#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#define Pi 3.1415926535897932384626433832795

void DrawStar(float fX, float fY){
	const float Radius = 1;
	const float InnerRadius = Radius*(1.0/(sin((2.0*Pi)/5.0)*2.0*cos(Pi/10.0) + sin((3.0*Pi)/10.0)));
	glColor3f(0.0, 0.522, 0.247);
	glBegin(GL_TRIANGLE_FAN);
    glVertex3f(fX, fY, 0.0);
	for(int i = 0; i < 10; ++i){
		float fAngleStart = Pi/2.0 + (i*2.0*Pi)/10.0;
		float fAngleEnd	= fAngleStart + Pi/5.0;
		if(i % 2 == 0) {
			glVertex3f((fX + Radius*cos(fAngleStart)/1.9), (fY + Radius*sin(fAngleStart)), 0.0);
			glVertex3f((fX + InnerRadius*cos(fAngleEnd)/1.9), (fY + InnerRadius*sin(fAngleEnd)), 0.0);
        } else {
			glVertex3f((fX + InnerRadius*cos(fAngleStart)/1.9), (fY + InnerRadius*sin(fAngleStart)), 0.0);
			glVertex3f((fX + Radius*cos(fAngleEnd)/1.9), (fY + Radius*sin(fAngleEnd)), 0.0);
        }
	}
	glEnd();
}

void draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(0.808, 0.067, 0.149);   //redish rectangle
    glVertex3f(2.0, 8.0, 0.0);
    glVertex3f(8.0, 8.0, 0.0);
    glVertex3f(8.0, 6.0, 0);
    glVertex3f(2.0, 6.0, 0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);   //black rectangle
    glVertex3f(2.0, 2.0, 0.0);
    glVertex3f(8.0, 2.0, 0.0);
    glVertex3f(8.0, 4.0, 0);
    glVertex3f(2.0, 4.0, 0);
    glEnd();
    DrawStar(4,5.0);
    DrawStar(6,5.0);

	glFlush();
}


void Initialize() {
	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 10.0, 0.0, 10.0, -10.0, 10.0);
}

int main(int iArgc, char** cppArgv)
{
    glutInit(&iArgc, cppArgv);
    glutInitWindowSize(950, 500);
	glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutCreateWindow("The flag of Syria");

    Initialize();
    glutDisplayFunc(draw);

	glutMainLoop();
	return 0;
}
