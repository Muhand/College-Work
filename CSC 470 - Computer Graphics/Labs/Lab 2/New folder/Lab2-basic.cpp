//
////Muhammad Sheikh
////Stephen Giglia
////Lab #2 - 470
//
//#include <stdio.h>   // use as needed for your system
//#include <stdlib.h>
//#include <math.h>
//#include <cmath>
//#include <GL/GLUT/glut.h>
//#define getrandom(min, max) ((rand()%(int)(((max) + 1)-(min)))+ (min))
//#define PI 3.14159
//
//class Point2   //single point w/ floating point coordinates
//{
//public:
//	float x, y;
//	Point2() { x = y = 0.0f; } //constructor 1
//	Point2(float xx, float yy) { x = xx; y = yy; } //constructor 2
//	void set(float xx, float yy) { x = xx; y = yy; }
//	float getX() { return x; }
//	float getY() { return y; }
//	void draw(void)
//	{
//		glBegin(GL_POINTS); //draw this point
//		glVertex2f((GLfloat)x, (GLfloat)y);
//		glEnd();
//	}
//
//};
//
//Point2 CP;      //current turtle point
//float CD = 90;  //current turtle direction
//
////FOR CREATIVE
//				//string production rules
////char atom[25] = "FXF";                      //starting string
////char Fstr[100] = "FF-[-FFA+F-F+L]+[+F+F][FL]";   //F production rule
////char Xstr[50] = "[-FLFFF-][+F+FLF+F--F]";                       //X production rule
////char Ystr[25] = "";                       //Y production rule
////float angle = getrandom(20, 30);                         //turn angle
//
////FOR BASIC
////char atom[25] = "FX";                      //starting string
////char Fstr[100] = "FF-[-F+F+F]+[+F-F-F]+F-F+[+FF-]-";   //F production rule
////char Xstr[50] = "X+F-[FX]+";                       //X production rule
////char Ystr[25] = "";  
////float angle = 27;                         //turn angle
//
//
////string production rules
//char atom[25] = "F";                      //starting string
//char Fstr[25] = "FF-[-F+F+F]+[+F-F-F]";   //F production rule
//char Xstr[25] = "";                       //X production rule
//char Ystr[25] = "";                       //Y production rule
//float angle = 22;                         //turn angle
//
//
//
//int length = 20;                          //forward length
//static int thickness = 3;
//float red, green, blue;
//
////array of current turtle locations
////better to use a linked list for these :)
////These arrays will allow a maximum of 100 nested [] pairs.   Should be heaps!!
//Point2 saveTut[100];
//float saveAng[100];
//int curr = 0;
//
////min and max extremes for the window size
//float xmin = 0.0, xmax = 0.0, ymin = 0.0, ymax = 0.0;
//
//
////-----TURTLE DRAWING FUNCTIONS- TAKEN OUT OF CANVAS.H------------------
//void moveTo(float x, float y)
//{
//	CP.set(x, y);
//}
//
//void lineTo(float x, float y)
//{
//	glBegin(GL_LINES);
//	glVertex2f((GLfloat)CP.getX(), (GLfloat)CP.getY());
//	glVertex2f((GLfloat)x, (GLfloat)y); //draw the line
//	glEnd();
//	CP.set(x, y); //update current point to new point
//	glFlush();
//}
//
//void turnTo(float angle) { CD = angle; }
//void turn(float angle) { CD += angle; }
//void forward(float dist, int isVisible)
//{
//	glLineWidth(thickness * 2);
//	const float rpd = 0.017453393;
//	float x1 = CP.x + dist*cos(rpd*CD);
//	float y1 = CP.y + dist*sin(rpd*CD);
//	if (isVisible)
//		lineTo(x1, y1);
//	else
//		moveTo(x1, y1);
//}
//
//void saveTurtle()
//{
//	saveTut[curr].set(CP.x, CP.y);
//	saveAng[curr] = CD;
//	curr++;
//}
//
//void restoreTurtle()
//{
//	curr--;
//	moveTo(saveTut[curr].getX(), saveTut[curr].getY());
//	turnTo(saveAng[curr]);
//}
//void drawLeaf()
//{
//
//	int x = CP.x;
//	int y = CP.y;
//	glBegin(GL_TRIANGLES);
//	glPushMatrix();
//	glRotatef(CD, 0, 0, 1);
//
//	glColor3f(0.5, .4, 0.05);
//	glVertex3f(x, y, 0);
//
//	glColor3f(0.2, .4, 0.1);
//	glVertex3f(10 + x, 10 + y, 0);
//	glVertex3f(x, 20 + y, 0);
//
//
//	glColor3f(0, 0.2, 0);
//	glVertex3f(x, y, 0);
//	glVertex3f(x, 20 + y, 0);
//	glVertex3f(-10 + x, 10 + y, 0);
//
//	glPopMatrix();
//	glEnd();
//	glColor3f(red, green, blue);
//}
//void drawApple()
//{
//	int xpos = CP.x;
//	int ypos = CP.y;
//
//	int lines = 100;
//	glColor3f(1, 0, 0);
//	glBegin(GL_POLYGON);
//	for (int i = 0; i <= lines; i++) {
//		glLineWidth(10);
//		double angle = 2 * PI * i / lines;
//		double x = cos(angle) * 6 + xpos;
//		double y = sin(angle) * 5 + ypos - 3;
//		glVertex2d(x, y);
//	}
//	glLineWidth(thickness);
//	glEnd();
//	glColor3f(red, green, blue);
//}
//
////Draw L-System from String--------------------------------
//void produceString(char *st, int order, int draw)
//{
//	float sx, sy, sa;
//	glLineWidth(order);
//
//	while (*st != '\0')		// scan through each character
//	{
//		switch (*st)
//		{
//		case '[': saveTurtle(); thickness--; break;
//		case ']': restoreTurtle(); thickness++; break;
//		case '+': turn(-angle); break;	// right turn
//		case '-': turn(angle); break;  // left turn
//		case 'F': if (order > 0)
//			produceString(Fstr, order - 1, draw);
//				  else
//				  {
//					  forward(length, draw);
//					  if (!draw)
//					  {
//						  if (CP.x < xmin)
//							  xmin = CP.x;
//						  if (CP.x > xmax)
//							  xmax = CP.x;
//						  if (CP.y < ymin)
//							  ymin = CP.y;
//						  if (CP.y > ymax)
//							  ymax = CP.y;
//					  }
//				  }
//				  break;
//		case 'X': if (order > 0)
//			produceString(Xstr, order - 1, draw); break;
//		case 'Y': if (order > 0)
//			produceString(Ystr, order - 1, draw); break;
//
//		case 'L': if (order <= 0)
//			drawLeaf(); break;
//		case 'A': if (order <= 0)
//			drawApple(); break;
//		}
//		st++;
//	}
//}
//
//
////<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
//void myDisplay(void)
//{
//	CP.set(0, 0);
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	//red = 0.9f; green = 0.8f; blue = 0.5f;
//	red = 0.6f; green = 0.4f; blue = 0.0f;
//	glColor3i(red, green, blue);
//	glLineWidth(1);
//
//	//setup initial turtle position
//	//run through once to determine window coordinates
//	moveTo(0.0, 0.0);
//	turnTo(90);
//	produceString(atom, thickness, 0);
//	gluOrtho2D(xmin - 10, xmax + 10, ymin - 10, ymax + 10);
//
//	//this time draw the curve
//	moveTo(0.0, 0.0);
//	turnTo(90);
//	produceString(atom, thickness, 1);
//	glFlush();		                 // send all output to display
//}
//
//void main(int argc, char** argv)
//{
//	glutInit(&argc, argv);          // initialize the toolkit
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
//	glutInitWindowSize(600, 600);     // set window size
//	glutInitWindowPosition(100, 150); // set window position on screen
//	glutCreateWindow("L-System Tree"); // open the screen window and set the name
//	glutDisplayFunc(myDisplay);     // register redraw function
//	glutMainLoop();
//	return;
//}
//
////*/

