#include "GraphicsComponent.hpp"
#include "ShapesComponent.hpp"
#include <iostream>
#include <vector>

int main(int argc, char *argv[]){

    GraphicsComponent g = new GraphicsComponent();
    g.setNewTarget(new Circle());

    return 0;
}
