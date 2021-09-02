#ifndef GRAPHICSCOMPONENT_HPP
#define GRAPHICSCOMPONENT_HPP

#include <vector>
#include "shapesComponent.hpp"

class GraphicsComponent{
    public:
        void run(int argc, char *argv[]);
        void setNewTargetVector(std::vector <Shape*> newTargetVector);

    private:
        int initResources();
        void keyboardInput();
        void display();
        std::vector <Shape*> targetVector;
        int currentShapeIndex;
        GLuint vbo;

};

#endif //GRAPHICSCOMPONENT_HPP
