#ifndef SHAPESCOMPONENT_HPP
#define SHAPESCOMPONENT_HPP

#include <vector>

class Point{
    public: 
        float x;
        float y;
};

class Shape{
    public:
        Shape(); //creates a unit sized shape
        Shape(Point center, float newSize);
        virtual void definePoints() = 0;
        void setNewSize(float newSize);
        void setNewCenter(float newCenter);
        std::vector <Point> getCoords();

    private:
        std::vector <Point> coordinates;
        float size;
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
