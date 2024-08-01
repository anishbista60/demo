#include <GL/glut.h>
#include <stdio.h>

int iter;
typedef float point[3];
point v[] = {
    {0.0, 0.0, 1.0},
    {0.0, 1.0, 0.0},
    {-1.0, -1.0, 0.0},
    {1.0, -1.0, 0.0},
};

void myInit()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void triangle(point a, point b, point c)
{
    glBegin(GL_TRIANGLES);
    glVertex3fv(a);
    glVertex3fv(b);
    glVertex3fv(c);
    glEnd();
}

void divide_triangle(point a, point b, point c, int m)
{
    if (m == 0)
    {
        triangle(a, b, c);
        return;
    }

    point v1, v2, v3;
    for (int i = 0; i < 3; i++)
        v1[i] = (a[i] + b[i]) / 2;

    for (int i = 0; i < 3; i++)
        v2[i] = (b[i] + c[i]) / 2;

    for (int i = 0; i < 3; i++)
        v3[i] = (a[i] + c[i]) / 2;

    divide_triangle(a, v1, v3, m - 1);
    divide_triangle(v1, b, v2, m - 1);
    divide_triangle(v3, v2, c, m - 1);
}

void tetrehedron(int m)
{
    glColor3f(0, 0, 1);
    divide_triangle(v[1], v[0], v[3], m);

    glColor3f(1, 0, 0);
    divide_triangle(v[1], v[2], v[0], m);

    glColor3f(1, 1, 0);
    divide_triangle(v[1], v[2], v[3], m);

    glColor3f(0, 1, 0);
    divide_triangle(v[0], v[2], v[3], m);
}

void display()
{
    tetrehedron(iter);
    glFlush();
}

int main(int argc, char **argv)
{
    printf("Enter no.of iterations: ");
    scanf("%d", &iter);
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Program-4");

    myInit();
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();

    return 0;
}
