#include "ShapesComponent.hpp"
#include <math.h>

Point::Point(int x, int y){
    this->x = x;
    this->y = y;
}

Shape::Shape(){ //creates a unit sized shape
    size = 0.0f;
    coordinates.push_back(new Point(0.0f, 0.0f));
}


Shape::Shape(Point center, float size){
    coordinates.push_back(center);
    this->size = size;
}
void Shape::setNewSize(float newSize){
    size = newSize;
}

void Shape::setNewCenter(Point newCenter){
    coordinates.at(0) = newCenter;
}

std::vector <Point> Shape::getCoords(){
    return coordinates;    
}

Circle::Circle(){
    :Shape();
}

Circle::Circle(Point center, float size){
    :Shape(Point center, float size);
}

void Circle::definePoints(){
    float twicePi;
    int x, y;

    twicePi = 2.0 * 3.142
    x = 0, y = 0;

    for (int i = 0; i <= 20; i++){
        coordinates.push_back(
            (x + (size * cos(i * twicePi / 20))), (y + (size * sin(i * twicePi / 20)))
            );
    }
}

float Circle::computeCircumference(){
    return 2.0 * 3.142 * size;
}

Square::Square(){
    :Shape();
}

Square::Square(){
    :Shape(Point center, float size);
}

void Square::definePoints(){
    int x, y;

    x = center.x - size;
    y = center.y + size;
    coordinates.push_back(new Point(x, y));
    x = center.x + size;
    y = center.y + size;
    coordinates.push_back(new Point(x, y));
    x = center.x + size;
    y = center.y - size;
    coordinates.push_back(new Point(x, y));
    x = center.x - size;
    y = center.y - size;
    coordinates.push_back(new Point(x, y));
}

float Square::Square computeDiagonal(){
    return 2 * size * sqrt(2);
}

Triangle::Triangle(){
    :Shape();
}

Triangle::Triangle(Point center, float size){
    :Shape(Point center, float size);
}

void Triangle::definePoints(){
    int x, y;

    x = center.x - size;
    y = center.y - size;
    coordinates.push_back(new Point(x, y));
    x = center.x;
    y = center.y + size;
    coordinates.push_back(new Point(x, y));
    x = center.x + size;
    y = center.y - size;
    coordinates.push_back(new Point(x, y));
}
