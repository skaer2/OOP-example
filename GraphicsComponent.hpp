#ifndef GRAPHICSCOMPONENT_HPP
#define GRAPHICSCOMPONENT_HPP

#include <vector>
#include <stdio.h>
#include <windows.h>
#include "shapesComponent.hpp"

#include <GL/glew.h>
#include <GL/glut.h>

namespace GraphicsComponent{
        int run(int argc, char *argv[]);
        void setNewTargetVector(std::vector <Shape*> newTargetVector);
        void keyboardInput(int key, int x, int y);
        int initResources();
        void display();
        std::vector <Shape*> targetVector;
        int currentShapeIndex;
        GLuint vbo;

};

#endif //GRAPHICSCOMPONENT_HPP
