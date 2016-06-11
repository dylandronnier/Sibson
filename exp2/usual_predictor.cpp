#include "usual_predictor.hpp"
#include <assert.h> 

float distance(Point p, Point q, float s){
  return pow((p.x()-q.x())*(p.x()-q.x()) + (p.y()-q.y())*(p.y()-q.y()), s/2);
}

float IDW::operator() (const Point &p) const {
    float res, ponderation=0.;
    for (auto it = database.begin(); it != database.end(); it++){
	if (it->first == p)
	    return it->second;
	res += (it->second)*(1./distance(it->first, p, exposant));
	ponderation += 1./distance(it->first, p, exposant);
    }
    return res/ponderation;
}

