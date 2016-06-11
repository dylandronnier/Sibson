#ifndef USUALPRED_HPP
#define USUALPRED_HPP

#include "hybride.hpp"
#include "predictor.hpp"

class IDW : public Predictor<Point> {
  private:
    std::map<Point, float> database;
    float exposant;
  public:
    IDW(float s) : exposant(s) { }
    IDW(const std::map <Point, float> &d, float s): database(d), exposant(s) {}
    ~IDW() {}
    float operator() (const Point &p) const;
    void insert(const Point &p, float val) { 
	database.insert(std::pair<Point, float>(p, val));
    }
};

class Sibson : public Predictor<Point> {
  private:
    Hybride *Tp; 
  public:
    Sibson(Hybride *tp): Tp(tp) {}
    ~Sibson() {}
    float operator() (const Point &p) const { return Tp->interpolSibson(p); }
    void insert(const Point &p, float val) { Tp->add_point(p, val); }
 };


class NN : public Predictor<Point> {
  private:
    Hybride *Tp;    
  public:
    NN(Hybride *tp): Tp(tp) {};
    ~NN() {}
    float operator() (const Point &p) const { return Tp->interpolNearest(p); }
    void insert(const Point &p, float val) { Tp->add_point(p, val); }
};

#endif // USUALPRED_HPP
