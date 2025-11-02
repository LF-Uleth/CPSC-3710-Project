

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
