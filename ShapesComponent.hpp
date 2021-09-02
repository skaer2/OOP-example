#ifndef SHAPESCOMPONENT_HPP
#define SHAPESCOMPONENT_HPP

#include <vector>
#include <math.h>

class Point{
    public: 
        Point(int x, int y);
        float x;
        float y;
};

class Shape{
    public:
        Shape(); //creates a unit sized shape
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

class Circle : public Shape{
    public:
        Circle();
        Circle(Point center, float size);
        virtual void definePoints();
        float computeCircumference();
};

class Square : public Shape{
    public:
        Square();
        Square(Point center, float size);
        virtual void definePoints();
        float computeDiagonal();

};

class Triangle : public Shape{
    public:
        Triangle();
        Triangle(Point center, float size);
        virtual void definePoints();

};

#endif //SHAPESCOMPONENT_HPP
