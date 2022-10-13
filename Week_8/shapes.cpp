#include "shapes.h"

// Rectangle
// **************************************************
Rectangle::Rectangle(double width, double height) {
    // Basic Rectangle constructor which takes two floats
    this->width = width;
    this->height = height;

}

Rectangle::Rectangle(const Rectangle & r) {
    // Rectangle constructor that takes a reference to
    // another Rectangle
    width = r.width;
    height = r.height;

}

// The destructor needs not do anything
Rectangle::~Rectangle(){};

double Rectangle::area() {
    // Calculating the area of a rectangle is relatively simple
    return width * height;

}

double Rectangle::perimeter() {
    return 2* (width + height);

}

double Rectangle::height() {
    return height;

}

double Rectangle::width() {
    return width;

}

void Rectangle::rotate() {
    double temp_height = height;
    this->height = width;
    this->width = temp_height;
    
}



// Square 
// **************************************************


