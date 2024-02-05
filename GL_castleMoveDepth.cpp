#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLint xValue = 0;
GLint yValue = 0;
GLint zValue = 0;

GLint clickDown = 0;
GLint fixX = 0;
GLint fixY = 0;

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(xValue, 1.0, 0.0, 0.0);
	glRotatef(yValue, 0.0, 1.0, 0.0);
	glRotatef(zValue, 0.0, 0.0, 1.0);

	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(-1, 0, 0);
	glColor3f(0, 1, 0);
	glVertex3f(0, -1, 0);
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, -1);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
		glScalef(2.0, 1.0, 1.0);
		glutSolidCube(0.4);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.6, 0.0, 0.0);
		glColor3f(0.0, 0.0, 1.0);
		glutSolidCube(0.4);
		glPushMatrix();
			glTranslatef(0.0, 0.2, 0.0);
			glRotatef(-90.0, 1.0, 0.0, 0.0);
			glColor3f(1.0, 1.0, 0.0);
			glutSolidCone(0.2, 0.3, 36, 10);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(+0.6, 0.0, 0.0);
		glColor3f(0.0, 0.0, 1.0);
		glutSolidCube(0.4);
		glPushMatrix();
			glTranslatef(0.0, 0.2, 0.0);
			glRotatef(-90.0, 1.0, 0.0, 0.0);
			glColor3f(1.0, 1.0, 0.0);
			glutSolidCone(0.2, 0.3, 36, 10);
		glPopMatrix();
	glPopMatrix();

	glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y)
{
	switch (KeyPressed) {
	case 'X':
	case 'x':
		xValue += 1;
		if (xValue > 360)
			xValue -= 360;
		break;
	case 'Y':
	case 'y':
		yValue += 1;
		if (yValue > 360)
			yValue -= 360;
		break;
	case 'Z':
	case 'z':
		zValue += 1;
		if (zValue > 360)
			zValue -= 360;
		break;
	case 'Q':
	case 'q':
		exit(0); break;
	case 32:  //space key
		xValue = 0;
		yValue = 0;
		zValue = 0;
		break;
	case 27: //esc key
		exit(0);
		break;
	case 3: //ctrl + c
		exit(0);
		break;
	}

	glutPostRedisplay();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y)
{
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN)
	{
		fixX = X;
		fixY = Y;
		clickDown = 1;
	}
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_UP)
	{
		clickDown = 0;
	}
}

	void MyMouseMove(GLint X, GLint Y)
	{
		if (clickDown == 1)
		{
			xValue = xValue + (fixX - X);
			yValue = yValue + (fixY - Y);
			fixX = X;
			fixX = Y;
		}
		glutPostRedisplay();
	}



int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH);
	glutCreateWindow("OpenGL Example");
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutMouseFunc(MyMouseClick);
	glutMotionFunc(MyMouseMove);
	glutMainLoop();

	return 0;
}
