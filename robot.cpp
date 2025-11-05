#include <GL/glut.h>

GLfloat headRo = 0;


//draw cube
void drawCube(float width, float height, float depth) {
    glPushMatrix();
    glScalef(width, height, depth);
    glutSolidCube(1.0);
    glPopMatrix();
}

//draw limb
void drawLimb(float length, float thickness) {
    drawCube(thickness, length, thickness);
}

//draw robot
void drawRobot() {
    glPushMatrix();
    glColor3f(0.5, 0.5, 1.0);

    // draw torso
    drawCube(1.25, 1.5, 0.6);

    //draw head
    glPushMatrix();
        glTranslatef(0.0, 0.8, 0.0);
        glColor3f(1.0, 0.8, 0.6);
        glRotatef((GLfloat) headRo, 1.0, 0, 0);
        drawCube(0.30, 0.20, 0.50);
    glPopMatrix();

    //draw LEFT arm
    glPushMatrix();
        glTranslatef(-0.75, 0.5, 0.0);
        drawCube(0.5, 0.5, 0.5);
        glTranslatef(0, -0.8, 0);
        drawLimb(1.75, 0.25);
        glTranslatef(0, 0.8, 0);
    glPopMatrix();
    
    //draw RIGHT arm
    glPushMatrix();
        glTranslatef(0.75, 0.5, 0.0);
        drawCube(0.5, 0.5, 0.5);
        glTranslatef(0, -0.8, 0);
        drawLimb(1.75, 0.25);
        glTranslatef(0, 0.8, 0);
    glPopMatrix();
    
    //draw LEFT Leg
    glPushMatrix();
        glTranslatef(-0.3, -1.0, 0.0);
        drawLimb(1.3, 0.25);
        glTranslatef(0, -0.8, 0);
        glColor3f(0.5, 0.5, 1.0);
        drawCube(0.5, 0.2, 0.5);
        glColor3f(1.0, 0.8, 0.6);
    glPopMatrix();
    
    //draw RIGHT Leg
    glPushMatrix();
        glTranslatef(0.3, -1.0, 0.0);
        drawLimb(1.3, 0.25);
        glTranslatef(0, -0.8, 0);
        glColor3f(0.5, 0.5, 1.0);
        drawCube(0.5, 0.2, 0.5);
        glColor3f(1.0, 0.8, 0.6);
    glPopMatrix();

    glPopMatrix();
}


//draw ground
void drawWorld(){
    glPushMatrix();
        glTranslatef(0.0, -3.0, 0.0);
        glColor3f(5.0, 4.8, 0.6);
        drawCube(20.0, 0.10, 20.0);
    glPopMatrix();

}


//dispplay settings
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(3.0, 2.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    drawWorld();
    drawRobot();

    glutSwapBuffers();
}


//lighting settings
void init(void) {
    glEnable(GL_DEPTH_TEST);

    GLfloat light_pos[] = { 1.0, 1.0, 1.0, 0.0 };
    //GLfloat light_pos[] = { 0, };
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    
    glClearColor(0.2, 0.2, 0.2, 1.0);
}


void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Robo");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    

    return 0;
}
