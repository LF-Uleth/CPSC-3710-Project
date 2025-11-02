

#include <GL/glut.h>
#include <stdlib.h>


void drawCube(float width, float height, float depth){
    glPushMatrix();
        glScalef(width, height, depth);
        glutSolidCube(1.0f);
    glPopMatrix();
}
