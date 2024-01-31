#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>

GLfloat Delta = 0.0;

void MyDisplay() {
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.5, 0.8);
	glBegin(GL_POLYGON);
	  glVertex3f(-1.0 + Delta, -0.5, 0.0);
	  glVertex3f(0.0 + Delta, -0.5, 0.0);
	  glVertex3f(0.0 + Delta, 0.5, 0.0);
	  glVertex3f(-1.0 + Delta, 0.5, 0.0);
	glEnd();
	glFlush();
}

void MyTimer(int Value)
{
	Delta += 0.005;
	glutPostRedisplay();
	glutTimerFunc(100, MyTimer, 1);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutCreateWindow("OpenGL Example");
	glutDisplayFunc(MyDisplay);

	glutTimerFunc(100, MyTimer, 1);

	glutMainLoop();
	
	return 0;
}
