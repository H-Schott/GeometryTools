#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <iostream>

//typedef unsigned int uint;

class Point;


class Vector {
public:
    double x;
    double y;
    double z;
public:
    Vector();
    Vector(double _x);
    Vector(double _x, double _y, double _z);
    Vector(const Point& p);

    double operator[](unsigned int id) const;
    double& operator[](unsigned int id);

    Vector operator+(const Vector& vec) const;
    Vector operator-() const;
    Vector operator-(const Vector& vec) const;
    Vector operator*(double a) const;
    Vector operator/(double a) const;
    Vector& operator+=(const Vector& v);
    Vector& operator-=(const Vector& v);
    Vector& operator/=(double a);

    double SquaredNorm() const;
    double Norm() const;
    Vector Normalized() const;

    static Vector X() { return Vector(1., 0., 0.); };
    static Vector Y() { return Vector(0., 1., 0.); };
    static Vector Z() { return Vector(0., 0., 1.); };
};



// Vector Inline Functions -----------------------------------------------------


inline Vector operator*(double a, const Vector& vec) { return vec * a; }


inline std::ostream& operator<<(std::ostream& os, const Vector vec) {
    os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return os;
}


inline Vector Normalize(const Vector& vec) {
    return vec / vec.Norm();
}


inline Vector Abs(const Vector& vec) {
    return Vector(std::abs(vec.x), std::abs(vec.y), std::abs(vec.z));
}


inline double Dot(const Vector& v1, const Vector& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline double AbsDot(const Vector& v1, const Vector& v2) {
    return std::abs(Dot(v1, v2));
}


inline Vector Cross(const Vector& v1, const Vector& v2) {
    return Vector((v1.y * v2.z) - (v1.z * v2.y),
                      (v1.z * v2.x) - (v1.x * v2.z),
                      (v1.x * v2.y) - (v1.y * v2.x));
}



double MinComponent(const Vector& vec);

double MaxComponent(const Vector& vec);

unsigned int MaxDimension(const Vector& vec);

Vector Min(const Vector& v1, const Vector& v2);

Vector Max(const Vector& v1, const Vector& v2);


Vector Permute(const Vector& vec, unsigned int xid, unsigned int yid, unsigned int zid);


inline void CoordinateSystem(const Vector& v1, Vector& v2, Vector& v3) {
    if (std::abs(v1.x) > std::abs(v1.y))
        v2 = Vector(-v1.z, 0, v1.x).Normalized();
    else v2 = Vector(0, v1.z, -v1.y).Normalized();
    v3 = Cross(v1, v2);
}


#endif