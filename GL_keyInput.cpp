#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "BunnyModel.h"

float xShift = 0;
float yShift = 0;

void MyDisplay() {
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5+xShift, -0.5+yShift, 0.0);
	glVertex3f(0.5 + xShift, -0.5 + yShift, 0.0);
	glVertex3f(0.5 + xShift, 0.5 + yShift, 0.0);
	glVertex3f(-0.5 + xShift, 0.5 + yShift, 0.0);

	glEnd();

	glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int x, int y)
{
	switch (KeyPressed)
	{
	case 'Q':
	case 'q': 
		exit(0); break;
	case 'w':
		yShift += 0.1; break;
	case 's':
		yShift -= 0.1; break;
	case 'a':
		xShift -= 0.1; break;
	case 'd':
		xShift += 0.1; break;
	}
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutCreateWindow("OpenGL Example");
	glutDisplayFunc(MyDisplay);

	glutKeyboardFunc(MyKeyboard);

	glutMainLoop();
	
	return 0;
}
