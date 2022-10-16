#include "shapes.h"

// MY_PI
// ...don't you mean our pi?
// *National anthem of Soviet-Union plays*
#define OUR_PI 3.141592

// Rectangle
// ****************************************************************************
Rectangle::Rectangle(double rect_height, double rect_width) {
    // NOTE!
    // Remember to check the order of input parameters, they are
    // somewhat important...
    //
    // Basic Rectangle constructor which takes two floats
    this->rect_height = rect_height;
    this->rect_width = rect_width;

}

Rectangle::Rectangle(const Rectangle & r) {
    // Rectangle constructor that takes a reference to
    // another Rectangle
    rect_width = r.rect_width;
    rect_height = r.rect_height;

}

// The destructor needs not do anything
Rectangle::~Rectangle(){};

double Rectangle::area() {
    // Calculating the area of a rectangle is relatively simple
    return rect_width * rect_height;

}

double Rectangle::perimeter() {
    return 2* (rect_width + rect_height);

}

double Rectangle::height() {
    return rect_height;

}

double Rectangle::width() {
    return rect_width;

}

void Rectangle::rotate() {
    double temp_rect_height = rect_height;
    this->rect_height = rect_width;
    this->rect_width = temp_rect_height;
    
}



// Square 
// ****************************************************************************
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// TODO: Ask TA about this syntax!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Square::Square(double length) : Rectangle(length, length){};

Square::Square(const Square & s) : Rectangle(s){};

// The destructor needs not do anything
Square::~Square(){};



// Cirlce
// ****************************************************************************
Circle::Circle(double r) {
    radius = r;

}

Circle::Circle(const Circle & c) {
    radius = c.radius;

}

// The destructor needs not do anything
Circle::~Circle(){};

double Circle::area() {
    return OUR_PI * radius * radius;

}

double Circle::perimeter() {
    return 2 * OUR_PI * radius;

}

double Circle::height() {
    return 2 * radius;

}

double Circle::width() {
    // bruh...
    return 2 * radius;

}

void Circle::rotate() {
    // What happens when you rotate a circle..!?
    return;
}


