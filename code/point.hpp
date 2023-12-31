#ifndef __POINT_HPP__
#define __POINT_HPP__

#include <iostream>
#include <cmath>

//typedef unsigned int uint;

class Vector;

class Point {
public:
    double x;
    double y;
    double z;
public:
    Point();
    Point(double _x, double _y, double _z);
    Point(const Point& pt);

    double operator[](unsigned int id) const;
    double& operator[](unsigned int id);
    
    Point operator+(const Vector& vec) const;
    Point operator+(const Point& pt) const;
    Point operator-(const Vector& vec) const;
    Point operator-=(const Point& pt);
    Vector operator-(const Point& pt) const;
    Point operator*(double a) const;
    Point operator*=(double a);
    Point operator/(double a) const;
};


// Point Inline Functions -----------------------------------------------------------

inline std::ostream& operator<<(std::ostream& os, const Point pt) {
    os << "(" << pt.x << ", " << pt.y << ", " << pt.z << ")";
    return os;
}

inline double Distance(const Point& p1, const Point& p2);

inline double SquaredDistance(const Point& p1, const Point& p2);


inline Point operator*(double a, const Point& pt) { return pt * a; }

Point Lerp(double t, const Point& p0, const Point& p1);

Point Max(const Point& p1, const Point& p2);

Point Min(const Point& p1, const Point& p2);

Point Floor(const Point& pt);

Point Ceil(const Point& pt);

Point Abs(const Point& pt);

Point Permute(const Point& pt, unsigned int x, unsigned int y, unsigned int z);

double CoTan(const Point& p1, const Point& p2, const Point& p3);


#endif