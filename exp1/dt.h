#ifndef TRIANGULATION_H
#define TRIANGULATION_H

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/basic.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/natural_neighbor_coordinates_2.h>
#include <CGAL/interpolation_functions.h>
#include <CGAL/Interpolation_traits_2.h>
#include <iostream>
#include <cmath>
using namespace std;

// a base vertex with attributes
template <class Vbb>
class My_vertex_base : public Vbb
{
public:
	typedef Vbb Vertex_base;
	typedef typename Vertex_base::Point Point;
private:

	// additional member data
public:
	My_vertex_base()
		: Vertex_base()
	{
	}
	My_vertex_base(const Point & p, void* f)
		: Vertex_base(p,f)
	{
	}
	My_vertex_base(const Point & p)
		: Vertex_base(p)
	{
	}
};


template <class Kernel, class TDS>
class DT : public CGAL::Delaunay_triangulation_2<Kernel,TDS>
{
public:

	// typedefs for basic primitives
	typedef typename Kernel::FT FT;
	typedef typename Kernel::Point_2    Point;
	typedef typename Kernel::Vector_2 	Vector;
	typedef typename Kernel::Ray_2      Ray;
	typedef typename Kernel::Line_2		Line;
	typedef typename Kernel::Segment_2  Segment;
	typedef typename Kernel::Triangle_2 Triangle;


	typedef typename CGAL::Delaunay_triangulation_2<Kernel,TDS> Dt2;

	// handles
	typedef typename Dt2::Face_handle         Face_handle;
	typedef typename Dt2::Vertex_handle       Vertex_handle;

	// iterators
	typedef typename Dt2::Face_iterator       Face_iterator;
	typedef typename Dt2::Edge_iterator       Edge_iterator;
	typedef typename Dt2::Vertex_iterator     Vertex_iterator;

	// circulators
	typedef typename Dt2::Edge_circulator     Edge_circulator;
	typedef typename Dt2::Vertex_circulator	  Vertex_circulator;
	typedef typename Dt2::Face_circulator	  Face_circulator;
	typedef typename Dt2::Line_face_circulator Line_face_circulator;

private:

public:
	DT() 
	{
	}

	virtual ~DT() 
	{
		Dt2::clear();
	}

public:

	// random (uniform)
	void generators_random(unsigned int nb_generators)
	{
		Dt2::clear();
		for(unsigned int i = 0; i < nb_generators; i++)
			insert(Point(r(), r()));
	}

	// random number between zero and max
	FT r(FT max = 1.0) { return max * (FT)rand() / (FT)RAND_MAX; }

    void insert_circle(const int nb)
    {
	const Point center(0.5, 0.5);
	const FT radius = 0.5;
	const FT pi = 3.1415926535897932384626433832795;
	for(int i = 0; i < nb; i++)
	    {
		FT alpha = (FT)i / (FT)nb * 2.0 * pi;
		const FT x = center.x() + radius * sin(alpha);
		const FT y = center.y() + radius * cos(alpha);
		Dt2::insert(Point(x, y));
		}
    }
    
    void insert_points_de_base(const FT xmin, const FT xmax,
			       const FT ymin, const FT ymax)
    {	
	Dt2::insert(Point(xmin,ymin));
	Dt2::insert(Point(xmax,ymin));
	Dt2::insert(Point(xmin,ymax));
	Dt2::insert(Point(xmax,ymax));
	Dt2::insert(Point(xmin + (xmax - xmin)/2., ymin + (ymax - ymin)/3.));
    }

    // OPENGL DRAWINGS FUNCTIONS
    
    // draw generators
    void gl_draw_generators(const float point_size,
		const unsigned char red,
		const unsigned char green,
		const unsigned char blue)
	{
		::glColor3ub(red, green, blue);
		::glPointSize(point_size);
		::glBegin(GL_POINTS);
		typename Dt2::Point_iterator it;
		for(it = Dt2::points_begin(); 
			it != Dt2::points_end(); 
			it++)
		{
			const Point& p = *it;
			::glVertex2f(p.x(), p.y());
		}
		::glEnd();
	}

