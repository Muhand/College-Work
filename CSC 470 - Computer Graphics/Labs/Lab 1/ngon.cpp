#include <windows.h> // use proper includes for your system
#include <math.h>
#include <gl/Gl.h>
#include <gl/glut.h>

#include "C:/canvas/graphics2d.cpp"

Point2 CP1;
const int screenWidth = 640; // width of screen window in pixels
const int screenHeight = 480; // height of screen window in pixels
GLdouble A, B, C, D; // values used for scaling and shifting

void setWindow(float left, float right, float bottom, float top)
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(left, right, bottom, top);
}

void setViewport(float left, float right, float bottom, float top)
{
	glViewport(left, bottom, right-left, top-bottom);
}

void lineTo(float x, float y)
{
	glBegin(GL_LINES);
		glVertex2f((GLfloat)CP1.x, (GLfloat)CP1.y);
		CP1.x = x; 
		CP1.y = y;
		glVertex2f((GLfloat)CP1.x, (GLfloat)CP1.y);
	glEnd();
	glFlush();
}

void moveTo(float x, float y)
{
	CP1.x = x; 
	CP1.y = y;
}

void ngon(int n,float cx, float cy, float radius)
{
	#define RadPerDeg 0.017453393 //radians per degree
	if(n < 3) 
		return; // bad number of sides
	double angle = 0, angleInc = 2 * 3.14159265 /n; //angle increment
	moveTo(cx + radius, cy);
	for(int k = 1; k <= n; k++)
	{
		angle += angleInc;
		lineTo(radius * cos(angle) + cx, radius*sin(angle) + cy);
	}
}

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0); 
	glColor3f(0.0f, 0.0f, 1.0f); 
	glLineWidth(4.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
	A = screenWidth / 4.0; // set values used for scaling and shifting
	B = 0.0;
	C = D = screenHeight / 2.0;
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	setWindow(-10.0, 10.0, -10.0, 10.0); 
	glViewport(0,0,480,480);
//	for(int i = 0; i < 5; i++) 
//		for(int j = 0; j < 4; j++)
//		{
//			int L = 500; 
//			setViewport(i * L, L + i * L, j * L, L + j * L); 
			ngon(9,3.0,2.0,5);	
//		}
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv); // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Ngonals"); // open the screen window
	glutDisplayFunc(myDisplay); // register redraw function
	myInit();
	glutMainLoop(); // go into a perpetual loop
}