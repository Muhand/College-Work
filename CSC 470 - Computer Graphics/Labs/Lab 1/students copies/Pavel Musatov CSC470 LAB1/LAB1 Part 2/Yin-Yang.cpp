#include <gl\glew.h>
#include <GL\GLU.h>
#include <GL\freeglut.h>
#include <math.h>
#include <iostream>

int screenW = 640;
int screenH = 640;

void drawCircle(float centerX, float centerY, float radius, float colorTop, float colorBottom)
{
	const float PI = 3.141592654;
	float x, y;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(colorTop, colorTop, colorTop);
	for (float angle = 0.0f; angle <= 360; angle += 0.01f)
	{
		float rad = PI * angle / 180;
		x = centerX+radius*cos(rad);
		y = centerY + radius*sin(rad);
		glVertex3f(x, y, 0.0f);
		if (angle >= 179.9f)
		{
			glColor3f(colorBottom, colorBottom, colorBottom);
		}
	}
	glEnd();
}


void initialize(void)
{
	glewInit();

	glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glShadeModel(GL_FLAT);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f);

}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawCircle(0.0f, 0.0f, 1.0f, 0.0f, 1.0f);	/*Drawing the first large circle*/
	drawCircle(-0.5f, 0.0f, 0.5f, 0.0f, 0.0f);	/*Drawing the left small, black circle*/
	drawCircle(0.5f, 0.0f, 0.5f, 1.0f, 1.0f);	/*Drawing the right small white circle*/
	drawCircle(0.5f, 0.0f, 0.20f, 0.0f, 0.0f);	/*Drawing the right smallest black circle*/
	drawCircle(-0.5f, 0.0f, 0.20f, 1.0f, 1.0f);	/*Drawing the left smallest white circle*/
	
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screenW,screenH);
	glutCreateWindow(" The Ying Yang");

	initialize();

	glutDisplayFunc(draw);
	glutReshapeFunc(reshape);


	glutMainLoop();

}