#include <stdio.h>   // use as needed for your system
#include <math.h>
#include <GL/glut/glut.h>
#define getrandom(min, max) ((rand()%(int)(((max) + 1)-(min)))+ (min))

class Point2   //single point w/ floating point coordinates
{
public:
	float x, y;
	Point2() { x = y = 0.0f; } //constructor 1
	Point2(float xx, float yy) { x = xx; y = yy; } //constructor 2
	void set(float xx, float yy) { x = xx; y = yy; }
	float getX() { return x; }
	float getY() { return y; }
	void draw(void)
	{
		glBegin(GL_POINTS); //draw this point
		glVertex2f((GLfloat)x, (GLfloat)y);
		glEnd();
	}

};

Point2 CP;      //current turtle point
float CD = 90;  //current turtle direction

				//string production rules
char atom[25] = "F";                      //starting string
char Fstr[25] = "FF-[-F+F+F]+[+F-F-F]";   //F production rule
char Xstr[25] = "";                       //X production rule
char Ystr[25] = "";                       //Y production rule
float angle = 27;                         //turn angle
int length = 20;                          //forward length

										  //array of current turtle locations
										  //better to use a linked list for these :)
										  //These arrays will allow a maximum of 100 nested [] pairs.   Should be heaps!!
Point2 saveTut[100];
float saveAng[100];
int curr = 0;

