#include "vector2d.h"
#include <cmath>

v2d::v2d(double a, double b) {
    // Seems somewhat wack?
    x = a;
    y = b;

}

v2d::v2d(const v2d & v) {
    // Unsure as to why we aren't using the arrow (->) in this case.
    //
    // Hanse explained as: v is a reference, and hence we can treat
    // it as though it was the object wich it is referencing.
    x = v.x;
    y = v.y;
}

v2d::~v2d() {
    // This is probably incorrect..
    //
    // Yes! this is highly unnecessary
    x = 0;
    y = 0;

}

v2d & v2d::operator=(const v2d &v) {
    // Understanding the "this pointer":
    // 'this' is a pointer that points to the object
    // which utilizes this function.
    // We could e.g. write this->x, but c++ already 
    // assumes when we write a member variable <member> that
    // we are writing this-><member>.
    //
    // Understanding references:
    // references, as this function returns are very much like a
    // constant pointer. However instead of an adress, like a pointer,
    // they take an object, or rather an r-value. It is an alias, so
    // any operation which affects this alias, will also affect that
    // which it references.
    // (You can tell it's a reference by the '&' after the type)
    //
    // Understanding dereferencing:
    // 'this' is a pointer, but a reference takes an r-value, not
    // an l-value, which a pointer is, so we need to dereference the
    // 'this' pointer, otherwise can't return it as a reference.
    // (dereferencing is done with the use of the '*' operator - it
    // returns the value at the adress rather than the adress itself).
    x = v.x;
    y = v.y;
    return *this;

}

v2d & v2d::operator+(const v2d &v) {
    x += v.x;
    y += v.y;
    return *this;

}

double v2d::operator*(const v2d &v) {
    return x * v.x + y * v.y;

}

v2d & v2d::operator*(double k) {
    x *= k;
    y *= k;
    return *this;

}

double v2d::length() {
    // Alternate way to solve this is finding the dot-product of
    // the object which uses this function. We just learned
    // that there is a pointer called 'this' whcih we can use.
    // We can then find the dot product of the dereferenced 'this'
    // pointer, by calling our previously defined * operator overload.
    // as such: 
    //      return sqrt( (*this) * (*this) )
    return sqrt(x*x + y*y);

}

