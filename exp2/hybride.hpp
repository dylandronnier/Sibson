#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/natural_neighbor_coordinates_2.h>
#include <CGAL/interpolation_functions.h>
#include <CGAL/Interpolation_traits_2.h>
#include <limits>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K>             Delaunay_triangulation;
typedef CGAL::Interpolation_traits_2<K>               Traits;
typedef K::FT                                         Coord_type;
typedef K::Point_2                                    Point;

class Hybride {
  public:
    typedef CGAL::Data_access< std::map<Point, float> > Value_access;
  private:
    Delaunay_triangulation T;
    std::map<Point, float> data;
    float xmin, xmax, ymin, ymax;
  public:
    Hybride() {
    xmin, ymin = std::numeric_limits<float>::max();
    xmax, ymax = std::numeric_limits<float>::min();
    }
    ~Hybride() {}
    void add_point(const Point &p, float value);
    float interpolSibson(const Point &p);
    float interpolNearest(const Point &p) { return data[T.nearest_vertex(p)->point()]; }
    void clear() { data.clear();  T.clear(); }
};

    
