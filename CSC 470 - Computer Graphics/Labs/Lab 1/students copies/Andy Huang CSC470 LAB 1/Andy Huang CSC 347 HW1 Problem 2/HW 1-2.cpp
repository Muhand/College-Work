//Andy Huang
//Homework 1, Problem 2
//CSC 470 Computer Graphics
#include <math.h>
#include <iostream>
#include <GL\glut.h>
#define SCREENWIDTH 640
#define SCREENHEIGHT 480
struct Point
{
	int x, y;
};
void myInit(void)
{
	glClearColor(0.5, 0.5, 0.5, 0.0);
	glColor3f(1.0, 0.0f, 1.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, SCREENWIDTH, 0.0, SCREENHEIGHT);
}
void drawArc(Point center, GLfloat radius, GLfloat startingAngle, GLfloat endingAngle, GLfloat r,
	GLfloat g, GLfloat b)
{
	const float Pi = 4 * atan(1.0);
	Point prev, current;
	glColor3f(r, g, b);
	glBegin(GL_LINES);
	glVertex2f(center.x, center.y);
	glVertex2f(center.x + radius * cos((startingAngle * Pi) / 180), center.y + radius *
		sin((startingAngle * Pi) / 180));
	glEnd();
	for (GLfloat angle = (startingAngle * Pi) / 180; angle <= (endingAngle * Pi) / 180; angle += Pi / 180)
	{
		current.x = center.x + radius * cos(angle);
		current.y = center.y + radius * sin(angle);
		if (angle != (startingAngle * Pi) / 180)
		{
			glBegin(GL_LINES);
			glVertex2f(prev.x, prev.y);
			glVertex2f(current.x, current.y);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex2f(center.x, center.y);
			glVertex2f(prev.x, prev.y);
			glVertex2f(current.x, current.y);
			glEnd();
			glFlush();
		}
		prev.x = current.x;
		prev.y = current.y;
	}
	glBegin(GL_LINES);
	glVertex2f(prev.x, prev.y);
	glVertex2f(center.x, center.y);
	glEnd();
}
void YingYang()
{
	Point center, leftCenter, rightCenter;
	//Calculating the Center
	center.x = 640 / 2;
	center.y = 480 / 2;
	//Calculating the Left Center
	leftCenter.x = 640 / 2 - 80;
	leftCenter.y = 480 / 2;
	//Calculating the Right Center
	rightCenter.x = 640 / 2 + 80;
	rightCenter.y = 480 / 2;

	drawArc(center, 160, 0, 360, 0, 0, 0);	//This is to draw the black part
	drawArc(center, 162, 0, 360, 0, 0, 0);	//This is to draw an outline for the circle
	drawArc(center, 160, 180, 360, 1, 1, 1);	//This is to draw the white circle
	drawArc(leftCenter, 80, 180, 361, 0, 0, 0);	//This is to draw the black semi circle
	drawArc(rightCenter, 80, 0, 181, 1, 1, 1);	//This is to draw the white semi circle
	drawArc(leftCenter, 20, 0, 360, 1, 1, 1);	//This is to draw the small white circle
	drawArc(rightCenter, 20, 0, 360, 0, 0, 0);	//This is to draw the small black circle
}
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(.5, .5, .5);
	glRecti(100, 20, 540, 460);
	YingYang();
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(SCREENWIDTH, SCREENHEIGHT);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Ying-Yang");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}