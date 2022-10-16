#ifndef __shapes__
#define __shapes__

class Shape {

    public:
        // Really good reading for this week:
        // https://cplusplus.com/doc/tutorial/polymorphism/
        //
        // Today is about polymorphism, which is largely about
        // pointers to classes vs. objects of classes.
        //
        //
        // Understanding "virtual member functions":
        // A bit complicated... A virtual function like a non-
        // virtual function can be overwritten by a derived class.
        // However, non-virtual functions can't be accessed by a
        // base-class pointer to the derived class.
        // This means, that if we create an object of a derived
        // class, and then make a pointer of the base-type class
        // then we can access the derived classes overwritten
        // virtual function, but we can't do that if the overwritten
        // function wasn't virtual.
        // A virtual function then makes its class a:
        // 'polymoprhic base class'.
        //
        // Understanding "pure virtual functions":
        // A 'pure' virtual function in c++ is defined by
        // assigning it to zero.
        // This way the derived classes must override the
        // implementation.
        // This in turn also makes the base class an "abstract"
        // class - meaning that instances of that class can't
        // be instantiated. Classes that contain at LEAST ONE
        // pure virtual function is considered abstract.
        // Although instances of an abstract class can't be
        // instantiated a pointer to an abstract class can 
        // still be made. With a pointer to a an abstract class
        // this pointer can even us the 'this' keyword to acces
        // a derived classes overwrite of its pure virtual
        // function.
        //
        // Understanding "static" vs. "dynamic":
        // As I understand, something that is static stays in
        // memory even if it goes out of scope, whereas something
        // that is dynamic will be erased from memory runs it
        // exits the current scope.
        // This is especially weird for variables defined 
        // locally in functions.


        // The area() function shouldn't take any arguments
        // because all required parameters are already
        // defined locally. area() should return a double.
        virtual double area() = 0;

        // perimiter() shouldn't take any arguments either
        // and should return a double.
        virtual double perimeter() = 0;

        // A pattern is forming.
        virtual double height() = 0;


        virtual double width() = 0;

        // rotate() is a void function however, because
        // it only affects our member variables.
        virtual void rotate() = 0;

};

class Rectangle: public Shape{
    // Rectangle inherits shape
    public:
        // Standard constructor: builds a rectangle (a x b)
        Rectangle(double width, double height);

        // Copy constructor: builds a rectangle that is exactly as r
        Rectangle(const Rectangle & r);

        // Destructor
        ~Rectangle();

        // We apparently also need to define them in here
        //
        // I think it is such that Square can inherit them.
        virtual double area();
        virtual double perimeter();
        virtual double height();
        virtual double width();
        virtual void rotate();


    protected:
        double rect_width;
        double rect_height;

};

class Square: public Rectangle{
    // Square inherits Rectangle
    public:
        // Standard constructor: builds a square (length x length)
        Square(double length);

        // Copy constructor: builds a square that is exactly as s
        Square(const Square & s);

        // Destructor
        ~Square();

};

class Circle: public Shape{
    public:
        // Standard constructor: builds a circle with radius r
        Circle(double r);

        // Copy constructor: builds a circle that is exactly as c
        Circle(const Circle & c);

        // Destructor
        ~Circle();

        // I am very confused as to why these needs to be declared
        // in Circle...
        double area();
        double perimeter();
        double height();
        double width();
        void rotate();

    private:
        double radius;
        
};

#endif // __shapes__