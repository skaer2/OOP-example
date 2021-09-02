#ifndef SHAPESCOMPONENT_HPP
#define SHAPESCOMPONENT_HPP

#include <vector>
#include <math.h>

class Point{ //a simple point class
    public: 
        Point(float x, float y);
        float x;
        float y;
};

class Shape{ //abstract class defining main properties of shapes
    public:
        Shape(); //creates a unit size shape
        Shape(Point center, float newSize);
        virtual void definePoints() = 0; //fills the coordinates vector with points specific to each kind of shape
        void setNewSize(float newSize);
        void setNewCenter(Point newCenter);
        std::vector <Point> getCoords();
        Point getCenter();

    protected:
        std::vector <Point> coordinates; //vector containing coordinates used to render the shape
        float size; //size from the center point
};

class Circle : public Shape{ //a simple circle shape
    public:
        Circle();
        Circle(Point center, float size); //size is the diameter of the circle
        virtual void definePoints();
        float computeCircumference();
};

class Square : public Shape{ //a simple square shape
    public:
        Square();
        Square(Point center, float size); //size is the side of the square
        virtual void definePoints();
        float computeDiagonal();

};

class Triangle : public Shape{ //a simple equilateral triangle shape
    public:
        Triangle();
        Triangle(Point center, float size); //size is the height of the triangle
        virtual void definePoints();

};

#endif //SHAPESCOMPONENT_HPP
