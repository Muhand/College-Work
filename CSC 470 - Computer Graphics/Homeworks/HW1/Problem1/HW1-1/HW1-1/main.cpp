////////////////////////////////////////////////////////////////////
//			 Muhand Jumah, George Shafik, Anas Mutwakil
//					CSC 470 - Computer Graphics
//				Homework #1 - Problem 1 - Basic work
////////////////////////////////////////////////////////////////////
#include <GL\GLUT\glut.h>

void init(void)
{
	//Initialize the window
	glClearColor(1.0, 1.0, 1.0, 0.0); 
	glMatrixMode(GL_PROJECTION); 
	gluOrtho2D(0.0, 640.0, 0.0, 480);
}

void twoSolidColorShapes(void) {
	glClear(GL_COLOR_BUFFER_BIT);				//Clear the window

	////////////////////////////////////
	//Triangle
	////////////////////////////////////
	glColor3f(0.0, 0.0, 1.0);					//Set background to blue
	glBegin(GL_TRIANGLES);						//Start drawing Lines
	glVertex2i(100, 400);						//Draw vertex 1
	glVertex2i(50, 300);						//Draw vertex 2
	glVertex2i(150, 300);						//Draw vertex 3
	glEnd();									//Connect and end drawing


	////////////////////////////////////
	//Rectangle
	////////////////////////////////////
	glColor3f(0.0, 1.0, 0.0);					//Set background to Green
	glRecti(200, 240, 400, 300);				//Show rectangle

	glFlush();									//View the shapes as quickly as possible
}

void twoMixColorShapes(void) {
	glClear(GL_COLOR_BUFFER_BIT);				//Clear the window

	////////////////////////////////////
	//Triangle
	////////////////////////////////////
	glBegin(GL_TRIANGLES);						//Start drawing Lines
	glColor3f(0.0, 0.0, 1.0);					//First vertex color is blue
	glVertex2i(100, 400);						//Draw vertex 1
	glColor3f(0.0, 1.0, 0.0);					//Second vertex color is green
	glVertex2i(50, 300);						//Draw vertex 2
	glColor3f(1.0, 0.0, 0.0);					//Third vertex color is red
	glVertex2i(150, 300);						//Draw vertex 3
	glEnd();									//Connect and end drawing


	////////////////////////////////////
	//Polygon
	////////////////////////////////////
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(200, 240);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(400, 300);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(200, 300);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2i(300, 200);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2i(100, 100);
	glEnd();


	glFlush();									//View the shapes as quickly as possible
}
void threeShapesWithMasks(void) {
	glClear(GL_COLOR_BUFFER_BIT);				//Clear the window

	glEnable(GL_POLYGON_STIPPLE);

	GLubyte random[] = {
		0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
		0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
		0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
		0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
		0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
		0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
		0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
		0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
		0x08,  0x7F,  0x0C,  0x00,  0x00,  0x00,  0x00,  0x00,
		0x0F,  0x81,  0xFE,  0x00,  0x00,  0x00,  0x00,  0x00,
		0x0F,  0x80,  0x7C,  0x00,  0x00,  0x00,  0x00,  0x00,
		0x00,  0x7F,  0x80,  0x00,  0x00,  0x00,  0x00,  0x00,
		0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
		0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
		0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
		0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00
	};


	/////////////////////////////////////
	//Random Poly
	/////////////////////////////////////
	glColor3f(0.0, 0.0, 1.0);
	glPolygonStipple(random);
	glBegin(GL_POLYGON);
	glVertex2i(400, 400);
	glVertex2i(600, 450);
	glVertex2i(350, 300);
	glVertex2i(300, 460);
	glEnd();


	//////////////////////////////////////
	//Triangle
	//////////////////////////////////////
	glPolygonStipple(random);
	glBegin(GL_TRIANGLES);						//Start drawing Lines
	glColor3f(0.0, 0.0, 1.0);					//First vertex color is blue
	glVertex2i(100, 400);						//Draw vertex 1
	glColor3f(0.0, 1.0, 0.0);					//Second vertex color is green
	glVertex2i(50, 300);						//Draw vertex 2
	glColor3f(1.0, 0.0, 0.0);					//Third vertex color is red
	glVertex2i(150, 300);						//Draw vertex 3
	glEnd();									//Connect and end drawing



	////////////////////////////////////
	//Rectangle
	////////////////////////////////////
	glColor3f(0.0, 1.0, 0.0);					//Set background to Green
	glPolygonStipple(random);
	glRecti(200, 240, 400, 300);				//Show rectangle


	glFlush();
	glDisable(GL_POLYGON_STIPPLE);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100); 
	glutInitWindowSize(1080, 600);
	glutCreateWindow("Problem 1-a");
	init();
	glutDisplayFunc(twoSolidColorShapes);

	glutCreateWindow("Problem 1-b");
	init();
	glutDisplayFunc(twoMixColorShapes);

	glutCreateWindow("Problem 1-c");
	init();
	glutDisplayFunc(threeShapesWithMasks);


	glutMainLoop();
}