#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include "LongNeckDino.h"

const float PI = 3.141592654;
GLuint screenW = 640, screenH = 640;
LongNeckDino bronto("BrontoF.data");

void transformations(float angle, float trans_x, float trans_y);
void rotation(float& angle, float angleOffSet, float x, float y);
void draw_The_Dino(float scale);


void dino_Circle(float trans_x, float trans_y, float angleOffSet, bool toRotate, float rotationAngle)
{
	float rotate = 0.0f;
	for (int i = 0; i < 12; ++i)
	{
		rotate += 15.0f;
		transformations(rotate, trans_x, trans_y);
		if (toRotate) {
			rotation(rotationAngle, angleOffSet, 0.0f, 0.0f);
		}
		draw_The_Dino(0.09f);

	}
}

void transformations(float angle, float trans_x, float trans_y)
{
	float rad = 2*PI * angle / 180;
	float x, y;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	x = trans_x + (0.3f)*cos(rad);
	y = trans_y + (0.3f)*sin(rad);
	glTranslatef(x, y, 1.0f);
}

void rotation(float& angle, float angleOffSet, float x, float y)
{

	angle += angleOffSet;
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	
}

void draw_The_Dino(float scale)
{
	for (int i = 0; i < bronto.get_Array_Size(); ++i)  // read each polyline
	{
		int temp_size;
		temp_size = bronto.vector_size(i);

		glBegin(GL_LINE_STRIP);	     // draw the next polyline
		for (int j = 0; j < temp_size; ++j)
		{
			glVertex2f(bronto.get_X_Coord(i, j)*scale, bronto.get_Y_Coord(i, j)*scale);
		}
		glEnd();
	}
	
}

void mainRenderer()
{
	glLoadIdentity();

	dino_Circle(0.5f, 0.5f, 0.0f, FALSE, 0.0f);
	
	dino_Circle(-0.5f, 0.5f, 30.0f, TRUE, -90.0f);

	dino_Circle(0.5f, -0.5f, 0.0f, TRUE, -180.0f);

	dino_Circle(-0.5f, -0.5f, 30.0f, TRUE, 60.0f);

	glFlush();
	glutSwapBuffers();
}

void win_Resize(int s_Width, int s_Hight)
{
	glViewport(0, 0, s_Width, s_Hight);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void initilization()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1, 1, -1.0, 1.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screenW, screenH);
	glutCreateWindow("Dino Circles");

	glutDisplayFunc(mainRenderer);
	glutReshapeFunc(win_Resize);

	initilization();

	glutMainLoop();
}