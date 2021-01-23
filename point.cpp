#include "point.h"
#include <cmath>


using namespace std;

// the distance between two points
double dist(const point& p1, const point& p2) {
    const double dx = p1.x() - p2.x();
    const double dy = p1.y() - p2.y();
    return sqrt(dx * dx + dy * dy);
}

// string representation
string show_point(const point& p) {
    return "(" + to_string(p.x()) + ", " + to_string(p.y()) + ")";
}

void point::set_x(int& x) {
    _x = x;
}

void point::set_y(int& y) {
    _y = y;
}

/*
 * Calculates the Manhattan Distance between 2 points
 */
int manhattan_distance(point p1, point p2){
    int abs_x = abs(p1.x() - p2.x());
    int abs_y = abs(p1.y() - p2.y());
    return abs_x + abs_y;
}