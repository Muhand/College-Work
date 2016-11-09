#include <windows.h> // use proper includes for your system
#include <math.h>
#include <string>
#include <gl/Gl.h>
#include <gl/glut.h>

using namespace std;

const int screenWidth = 500; // width of screen window in pixels
const int screenHeight = 400; // height of screen window in pixels

GLfloat r1 = 1, g1 = 1, b1 = 1;
GLfloat r2 = 1, g2 = 0, b2 = 0;
int shape = -1;

void setWindow(float left, float right, float bottom, float top){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
	glClearColor(0, 0, 0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void drawTriangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3) {
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();
}

void drawRectangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4){
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
}

void drawPentagon(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4, GLfloat x5, GLfloat y5){
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glVertex2f(x5, y5);
	glEnd();
}

void drawHexagon(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4, GLfloat x5, GLfloat y5, GLfloat x6, GLfloat y6){
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glVertex2f(x5, y5);
	glVertex2f(x6, y6);
	glEnd();
}

void myDisplay(void){
	setWindow(0, 10, 0, 10);

	if (shape == 2) glClearColor(r1, g1, b1, 0);
	else glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	if (shape == 0){
		glColor3f(r1, g1, b1);
		drawTriangle(0, 0, 10, 0, 5, 10);
		glColor3f(r2, g2, b2);
		drawTriangle(4.5, 4, 5.5, 4, 5, 10);
		drawTriangle(0, 0, 5, 5, 5, 3.5);
		drawTriangle(10, 0, 5, 5, 5, 3.5);
	}
	else if (shape == 1){
		glColor3f(r1, g1, b1);
		drawPentagon(5, 10, 0, 6, 1, 0, 9, 0, 10, 6);
		glColor3f(r2, g2, b2);
		drawTriangle(4.5, 4, 5.5, 4, 5, 10);
		drawTriangle(1, 0, 5, 5, 5, 3.5);
		drawTriangle(9, 0, 5, 5, 5, 3.5);
		drawTriangle(0, 6, 5, 5, 5, 3.5);
		drawTriangle(10, 6, 5, 5, 5, 3.5);
	}
	else if (shape == 2){
		glColor3f(0, 0, 0);
		drawTriangle(3, 0, 5, 3.3, 7, 0);
		drawTriangle(0, 3.3, 0, 8, 3.5, 5.5);
		drawTriangle(10, 3.3, 10, 8, 6.5, 5.5);
		drawTriangle(5, 10, 0, 10, 4.5, 6.5);
		drawTriangle(5, 10, 10, 10, 5.5, 6.5);
		drawTriangle(5.5, 6.5, 10, 8, 10, 10);
		drawTriangle(4.5, 6.5, 0, 8, 0, 10);
		drawRectangle(7, 0, 10, 0, 10, 3.3, 6, 4);
		drawRectangle(3, 0, 0, 0, 0, 3.3, 4, 4);
		glColor3f(r1, g1, b1);
		glRectf(10, 10, 0.0, 10);
	}
	else if (shape == 3){
		glColor3f(r1, g1, b1);
		drawHexagon(2, 0, 8, 0, 10, 5, 8, 10, 2, 10, 0, 5);
		glColor3f(r2, g2, b2);
		drawTriangle(0, 5, 5, 4, 5, 6);
		drawTriangle(10, 5, 5, 4, 5, 6);
		drawTriangle(2, 10, 4, 5, 6, 5);
		drawTriangle(8, 10, 6, 5, 4, 5);
		drawTriangle(2, 0, 4, 5, 6, 5);
		drawTriangle(8, 0, 6, 5, 4, 5);
	}
	glFlush();
}

void color_menu(int id){
	if (id == 0)      { r1 = 1.0; g1 = 0.0; b1 = 0.0; }
	else if (id == 1) { r1 = 0.0; g1 = 1.0; b1 = 0.0; }
	else if (id == 2) { r1 = 0.0; g1 = 0.0; b1 = 1.0; }
	else if (id == 3) { r1 = 1.0; g1 = 1.0; b1 = 1.0; }
	else if (id == 4) { r2 = 1.0; g2 = 0.0; b2 = 0.0; }
	else if (id == 5) { r2 = 0.0; g2 = 1.0; b2 = 0.0; }
	else if (id == 6) { r2 = 0.0; g2 = 0.0; b2 = 1.0; }
	else if (id == 7) { r2 = 1.0; g2 = 1.0; b2 = 1.0; }
	myDisplay();
}

void shape_menu(int id){
	if (id == 4) exit(0);
	else shape = id;
	myDisplay();
}

void main(int argc, char** argv)
{
	int colorMenu1, colorMenu2, shapeMenu;

	glutInit(&argc, argv); // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - screenWidth) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - screenHeight) / 2); // set window position on screen
	glutCreateWindow("Draw Shapes"); // open the screen window
	glutDisplayFunc(myDisplay); // register redraw function

	colorMenu1 = glutCreateMenu(color_menu);
	glutAddMenuEntry("RED", 0);
	glutAddMenuEntry("GREEN", 1);
	glutAddMenuEntry("BLUE", 2);
	glutAddMenuEntry("WHITE", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	colorMenu2 = glutCreateMenu(color_menu);
	glutAddMenuEntry("RED", 4);
	glutAddMenuEntry("GREEN", 5);
	glutAddMenuEntry("BLUE", 6);
	glutAddMenuEntry("WHITE", 7);

	glutCreateMenu(color_menu);
	glutAddSubMenu("OUTSIDE COLOR", colorMenu1);
	glutAddSubMenu("INSIDE COLOR", colorMenu2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	shapeMenu = glutCreateMenu(shape_menu);
	glutAddMenuEntry("TRIANGLE", 0);
	glutAddMenuEntry("PENTAGON", 1);
	glutAddMenuEntry("7 POINTED STAR", 2);
	glutAddMenuEntry("HEXAGON", 3);
	glutAddMenuEntry("QUIT", 4);
	glutAttachMenu(GLUT_LEFT_BUTTON);

	glutMainLoop(); // go into a perpetual loop
}