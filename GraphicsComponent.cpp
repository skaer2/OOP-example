#include "GraphicsComponent.hpp"
#include <iostream>

GLuint vbo;
std::vector <Shape*> targetVector;
int currentShapeIndex;

int GraphicsComponent::run(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(480, 480);
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

    if (!initResources()) {
		glutDisplayFunc(display);
        glutSpecialFunc(keyboardInput);
		glutMainLoop();
	}

    return 0;
}

void GraphicsComponent::setNewTargetVector(std::vector <Shape*> newTarget){
    targetVector = newTarget; 
}

void GraphicsComponent::keyboardInput(int key, int x, int y){
    switch(key){
        case GLUT_KEY_RIGHT:
            currentShapeIndex++;
            break;

        case GLUT_KEY_LEFT:
            currentShapeIndex--;
            break;
    }

    if(currentShapeIndex < 0) currentShapeIndex = targetVector.size() - 1;
    if(currentShapeIndex > (int) targetVector.size() - 1) currentShapeIndex = 0;

    glutPostRedisplay();
}

int GraphicsComponent::initResources(){
    currentShapeIndex = 0;

    if (targetVector.size() == 0) {
        std::cout << "Error: no shapes in vector";
        return 1;
    }
    for(auto element: targetVector){
        element->definePoints();
    }

    return 0;
}

void GraphicsComponent::display(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3ub(0,0,0);
    glBegin(GL_TRIANGLE_FAN);

    for(int i = 1; i < (int) targetVector.at(currentShapeIndex)->getCoords().size(); i++){

        glVertex2f( targetVector.at(currentShapeIndex)->getCoords().at(i).x
                  , targetVector.at(currentShapeIndex)->getCoords().at(i).y
                  );
    }
    glEnd();

    glutSwapBuffers();

}
