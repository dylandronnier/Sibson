/**
 * @file offconst.hpp
 * @author Dylan Dronnier <dylan.dronnier@laposte.net>
 * 
 * @section DESCRIPTION
 *
 *  
 *
 */

#ifndef OFFCONST_HPP
#define OFFCONST_HPP

#include <CGAL/Delaunay_triangulation_2.h>
#include <string>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K> Delaunay_triangulation;


class OFFConstructor {
  private:
    float xmin, xmax, ymin, ymax;
    unsigned int N;
    Delaunay_triangulation dt;
    string filename;
    
  public:
    OFFConstructor(float xm, float xM, float ym, float yM, unsigned int n);
    ~OFFConstructor();
    float Test(const Predictor& a) const;
}

#endif // OFFCONST_HPP
