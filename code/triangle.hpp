#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include "point.hpp"
#include "vector.hpp"

class Triangle {
public:
    Point a;
    Point b;
    Point c;

    Triangle();
    Triangle(Point a, Point b, Point c);

    Vector Edge(unsigned int edge_id) const;
    Vector Normal(bool unit=true) const;
    Point Barycentre() const;
    double Area() const;
};


#endif