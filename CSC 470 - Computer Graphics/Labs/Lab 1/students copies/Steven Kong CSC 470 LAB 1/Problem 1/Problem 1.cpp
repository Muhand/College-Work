//Steven Kong
//CSC 470 Computer Graphics
//Lab 1 Problem 1
#include <math.h>
#include <GL/glut.h>
#include <fstream>
using namespace std;

const int screenWidth = 640; // width of screen window in pixels
const int screenHeight = 480; // height of screen window in pixels
GLdouble A, B, C, D; // values used for scaling and shifting

void setWindow(float left, float right, float bottom, float top) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
}

void setViewport(float left, float right, float bottom, float top) {
	glViewport(left, bottom, right - left, top - bottom);
}

void drawPolyLineFile(char * fileName) {
	fstream inStream;
	inStream.open(fileName, ios::in); // open the "Brontoi.dat"
	if (inStream.fail())
		return;
	//glClear(GL_COLOR_BUFFER_BIT); // clear the screen
	GLint numpolys, numLines, x, y;
	inStream >> numpolys; // read the number of polylines
	for (int j = 0; j < numpolys; j++) { // read each polyline
		inStream >> numLines;
		glBegin(GL_LINE_STRIP); // draw the next polyline
		for (int i = 0; i < numLines; i++) {
			inStream >> x >> y; // read the next x, y pair
			glVertex2i(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

void draw(GLfloat x, GLfloat y, int tilt, bool tilted, bool flip, int radius) {
	const float Pi = 4 * atan(1.0);
	for (GLfloat angle = Pi / 180; angle <= 2 * Pi; angle += Pi / 6) {
		glPushMatrix();
		glTranslatef(radius * cos(angle) + x, radius * sin(angle) + y, 0);
		glRotatef(tilt, 0, 0, 1);
		if (flip)
			glRotatef(180, 1, 0, 0);
		if (tilted)
			tilt += 30;
		glScaled(0.1, 0.1, 0.1);
		glTranslatef(-(radius * cos(angle) + x), -(radius * sin(angle) + y), 0);
		drawPolyLineFile("Brontoi.dat");
		glPopMatrix();
	}
}

//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0); // background color is white
	glColor3f(0.0f, 0.0f, 0.0f); // drawing color is black
	glPointSize(10.0); // a 'dot' is 2 by 2 pixels
	glMatrixMode(GL_PROJECTION); // set "camera shape"
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);

	A = screenWidth / 4.0; // set values used for scaling and shifting
	B = 0.0;
	C = D = screenHeight / 2.0;
}

//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void) { // plot the sinc function, using world coordinates
	glClear(GL_COLOR_BUFFER_BIT);
	setWindow(0, 640.0, 0, 480.0); // set a fixed window
	draw(screenWidth / 4, 3 * screenHeight / 4, -90, 1, 0, 90); //top left
	draw(3 * screenWidth / 4, 3 * screenHeight / 4 + 30, 0, 0, 0, 90); //top right
	draw(screenWidth / 4, screenHeight / 4, 270, 1, 1, 90); //bottom left
	draw(3 * screenWidth / 4, screenHeight / 4 + 20, 0, 0, 1, 90); //bottom right
}

//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
void main(int argc, char** argv) {
	glutInit(&argc, argv); // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Lab 1 Problem 1"); // open the screen window
	glutDisplayFunc(myDisplay); // register redraw function
	myInit();
	glutMainLoop(); // go into a perpetual loop
}