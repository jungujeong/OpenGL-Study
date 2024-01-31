#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>


GLuint g_objectID = -1;

GLint GenerateCallList()
{
	GLint lid = glGenLists(1);

	glNewList(lid, GL_COMPILE);
	    glColor3f(1.0f, 1.0f, 0.0f);
		glBegin(GL_POLYGON);
	     	glVertex3f(0.5, 0.5, 0.0);
			glVertex3f(-0.5, 0.5, 0.0);
			glVertex3f(-0.5, -0.5, 0.0);
			glVertex3f(0.5, -0.5, 0.0);
		glEnd();
	glEndList();

	return lid;
}


void MyDisplay() {
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glCallList(g_objectID);
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutCreateWindow("OpenGL Example");

	g_objectID = GenerateCallList();

	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	
	return 0;
}
