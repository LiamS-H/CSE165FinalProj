#include "../freeglut/include/GL/freeglut.h"
#include <cstdio>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        printf("OpenGL Error: %d\n", error);
    }
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("CSE165Proj");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}