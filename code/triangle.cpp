#include "triangle.hpp"

Triangle::Triangle(Point _a, Point _b, Point _c) : a(_a), b(_b), c(_c) {}


Vector Triangle::Edge(unsigned int edge_id) const {
    switch (edge_id) {
    case 0:
        return b - a;
    case 1:
        return c - b;
    case 2:
        return a - c;
    default:
        return Vector();
    }
}

Vector Triangle::Normal(bool unit) const {
    Vector normal = Cross(Vector(b - a), Vector(c - a));
    if (unit) return Normalize(normal);
    return normal;
}

Point Triangle::Barycentre() const {
    return (a + b + c) / 3;
}

double Triangle::Area() const {
    return 0.5 * Cross(Vector(b - a), Vector(c - a)).Norm();
}

void Triangle::Bounds(Point& p_min, Point& p_max) const {
    p_min = a;
    p_max = a;

    p_min = Min(p_min, b);
    p_min = Min(p_min, c);

    p_max = Max(p_max, b);
    p_max = Max(p_max, c);
}


// EOF