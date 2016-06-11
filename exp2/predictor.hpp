#ifndef PREDICTOR_HPP
#define PREDICTOR_HPP
#include <cmath>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/natural_neighbor_coordinates_2.h>
#include <CGAL/interpolation_functions.h>
#include <CGAL/Interpolation_traits_2.h>
#include <limits>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K> Delaunay_triangulation;
typedef K::Point_2 Point;


template <typename T>
class Predictor {
  public:
    Predictor() {};
    virtual ~Predictor() {};
    virtual float operator()(const T &p) const =0;
    virtual void insert(const T &p, float value) =0;
    float MSE(const std::map<T, float> &datatest) const;
};


template <typename T>
float Predictor<T>::MSE(const std::map<T, float> &datatest) const {
    int N=0;
    float res=0.;
    for (auto it = datatest.begin(); it != datatest.end(); it++) {
	res += pow((operator()(it->first)) - it->second, 2);
	N++;
    }
    return res/N;
}

#endif // PREDICTOR_HPP
