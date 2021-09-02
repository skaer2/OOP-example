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
        glutSpecialFunc(keyboardInput);
		glutMainLoop();
	}
}

void GraphicsComponent::setNewTargetVector(std::vector <Shape*> newTarget){
    targetVector = newTarget; 
}

void GraphicsComponent::keyboardInput(int key, int x, int y){
    switch(key){
        GLUT_KEY_RIGHT:
            currentShapeIndex++;
            break;

        GLUT_KEY_LEFT:
            currentShapeIndex--;
            break;
    }

    if(currentShapeIndex < 0) currentShapeIndex = targetVector.size();
    if(currentShapeIndex > targetVector.size()) currentShapeIndex = 0;

}

int GraphicsComponent::initResources(){
    currentShapeIndex = 0;

    for(auto element: targetVector){
        element->definePoints();
    }

    glGenBuffers(1, &vbo);

   
    return 0;
}

void GraphicsComponent::display(){
    glClearColor(1,1,1,1);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER
                , targetVector.at(currentShapeIndex).getCoords.size() * sizeof(Shape)
                , &targetVector.at(currentShapeIndex).getCoords.front()
                , GL_DYNAMIC_DRAW);


    glDrawArrays(GL_TRIANGLE_FAN, 0, targetVector.at(currentShapeIndex).getCoords.size());

    glutSwapBuffers();


}