	// draw delaunay edges
	void gl_draw_delaunay_edges(const float line_width,
		const unsigned char red,
		const unsigned char green,
		const unsigned char blue)
	{
		::glColor3ub(red, green, blue);
		::glLineWidth(line_width);

		::glBegin(GL_LINES);
		Edge_iterator hEdge;
		for(hEdge  = Dt2::edges_begin(); 
			hEdge != Dt2::edges_end(); 
			hEdge++) 
		{
		    const Point& p1 = (*hEdge).first->vertex(Dt2::ccw((*hEdge).second))->point();
		    const Point& p2 = (*hEdge).first->vertex(Dt2::cw((*hEdge).second))->point();
		    ::glVertex2d(p1.x(), p1.y());
		    ::glVertex2d(p2.x(), p2.y());
		}
		::glEnd();
	}
    
    void gl_draw_face(Face_handle f,
		      const unsigned char red,
		      const unsigned char green,
		      const unsigned char blue)
    {
	::glColor3ub(red, green, blue);
	
	::glBegin(GL_TRIANGLES);
	for(int i=0; i<3; i++)
	    {
		const Point& q = f->vertex(i)->point();
		::glVertex2d(q.x(), q.y());
	    }
	::glEnd();
    }
    
    void gl_draw_voronoi_edges(const float line_width,
			       const unsigned char red,
			       const unsigned char green,
			       const unsigned char blue)
    {
	::glColor3f(red, green, blue);
	::glLineWidth(line_width);
	
	::glBegin(GL_LINES);
	Edge_iterator hEdge;
	for(hEdge = Dt2::edges_begin(); hEdge != Dt2::edges_end(); hEdge++)
	    {
		Ray ray;
		Line line;
		Segment segment;
		Point source, target;
		
		CGAL::Object object = Dt2::dual(hEdge);
		if(CGAL::assign(segment,object))
		    {
			source = segment.source();
			target = segment.target();
		    }
		else if(CGAL::assign(ray,object))
		    {
			source = ray.source();
			target = ray.point(1000.0);
		    }
		else if (CGAL::assign(line,object))
		    {
			source = line.point( 1000.0);
			target = line.point(-1000.0);
		    }
		::glVertex2f(source.x(),source.y());
		::glVertex2f(target.x(),target.y());
	    }
	::glEnd();
    }
    
    void draw_convex_hull(const float line_width,
			  const unsigned char red,
			  const unsigned char green,
			  const unsigned char blue)
    {
	::glColor3f(red, green, blue);
	::glLineWidth(line_width);
	
	if (Dt2::dimension() < 2) return;
		
	Vertex_circulator vc = Dt2::incident_vertices(Dt2::infinite_vertex());
	Vertex_circulator end(vc);
	
	::glBegin(GL_LINE_LOOP);
	CGAL_For_all(vc, end)
	    {
		const Point& p = vc->point();
		::glVertex2d(p.x(), p.y());
	    }		
	::glEnd();		
    }
    
    void draw_face_under_mouse(const Point& p,
			       const unsigned char red,
			       const unsigned char green,
			       const unsigned char blue)
    {
	if (Dt2::dimension() < 2) return;
	
	Face_handle f = Dt2::locate(p);
	gl_draw_face(f, red, green, blue);
    }
    
	
    void draw_faces_along_line(
			       const unsigned char red,
			       const unsigned char green,
			       const unsigned char blue)
    {
	if (Dt2::dimension() < 2) return;
	
	Point p(0.0, 0.0);
	Point q(1.0, 1.0);
	Line_face_circulator circ = Dt2::line_walk(p, q);
	Line_face_circulator end = circ;
	CGAL_For_all(circ, end)
	    gl_draw_face(circ, red, green, blue);
    }
    
    void draw_nearest_vertex(const Point& P,
			     const float point_size,
			     const unsigned char red,
			     const unsigned char green,
			     const unsigned char blue)
    {
	if (Dt2::dimension() < 2) return;
	
	::glColor3ub(red, green, blue);
	::glPointSize(point_size);
	
	Vertex_handle vc = Dt2::nearest_vertex(P);
	const Point& p = vc->point();
	::glBegin(GL_POINTS);
	::glVertex2d(p.x(), p.y());
	::glEnd();	
    }
    
