#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>


void MyDisplay() {
	
	glBegin(GL_TRIANGLES);
	    glColor3f(0.0, 1.0, 0.0);
		glVertex2f(0.0, 0.5);
		glColor3f(1.0, 0.0, 1.0);
		glVertex2f(0.5, 0.0);
		glVertex2f(0.0, 0.0);
	glEnd();

	glFlush();

}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(512, 256);
	glutCreateWindow("OpenGL Example");
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
