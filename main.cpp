#include "GraphicsComponent.hpp"
#include "ShapesComponent.hpp"
#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <GL/glut.h>

int main(int argc, char *argv[]){

    std::vector <Shape*> shapes;
    shapes.push_back(new Square(Point(0.0f,0.0f), 1.0f));
    shapes.push_back(new Circle());
    shapes.push_back(new Triangle());

    std::cout << "Switch shapes with arrowkeys";

    GraphicsComponent::setNewTargetVector(shapes);
    GraphicsComponent::run(argc, argv);

    for(auto element: shapes){
       delete element;
    }
    return 0;
}