    void draw_graph(float min_x, float max_x,
		    float min_y, float max_y,
		    int nb_x, int nb_y, float point_size)
    {
	typedef CGAL::Exact_predicates_inexact_constructions_kernel K;

	typedef CGAL::Data_access< std::map<Point, FT, K::Less_xy_2 > > Value_access;

	std::map<Point, FT, K::Less_xy_2> function_values;	
	
	typename Dt2::Point_iterator it;
	for(it = Dt2::points_begin(); 
	    it != Dt2::points_end(); 
	    it++)
	    {
		const Point& p = *it;
		function_values.insert(std::make_pair(p, cos(p.x() + p.y())));
	    }
	std::vector< std::pair< Point, FT > > coords;
	::glPointSize(point_size);

	::glBegin(GL_POINTS);

	K::FT norm2, res2;
	for (int i=0; i < nb_x; i++)
	    for (int j=0; j < nb_y; j++) {
		coords.clear();
		Point p2(min_x + i*(max_x - min_x)/nb_x, min_y + j*(max_y - min_y)/nb_y);
		norm2 = CGAL::natural_neighbor_coordinates_2(*this, p2, std::back_inserter(coords)).second;
		res2 =  CGAL::linear_interpolation(coords.begin(), coords.end(), norm2, Value_access(function_values));

		::glColor3f(Jetred(res2), Jetgreen(res2), Jetblue(res2));

		std::cout << Jetred(res2) << std::endl;
		::glVertex2f(p2.x(), p2.y());


	    }
	::glEnd();

    }
    
    bool incident_to_infinite_cell(Vertex_handle v)
    {
	Face_circulator fc = Dt2::incident_faces(v);
	Face_circulator end = fc;
	
	CGAL_For_all(fc, end)
	    if(Dt2::is_infinite(fc))
		return true;
	
	return false;
    }
    
	Point compute_centroid(Vertex_handle v)
    {
	const Point& pivot = v->point();
	
	// return pivot if vertex incident to infinite cell(s)
	if(incident_to_infinite_cell(v))
	    return pivot;
	
	// we star-triangulate the convex polygon 
	// formed by the Voronoi cell, with center
	// as pivot vertex.
	Vector vec = CGAL::NULL_VECTOR;
	FT sum_areas = 0.0; 
	
	Face_circulator fc = Dt2::incident_faces(v);
	Face_circulator end = fc;
	CGAL_For_all(fc, end)
	    {
		// second triangle vertex
		const Point p1 = Dt2::dual(fc);

		// move to next facet (to select third triangle vertex)
		fc++;
		const Point p2 = Dt2::dual(fc);
		fc--; // restore circulator
		
			// construct triangle and compute area & centroid
		Triangle tri(pivot, p1, p2);
		const FT area = tri.area();
		const Point gi = CGAL::centroid(tri); // triangle centroid
		
		vec = vec + area * (gi - CGAL::ORIGIN);
		sum_areas += area;
		}
	
		return CGAL::ORIGIN + vec / sum_areas;
    }
	
    void draw_centroids(const float point_size,
			const unsigned char red,
			const unsigned char green,
			const unsigned char blue)
	{
	    ::glColor3ub(red, green, blue);
	    ::glPointSize(point_size);

	    typename Dt2::Finite_vertices_iterator v;
	    for(v  = Dt2::finite_vertices_begin();
		v != Dt2::finite_vertices_end();
		v++)
		{
		    const Point c = compute_centroid(v);
		    if(c != v->point()) // draw centroid only when different from vertex
			{
			    ::glBegin(GL_POINTS);
			    ::glVertex2d(c.x(), c.y());
			    ::glEnd();
			}
		}
		
	}
    
    void lloyd()
    {
	// compute centroids
        std::list<Point> centroids;
        typename Dt2::Finite_vertices_iterator v;
        for(v  = Dt2::finite_vertices_begin();
            v != Dt2::finite_vertices_end();
            v++)
	    {
		const Point c = compute_centroid(v);
		centroids.push_back(c);
	    }
	
	// clear triangulation
        Dt2::clear();
	
	// insert all centroids
        Dt2::insert(centroids.begin(), centroids.end());
    }
    double base( double val ) {
	if ( val <= -0.75 ) return 0;
	else if ( val <= -0.25 ) return interpolate( val, 0.0, -0.75, 1.0, -0.25 );
	else if ( val <= 0.25 ) return 1.0;
	else if ( val <= 0.75 ) return interpolate( val, 1.0, 0.25, 0.0, 0.75 );
	else return 0.0;
}
    
    double Jetred( double gray ) {
	return base( gray - 0.5 );
    }
    double Jetgreen( double gray ) {
	return base( gray );
    }
    double Jetblue( double gray ) {
	return base( gray + 0.5 );
    }

    double interpolate( double val, double y0, double x0, double y1, double x1 ) {
	return (val-x0)*(y1-y0)/(x1-x0) + y0;
    }
    
};

#endif // TRIANGULATION_H
