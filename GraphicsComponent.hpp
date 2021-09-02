#ifndef GRAPHICSCOMPONENT_HPP
#define GRAPHICSCOMPONENT_HPP

#include <vector>
#include <stdio.h>
#include <windows.h>
#include "ShapesComponent.hpp"

#include <GL/glew.h>
#include <GL/glut.h>

namespace GraphicsComponent{
        int run(int argc, char *argv[]); //starts OpenGL pipeline
        void setNewTargetVector(std::vector <Shape*> newTargetVector); //sets the vector with shapes to render
                                                                       //set the vector before calling run

        //these functions are used in run by OpenGL
        void keyboardInput(int key, int x, int y); 
        int initResources();
        void display();

};

#endif //GRAPHICSCOMPONENT_HPP
