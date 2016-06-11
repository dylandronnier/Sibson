//#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
//#include <CGAL/Delaunay_triangulation_2.h>

#include "usual_predictor.hpp"
#include <fstream>
#include <stdlib.h>
#include <string>
//typedef K::Point_2 Point;

float camel(float x, float y) {
    return y*y;
    //return (4. - 2.1*x*x+pow(x,4)/3.)*x*x + x*y + (4.*y*y-4.)*y*y;
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

void createOFF(std::string s, float xmin, float xmax,
	       float ymin, float ymax, int Nx, int Ny) { //float (*f)(float, float)) {
    std::ofstream file(s);
    file << "OFF" << std::endl;
    file << Nx*Ny << ' ' << 2*(Nx-1)*(Ny-1) << ' ' << 3*Nx*Ny - 2*(Nx+Ny-2) - 3 << std::endl;
    for (int i=0; i < Nx; i++)
	for(int j=0; j < Ny; j++) {
	    file << xmin + i*(xmax - xmin)/(Nx-1) << ' ';
	    file << ymin + j*(ymax - ymin)/(Ny-1) << ' ';
	    file << camel(xmin + i*(xmax - xmin)/(Nx-1), ymin + j*(ymax - ymin)/(Ny-1)) << std::endl;
	}
    for (int i=0; i < (Nx-1); i++)
	for(int j=0; j < (Ny-1); j++)
	    file << "3 "
		 << j + i*Ny << ' ' 
		 << j+1 + i*Ny << ' '
		 << j + (i+1)*Ny << std::endl;

    for (int i=1; i < Nx; i++)
	for(int j=1; j < Ny; j++)
	    file << "3 "
		 << j + i*Ny << ' ' 
		 << j-1 + i*Ny << ' '
		 << j + (i-1)*Ny << std::endl;	    
}

int main() {
    /*
    Delaunay_triangulation Tcamel;
    std::map<Point, float> camelValues;

    // Predictore to compare
    std::vector< Predictor<Point>* > Test;
    Hybride *Tpointeur = new Hybride;
    Test.push_back(new IDW(10));
    Test.push_back(new Sibson(Tpointeur));
    Test.push_back(new NN(Tpointeur));
    //Test.push_back(new GP(1.2));


    // Sommets de l'enveloppe convexe : rectangle
    for (auto it = Test.begin(); it != Test.end(); it++) {
	(*it)->insert(Point(-2., -1.), camel(-2., -1.));
	(*it)->insert(Point(-2., 1.), camel(-2., 1.));
	(*it)->insert(Point(2., -1.), camel(2., -1.));
	(*it)->insert(Point(2., 1.), camel(2., 1.));
    }

    Point p;
    float v;

    std::map<Point, float> datatest;
    for(int i = 0; i < 1000; i++) {
	p = aleat(-2., 2., -1., 1.);
	datatest.insert(std::pair<Point, float> (p, camel(p)));
    }
	
    std::ofstream file("res.txt");
    file << "DataSize IDW Sibson NN" << std::endl;
    for (int i = 0; i < 40; i++) {
	p = aleat(-2., 2., -1., 1.);
	file << 4+i << ' ';
	for (auto it = Test.begin(); it != Test.end(); it++) {
	    file << (*it)->MSE(datatest) << ' ';
	    (*it)->insert(p, v);
	}	
	file << std::endl;	
    }
    */
    createOFF("ccool.off", -2., 2., -1., 1., 4, 4);// camel);
    
    //delete Tpointeur;
    
    return 0;
    

}
    
