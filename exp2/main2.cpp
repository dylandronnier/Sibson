//#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
//#include <CGAL/Delaunay_triangulation_2.h>

#include "usual_predictor.hpp"
#include <fstream>
#include <stdlib.h>
#include <string>
//typedef K::Point_2 Point;

float camel(float x, float y) {
    //return cos(x+y);//y*y;
    return (4. - 2.1*x*x+pow(x,4)/3.)*x*x + x*y + (4.*y*y-4.)*y*y;
}    


float camel(const Point &p){
  float x = p.x();
  float y = p.y();
  return camel(x, y);
}

Point aleat(float xmin, float xmax, float ymin, float ymax) {
    return Point(xmin + (xmax - xmin) * rand()/RAND_MAX, 
		 ymin + (ymax - ymin) * rand()/RAND_MAX);
}

int main() {
    
    Delaunay_triangulation Tcamel;
    std::map<Point, float> camelValues;

    // Predictore to compare
    std::vector< Predictor<Point>* > Test;
    Hybride *Tpointeur = new Hybride;
    Test.push_back(new IDW(10));
    Test.push_back(new Sibson(Tpointeur));
    Test.push_back(new NN(Tpointeur));


    // Sommets de l'enveloppe convexe : rectangle
    for (auto it = Test.begin(); it != Test.end(); it++) {
	(*it)->insert(Point(-2., -1.), camel(-2., -1.));
	(*it)->insert(Point(-2., 1.), camel(-2., 1.));
	(*it)->insert(Point(2., -1.), camel(2., -1.));
	(*it)->insert(Point(2., 1.), camel(2., 1.));
    }

    Point p, p1, p2;
    float v1, v2;

    std::map<Point, float> datatest;
    for(int i = 0; i < 1000; i++) {
	p = aleat(-2., 2., -1., 1.);
	datatest.insert(std::pair<Point, float> (p, camel(p)));
    }
	
    std::ofstream file("res.txt");
    file << "DataSize IDW Sibson NN" << std::endl;
    for (int i = 0; i < 40; i++) {
	p1 = aleat(-2., 0.1, -1., -0.5);
	p2 = aleat(0.5, 1.9, 0.1, 0.8);

	v1 = camel(p1);
	v2 = camel(p2);
	file << 4+2*i << ' ';
	for (auto it = Test.begin(); it != Test.end(); it++) {
	    file << (*it)->MSE(datatest) << ' ';
	    (*it)->insert(p1, v1);
	    (*it)->insert(p2, v2);
	}	
	file << std::endl;	
    }
    
    delete Tpointeur;
    
    return 0;
    

}
    
