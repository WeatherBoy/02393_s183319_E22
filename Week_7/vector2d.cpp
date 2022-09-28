#include "vector2d.h"
#include <cmath>

v2d::v2d(double a, double b) {
    // Seems somewhat wack?
    x = a;
    y = b;
}

v2d::v2d(const v2d & v) {
    // Unsure as to why we aren't using the arrow (->) in this case.
    x = v.x;
    y = v.y;
}

v2d::~v2d() {
    // This is probably incorrect..
    x = 0;
    y = 0;
}

v2d & v2d::operator=(const v2d &v) {
    x = v.x;
    y = v.y;
}

v2d & v2d::operator+(const v2d &v) {
    x += v.x;
    y += v.y;
}

double v2d::operator*(const v2d &v) {
    return x * v.x + y * v.y;
}

v2d & v2d::operator*(double k) {
    x *= k;
    y *= k;
}

double v2d::length() {
    return sqrt(x*x + y*y);
}

