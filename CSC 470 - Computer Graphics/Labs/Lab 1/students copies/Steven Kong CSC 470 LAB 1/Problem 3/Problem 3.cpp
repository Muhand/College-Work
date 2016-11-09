//Steven Kong
//CSC 470 Computer Graphics
//Lab 1 Problem 3
#include<stdio.h>
#include <GL/glut.h>
#include<math.h>
using namespace std;

const int screenWidth = 640; // width of screen window in pixels
const int screenHeight = 480; // height of screen window in pixels
GLfloat r1 = 1, g1 = 0, b1 = 1;
GLfloat r2 = 0, g2 = 0, b2 = 1;
GLfloat r3 = 0, g3 = 1, b3 = 0;
int shape = 0;

void drawTriangle(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
void drawRectangle(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
void menu();

//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
void myInit(void) {
	glPointSize(10.0); // a 'dot' is 2 by 2 pixels
	glMatrixMode(GL_PROJECTION); // set "camera shape"
	glLoadIdentity();
	gluOrtho2D(0.0, 1, 0.0, 1);

}

//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void) {
	glClearColor(0, 0, 0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	if (shape == 1) { //Triangle
		drawTriangle(0, 0, 1, 0, 0.5, 1);
		drawTriangle(0, 0, .5, .325, 1, 0);
		drawTriangle(0, 0, .5, 1, .45, .45);
		drawTriangle(1, 0, .5, 1, .55, .45);
	}

	if (shape == 2) { //Pentagon
		glBegin(GL_POLYGON);
		glColor3f(r3, g2, b1);
		glVertex2f(0.5, 1.0);
		glVertex2f(1.0, 0.575);
		glVertex2f(0.8, 0.0);
		glVertex2f(0.2, 0.0);
		glVertex2f(0.0, 0.575);
		glEnd();

		drawTriangle(0.8, 0, .2, 0, .5, .4);
		drawTriangle(0.2, 0, 0, .575, .4, .45);
		drawTriangle(.8, 0, 1, .575, .6, .45);
		drawTriangle(0.5, 1, 0, .575, .45, .55);
		drawTriangle(0.5, 1, 1, .575, .55, .55);
	}

	if (shape == 3) { //Tetradecagon
		drawTriangle(.3, 0, .5, .33, 0.7, 0);
		drawRectangle(.7, 0, 1, 0, 1, .33, .6, .4);
		drawRectangle(.3, 0, 0, 0, 0, .33, .4, .4);
		drawTriangle(1, .33, 1, .8, .65, .55);
		drawTriangle(0, .33, 0, .8, .35, .55);
		drawTriangle(.5, 1, 0, 1, .45, .65);
		drawTriangle(.5, 1, 1, 1, .55, .65);
		drawTriangle(.55, .65, 1, .8, 1, 1);
		drawTriangle(.45, .65, 0, .8, 0, 1);
	}

	if (shape == 4) { //Hexagon
		glBegin(GL_POLYGON);
		glColor3f(r3, g2, b1);
		glVertex2f(0.0, 0.25);
		glVertex2f(0.5, 0.0);
		glVertex2f(1.0, 0.25);
		glVertex2f(1.0, 0.75);
		glVertex2f(0.5, 1.0);
		glVertex2f(0.0, 0.75);
		glEnd();

		drawTriangle(0, .25, .4, .4, 0.5, 0);
		drawTriangle(0.5, 0, .575, .4, 1.0, .25);
		drawTriangle(1.0, 0.25, .65, .5125, 1, .75);
		drawTriangle(0, .25, .35, .5125, 0, .75);
		drawTriangle(0, .75, .425, .625, 0.5, 1.0);
		drawTriangle(0.5, 1.0, .575, .625, 1.0, 0.75);

		const float Pi = 4 * atan(1.0);
		glBegin(GL_POLYGON);
		glColor3f(r2, g3, b1);
		for (GLfloat angle = Pi / 180; angle <= 2 * Pi; angle += Pi / 12)
		{
			glVertex2f(0.175*cos(angle) + 0.5, 0.175*sin(angle) + 0.5);
		}
		glEnd();
	}

	glFlush();

}

void drawTriangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3) {
	glBegin(GL_POLYGON);
	glColor3f(r1, g1, b1);
	glVertex2f(x1, y1);
	glColor3f(r2, g2, b2);
	glVertex2f(x2, y2);
	glColor3f(r3, g3, b3);
	glVertex2f(x3, y3);
	glEnd();
}

void drawRectangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4) {
	glBegin(GL_POLYGON);
	glColor3f(r1, g1, b1);
	glVertex2f(x1, y1);
	glColor3f(r2, g2, b2);
	glVertex2f(x2, y2);
	glColor3f(r3, g3, b3);
	glVertex2f(x3, y3);
	glColor3f(r1, g2, b3);
	glVertex2f(x4, y4);
	glEnd();
}

void colorMenu1(int id) {
	if (id == 1) { r1 = 1.0; g1 = 0.0; b1 = 0.0; }
	else if (id == 2) { r1 = 0.0; g1 = 1.0; b1 = 0.0; }
	else if (id == 3) { r1 = 0.0; g1 = 0.0; b1 = 1.0; }
	else if (id == 4) { r1 = 1.0; g1 = 1.0; b1 = 1.0; }
	myDisplay();
}

void colorMenu2(int id) {
	if (id == 1) { r2 = 1.0; g2 = 0.0; b2 = 0.0; }
	else if (id == 2) { r2 = 0.0; g2 = 1.0; b2 = 0.0; }
	else if (id == 3) { r2 = 0.0; g2 = 0.0; b2 = 1.0; }
	else if (id == 4) { r2 = 1.0; g2 = 1.0; b2 = 1.0; }
	myDisplay();
}

void colorMenu3(int id) {
	if (id == 1) { r3 = 1.0; g3 = 0.0; b3 = 0.0; }
	else if (id == 2) { r3 = 0.0; g3 = 1.0; b3 = 0.0; }
	else if (id == 3) { r3 = 0.0; g3 = 0.0; b3 = 1.0; }
	else if (id == 4) { r3 = 1.0; g3 = 1.0; b3 = 1.0; }
	myDisplay();
}

void shapeMenu(int id) {
	shape = id;
	myDisplay();
}

//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
void main(int argc, char** argv) {
	glutInit(&argc, argv); // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Lab 1 Problem 3"); // open the screen window	
	glutDisplayFunc(myDisplay); // register redraw function
	menu();
	myInit();
	glutMainLoop(); // go into a perpetual loop
}

void colors(int id) {};

void menu() {
	int colorr, color1, color2, color3, shapes;

	color1 = glutCreateMenu(colorMenu1);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	glutAddMenuEntry("White", 4);

	color2 = glutCreateMenu(colorMenu2);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	glutAddMenuEntry("White", 4);

	color3 = glutCreateMenu(colorMenu3);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	glutAddMenuEntry("White", 4);

	colorr = glutCreateMenu(colors);
	glutAddSubMenu("Color 1", color1);
	glutAddSubMenu("Color 2", color2);
	glutAddSubMenu("Color 3", color3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	shapes = glutCreateMenu(shapeMenu);
	glutAddMenuEntry("Triangle", 1);
	glutAddMenuEntry("Pentagon", 2);
	glutAddMenuEntry("Tetradecagon", 3);
	glutAddMenuEntry("Hexagon", 4);
	glutAttachMenu(GLUT_LEFT_BUTTON);
}