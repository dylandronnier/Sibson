#include "hybride.hpp"


void Hybride::add_point(const Point &p, float value) {
    data.insert(std::pair<Point, float>(p, value));
    T.insert(p);
    if (p.x() < xmin)
	xmin = p.x();
    if (p.x() > xmax)
	xmax = p.x();
    if (p.y() < ymin)
	ymin = p.y();
    if (p.y() > ymax)
	ymax = p.y();
}


float Hybride::interpolSibson(const Point &p) {
    assert(p.x() >= xmin and p.x() <= xmax and p.y() <= ymax and p.y() >= ymin);
    std::vector< std::pair< Point, float > > coords;
    float norm = CGAL::natural_neighbor_coordinates_2(T,
						      p,
						      std::back_inserter(coords)
						      ).second;
    return CGAL::linear_interpolation(coords.begin(), coords.end(), norm,
					  Value_access(data));
}    
    
