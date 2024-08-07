#include <GL/glut.h>
#include <stdio.h>

void myinit() {
    glClearColor(0.0, 0.0, 1.0, 1.0); // Background
    gluOrtho2D(-500, 500, -500, 500);
}

void draw_triangle() {
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(100, 100);
    glVertex2f(200, 100);
    glVertex2f(150, 150);
    glEnd();
}

void translate() {
    glPushMatrix();
    glTranslated(100, 0, 0);
    draw_triangle();
    glPopMatrix();
}

void rotate_triangle() {
    glPushMatrix();
    glRotated(45, 0, 0, 1);
    draw_triangle();
    glPopMatrix();
}

void pivot_point_rotate() {
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslated(100, 100, 0);
    glRotated(45, 0, 0, 1);
    glTranslated(-100, -100, 0);
    draw_triangle();
    glPopMatrix();
}

void scale_triangle() {
    glPushMatrix();
    glScaled(2, 2, 1);
    draw_triangle();
    glPopMatrix();
}

void pivot_point_scale() {
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslated(100, 100, 0);
    glScaled(2, 2, 1);
    glTranslated(-100, -100, 0);
    draw_triangle();
    glPopMatrix();
}

void displayMe() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 0.0, 0.0, 0.0);
    glColor3f(1, 0, 0);
    draw_triangle();
    glFlush();
}

void menu_rotate(int id) {
    switch(id) {
        case 1:
            translate();
            break;
        case 2:
            rotate_triangle();
            break;
        case 3:
            pivot_point_rotate();
            break;
        case 4:
            scale_triangle();
            break;
        case 5:
            pivot_point_scale();
            break;
        default:
            exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Transformation");
    myinit();
    glutCreateMenu(menu_rotate);
    glutAddMenuEntry("Translate", 1);
    glutAddMenuEntry("Rotation About Origin", 2);
    glutAddMenuEntry("Rotation About fixed point", 3);
    glutAddMenuEntry("Scale About Origin", 4);
    glutAddMenuEntry("Scale About fixed point", 5);
    glutAddMenuEntry("EXIT", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}
