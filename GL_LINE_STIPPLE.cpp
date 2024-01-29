#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>

void drawOneLine(float x1, float y1, float x2, float y2) {
	glBegin(GL_LINES);
	    glVertex2f(x1, y1);
		glVertex2f(x2, y2);
	glEnd();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2.0);

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x0101);
	drawOneLine(-0.8, 0.8, 0.8, 0.8);
	glLineStipple(1, 0x00FF);
	drawOneLine(-0.8, 0.6, 0.8, 0.6);
	glLineStipple(1, 0x1C47);
	drawOneLine(-0.8, 0.4, 0.8, 0.4);
	glLineWidth(5.0);
	glLineStipple(1, 0x0101);
	drawOneLine(-0.8, 0.1, 0.8, 0.1);
	glLineStipple(1, 0x00FF);
	drawOneLine(-0.8, -0.1, 0.8, -0.1);
	glLineStipple(1, 0x1C47);
	drawOneLine(-0.8, -0.3, 0.8, -0.3);

	glLineStipple(5, 0x1C47);
	drawOneLine(-0.8, -0.7, 0.8, -0.7);
	glDisable(GL_LINE_STIPPLE);
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
