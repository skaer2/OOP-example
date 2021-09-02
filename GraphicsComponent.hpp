#ifndef GRAPHICSCOMPONENT_HPP
#define GRAPHICSCOMPONENT_HPP

#include <vector>
#include <stdio.h>
#include <windows.h>
#include "ShapesComponent.hpp"

#include <GL/glew.h>
#include <GL/glut.h>

namespace GraphicsComponent{
        int run(int argc, char *argv[]);
        void setNewTargetVector(std::vector <Shape*> newTargetVector);
        void keyboardInput(int key, int x, int y);
        int initResources();
        void display();
        GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

};

#endif //GRAPHICSCOMPONENT_HPP
