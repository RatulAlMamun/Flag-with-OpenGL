#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.1415926535898

void Draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2.5);
    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(5.0, 3.0);
    glVertex2f(-5.0, 3.0);
    glVertex2f(-5.0, -3.0);
    glVertex2f(5.0, -3.0);
    glEnd();


    glColor3f(1.0, 0.0, 0.0);
    GLint circle_points = 1000;
    GLfloat angle;
    glBegin(GL_POLYGON);
    for(int i = 0; i < circle_points; i++){
        angle = 2*PI*i/circle_points;
        glVertex2f(2.0*cos(angle), 2.0*sin(angle));
    }
    glEnd();
    glFlush();
}

void Initialize(){
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -10, 10);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(400, 100);
    glutCreateWindow("Points");
    Initialize();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
