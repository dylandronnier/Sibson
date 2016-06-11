#ifndef TRIANGULATION_HPP
#define TRIANGULATION_HPP

#include <CGAL/basic.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/natural_neighbor_coordinates_2.h>
#include <CGAL/interpolation_functions.h>
#include <CGAL/Interpolation_traits_2.h>
#include <unordered_map>
#include <iostream>
#include <assert.h> 
#include <limits>

template<class Kernel>
struct PointHasher {
    std::size_t operator()(const CGAL::Point_2<Kernel>& p) const {
	return std::hash<float>()(p.x()) ^ std::hash<float>()(p.y());
    }
};

// a base vertex with attributes
template <class Vbb>
class My_vertex_base : public Vbb {
  public:
    typedef Vbb Vertex_base;
    typedef typename Vertex_base::Point Point;
    
  private:
    // additional member data
    bool m_input;
    
  public:
    My_vertex_base() : Vertex_base() { }
    My_vertex_base(const Point & p, void* f) : Vertex_base(p,f) { }
    My_vertex_base(const Point & p) : Vertex_base(p) { }
    bool& input() { return m_input; }
};


template <class Kernel, class TDS>
class DT : private CGAL::Delaunay_triangulation_2<Kernel,TDS> {
  public:
    
    // typedefs for basic primitives
    typedef typename Kernel::FT FT;
    typedef typename Kernel::Ray_2      Ray;
    typedef typename Kernel::Line_2     Line;
    typedef typename Kernel::Point_2    Point;
    typedef typename Kernel::Vector_2   Vector;
    typedef typename Kernel::Segment_2  Segment;
    typedef typename Kernel::Triangle_2 Triangle;
    
    typedef typename CGAL::Delaunay_triangulation_2<Kernel,TDS> Dt2;
    
    // handles
    typedef typename Dt2::Face_handle         Face_handle;
    typedef typename Dt2::Vertex_handle       Vertex_handle;
    
    // iterators
    typedef typename Dt2::Face_iterator       Face_iterator;
    typedef typename Dt2::Edge_iterator       Edge_iterator;
    typedef typename Dt2::Finite_vertices_iterator Vertex_iterator; // 
    
    // circulators
    typedef typename Dt2::Edge_circulator      Edge_circulator;
    typedef typename Dt2::Vertex_circulator    Vertex_circulator;
    typedef typename Dt2::Face_circulator      Face_circulator;
    typedef typename Dt2::Line_face_circulator Line_face_circulator;
    typedef std::unordered_map< Point, Vector, PointHasher<Kernel> > Move;
    typedef std::unordered_map< Point, int, PointHasher<Kernel> > Count;
    typedef CGAL::Data_access< std::map<Point, float> > Value_access;

    
  private:
    
    std::map<Point,float> data;
    float xmin, xmax, ymin, ymax;
    
  public:
    
    DT() { 
    xmin, ymin = std::numeric_limits<float>::max();
    xmax, ymax = std::numeric_limits<float>::min();
    }
    
    virtual ~DT() { Dt2::clear(); }

    Point cendroid_T(const Triangle& t) {
	return CGAL::ORIGIN + ((t[0] - CGAL::ORIGIN) + (t[1] - CGAL::ORIGIN) +
			       (t[2] - CGAL::ORIGIN))/3;
    }

    void add_value(Point p, float val) {
	data.insert(std::pair<Point, float>(p, value));
	insert(p);
	if (p.x() < xmin)
	    xmin = p.x();
	if (p.x() > xmax)
	    xmax = p.x();
	if (p.y() < ymin)
	    ymin = p.y();
	if (p.y() > ymax)
	    ymax = p.y();
	
    }
    
    float interpolSibson(const Point &p) {
	assert(p.x() > xmin and p.x() < xmax and p.y() < ymax and p.y() > ymin);
	std::vector< std::pair< Point, float > > coords;
	float norm = CGAL::natural_neighbor_coordinates_2(*this,
							  p,
							  std::back_inserter(coords)
							  ).second;
	return CGAL::linear_interpolation(coords.begin(), coords.end(), norm,
					  Value_access(data));
    }
    
    Point centroid_voronoi_cell(Vertex_handle v) {
	Face_circulator f = Dt2::incident_faces(v);
	Face_circulator end = f;
	Vector vec = CGAL::NULL_VECTOR;
	float sum_areas = 0;
	Triangle t;
	do {
	    if (Dt2::is_infinite(f)) return v->point();
	    t = Triangle(Dt2::dual(f), Dt2::dual(f++), v->point());
	    vec = vec + t.area() * (cendroid_T(t) - CGAL::ORIGIN);
	    sum_areas += t.area();
	} while(f != end);
	return CGAL::ORIGIN + vec/sum_areas;
}
    
    
    void lloyd_MonteCarlo() {
	int i = 10000;
	Move mp;
	Count mi;
	while (i > 0) {
	    Point p(xmin + (xmax - xmin) * rand()/RAND_MAX, ymin + (ymax - ymin) * rand()/RAND_MAX);
	    if (domain(p)) {
		Point pc = Dt2::nearest_vertex(p)->point();
		if (mi[pc] > 0)
		    mp[pc] = mp[pc] + (p - pc);
		else 
		    mp[pc] = (p - pc);
		mi[pc]++;
		i--;
	    }
	}
	for (Vertex_iterator v = Dt2::finite_vertices_begin();
	     v != Dt2::finite_vertices_end(); v++)
	    if (mi[v->point()] > 0)
		Dt2::move(v, v->point() + mp[v->point()]/mi[v->point()]);		
    }
}
    
    
#endif // TRIANGULATION_HPP
