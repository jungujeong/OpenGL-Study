#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "BunnyModel.h"


void MyDisplay() {
	
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();   //  ���� ��ȯ ��� �ʱ�ȭ �� ũ�� 1.5�� ����
	glScalef(1.5f, 1.5f, 1.5f);
	glRotatef(90, 0, 1, 0);  //  �ٶ󺸴� ���� ����

	// BunnyModel �׸��� �ڵ�
	unsigned int i;
	for (i = 0; i < (sizeof(face_indicies) / sizeof(face_indicies[0])); i++)  // 16301  (byte���̹Ƿ� �迭 ũ�� * 2(short int))
	{
		int vi;
		glBegin(GL_LINES);
		vi = face_indicies[i][0];   glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		vi = face_indicies[i][1];   glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		vi = face_indicies[i][1];   glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		vi = face_indicies[i][2];   glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		vi = face_indicies[i][2];   glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		vi = face_indicies[i][0];   glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		glEnd();
	}

	glFlush();

}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutCreateWindow("OpenGL Example");
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	
	return 0;
}
