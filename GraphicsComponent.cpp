#include "GraphicsComponent.hpp"

#include <GL/glew.h>
#include <GL/glut.h>

GraphicsComponent::run(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(640, 480);
	glutCreateWindow("OOP example");

    GLenum glew_status = glewInit();

	if (GLEW_OK != glew_status) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_status));
		return 1;
	}

	if (!GLEW_VERSION_2_0) {
		fprintf(stderr, "No support for OpenGL 2.0 found\n");
		return 1;
	}

    if (!init_resources()) {
		glutDisplayFunc(display);
		glutMainLoop();
	}
}

void setNewTargetVector(std::vector <Shape*> newTarget){

}

int initResources(){
    currentShapeIndex = 0;

    for(auto element: targetVector){
        element->definePoints();
    }

    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER
                , targetVector.at(0).getCoords.size() * sizeof(Shape)
                , &targetVector.at(0).getCoords.front()
                , GL_DYNAMIC_DRAW);

    return 0;
}

void display(){
    glClearColor(1,1,1,1);
}
