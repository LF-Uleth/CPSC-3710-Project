

#include <GL/glut.h>
#include <stdlib.h>


void drawCube(float width, float height, float depth){
    glPushMatrix();
        glScalef(width, height, depth);
        glutSolidCube(1.0f);
    glPopMatrix();
}


void drawRobot(){

//Draw Torso
glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    drawCube(1.25, 1.5, 0.6);
glPopMatrix();


//Draw Head
    

    
}

//display settings
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(3.0, 3.0, 3.0,   
              0.0, 0.0, 0.0,   
              0.0, 1.0, 0.0);

    drawRobot();

    glutSwapBuffers();
}

// set opengl settings
void initGL() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Robot");
    initGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
