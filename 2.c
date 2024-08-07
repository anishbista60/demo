#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

int i, j, l;
float r[3][3];
float p[3][3] = {{0, 100, 50}, {0, 0, 50}, {1, 1, 1}};
float t[3][3] = {{1, 0, 100}, {0, 1, 0}, {0, 0, 1}};
float s[3][3] = {{5, 0, 0}, {0, 5, 0}, {0, 0, 1}};

void myinit() {
    glClearColor(0.0, 0.0, 1.0, 1.0); // Background
    gluOrtho2D(-500, 500, -500, 500);
}

void rotate() {
    float theta = 0;
    printf("Enter the angle in degrees: ");
    scanf("%f", &theta);
    float angle = (theta * 3.14) / 180;
    float cosx = cos(angle);
    float sinx = sin(angle);
    float rot[3][3] = {{cosx, -sinx, 0}, {sinx, cosx, 0}, {0, 0, 1}};

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            r[i][j] = 0;
            for (l = 0; l< 3; l++) {
                r[i][j] += rot[i][l] * p[l][j];
            }
        }
    }
}

void scale() {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            r[i][j] = 0;
            for (l = 0; l < 3; l++) {
                r[i][j] += s[i][l] * p[l][j];
            }
        }
    }
}

void translate() {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            r[i][j] = 0;
            for (l = 0; l < 3; l++) {
                r[i][j] += t[i][l] * p[l][j];
            }
        }
    }
}

void draw_triangle(float tri[3][3]) {
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(tri[0][0], tri[1][0]);
    glVertex2f(tri[0][1], tri[1][1]);
    glVertex2f(tri[0][2], tri[1][2]);
    glEnd();
}

void displayMe() {
    glClear(GL_COLOR_BUFFER_BIT);
    draw_triangle(p);
    draw_triangle(r);
    glFlush();
}

int main(int argc, char** argv) {
    int var;
    printf("Enter the Operation You want to Perform:\n");
    printf("1. Translation\n2. Scalability\n3. Rotation\n");
    scanf("%d", &var);

    switch (var) {
        case 1:
            translate();
            break;
        case 2:
            scale();
            break;
        case 3:
            rotate();
            break;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(200, 200);
    glutCreateWindow("Hello World");
    myinit();
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}
