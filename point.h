#ifndef POINT_H
#define POINT_H

#include <string>
#include <cstdlib>

// a point in two-dimensional space
class point {
    double _x, _y;
public:
    point(double x, double y) : _x(x), _y(y) {}
    point() = default;

    double x() const { return _x; }
    double y() const { return _y; }

    void set_y(int& y);
    void set_x(int& x);
};

// the distance between two points
double dist(const point& p1, const point& p2);

// string representation
std::string show_point(const point& p);

// calculates the Manhattan distance
int manhattan_distance(point p1, point p2);

#endif
