//Steven Kong
//CSC 470 Computer Graphics
//Lab 1 Problem 2
#include<math.h>
#include<GL/glut.h>
#define SCREENWIDTH 640
#define SCREENHEIGHT 480

struct Point { GLfloat x, y; };

void myInit(void) {
	glClearColor(0.5, 0.5, 0.5, 0.0);
	glColor3f(1.0, 0.0f, 1.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, SCREENWIDTH, 0.0, SCREENHEIGHT);
}

void drawArc(Point center, GLfloat radius,
	GLfloat startingAngle, GLfloat endingAngle, GLfloat r,
	GLfloat g, GLfloat b) {
	const GLfloat Pi = 4.0 * atan(1.0);
	Point prev, current;
	glColor3f(r, g, b);
	glBegin(GL_LINES);
	glVertex2f(center.x, center.y);
	glVertex2f(center.x + radius * cos((startingAngle * Pi) / 180), center.y + radius *
		sin((startingAngle * Pi) / 180));
	glEnd();
	for (GLfloat angle = (startingAngle * Pi) / 180; angle <= (endingAngle * Pi) / 180;
	angle += Pi / 180) {
		current.x = center.x + radius * cos(angle);
		current.y = center.y + radius * sin(angle);
		if (angle != (startingAngle * Pi) / 180) {
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

void YingYang() {
	Point center, leftCenter, rightCenter;
	center.x = 320;
	center.y = 240;
	leftCenter.x = 240;
	leftCenter.y = 240;
	rightCenter.x = 400;
	rightCenter.y = 240;
	GLfloat radius = 161;
	GLfloat radius2 = 159;
	GLfloat subRadius1 = 80;
	GLfloat subRadius2 = 20;

	//Draw whole circle with black color
	drawArc(center, radius, 0, 360, 0, 0, 0);
	//Draw bottom half circle with white color
	drawArc(center, radius2, 180, 360, 1, 1, 1);
	//Draw left half of circle with subRadius1 with black color
	drawArc(leftCenter, subRadius1, 0, 361, 0, 0, 0);
	//Draw right half of circle with subRadius1 with white color
	drawArc(rightCenter, subRadius1, 0, 361, 1, 1, 1);
	//Draw a circle to left with subRadius2 and white color
	drawArc(leftCenter, subRadius2, 0, 361, 1, 1, 1);
	//Draw a circle to right with subRadius2 and black color
	drawArc(rightCenter, subRadius2, 0, 361, 0, 0, 0);
}

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glRecti(100, 20, 540, 460);
	YingYang();
}

void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(SCREENWIDTH, SCREENHEIGHT);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Lab 1 Problem 2");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}