//min and max extremes for the window size
float xmin = 0.0, xmax = 0.0, ymin = 0.0, ymax = 0.0;


//-----TURTLE DRAWING FUNCTIONS- TAKEN OUT OF CANVAS.H------------------
void moveTo(float x, float y)
{
	CP.set(x, y);
}

void lineTo(float x, float y)
{
	glBegin(GL_LINES);
	glVertex2f((GLfloat)CP.getX(), (GLfloat)CP.getY());
	glVertex2f((GLfloat)x, (GLfloat)y); //draw the line
	glEnd();
	CP.set(x, y); //update current point to new point
	glFlush();
}

void turnTo(float angle) { CD = angle; }
void turn(float angle) { CD += angle; }
void forward(float dist, int isVisible)
{
	const float rpd = 0.017453393;
	float x1 = CP.x + dist*cos(rpd*CD);
	float y1 = CP.y + dist*sin(rpd*CD);
	if (isVisible)
		lineTo(x1, y1);
	else
		moveTo(x1, y1);
}

void saveTurtle()
{
	saveTut[curr].set(CP.x, CP.y);
	saveAng[curr] = CD;
	curr++;
}

void restoreTurtle()
{
	curr--;
	moveTo(saveTut[curr].getX(), saveTut[curr].getY());
	turnTo(saveAng[curr]);
}

//Draw L-System from String--------------------------------
void produceString(char *st, int order, int draw)
{
	float sx, sy, sa;
	glLineWidth(order);

	while (*st != '\0')		// scan through each character
	{
		switch (*st)
		{
		case '[': saveTurtle(); break;
		case ']': restoreTurtle(); break;
		case '+': turn(-angle); break;	// right turn
		case '-': turn(angle); break;  // left turn
		case 'F': if (order > 0)
			produceString(Fstr, order - 1, draw);
				  else
				  {
					  forward(length, draw);
					  if (!draw)
					  {
						  if (CP.x < xmin)
							  xmin = CP.x;
						  if (CP.x > xmax)
							  xmax = CP.x;
						  if (CP.y < ymin)
							  ymin = CP.y;
						  if (CP.y > ymax)
							  ymax = CP.y;
					  }
				  }
				  break;
		case 'X': if (order > 0)
			produceString(Xstr, order - 1, draw); break;
		case 'Y': if (order > 0)
			produceString(Ystr, order - 1, draw); break;
		}
		st++;
	}
}


//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	CP.set(0, 0);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 0);
	glLineWidth(1);

	//setup initial turtle position
	//run through once to determine window coordinates
	moveTo(0.0, 0.0);
	turnTo(90);
	produceString(atom, 4, 0);
	gluOrtho2D(xmin - 10, xmax + 10, ymin - 10, ymax + 10);

	//this time draw the curve
	moveTo(0.0, 0.0);
	turnTo(90);
	produceString(atom, 4, 1);
	glFlush();		                 // send all output to display
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(600, 600);     // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("L-System Tree"); // open the screen window and set the name
	glutDisplayFunc(myDisplay);     // register redraw function
	glutMainLoop();

}

