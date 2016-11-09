////////////////////////////////////////////////////////////////////
//						  Muhand Jumah
//					CSC 470 - Computer Graphics
//				Midterm - Question 9
////////////////////////////////////////////////////////////////////
#include <GL\GLUT\glut.h>

void init(void)
{
	//Initialize the window
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 640.0, 0.0, 480);
}

void draw(void) {
	glClear(GL_COLOR_BUFFER_BIT);				//Clear the window

	//GL_TRIANGLE_STRIP
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(100, 400); //vertex 1
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(50,300); //vertex 2
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(150,300); //vertex 3
	glColor3f(1.0, 0.0, 1.0);
	glVertex2i(100, 200); //vertex 4
	glEnd();

	//GL_QUAD_STRIP
	glBegin(GL_QUAD_STRIP);
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


	//GL_TRIANGLE_FAN
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(600, 400); //vertex 1
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(650, 450); //vertex 2
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(550, 350); //vertex 3
	glColor3f(1.0, 0.0, 1.0);
	glVertex2i(630, 200); //vertex 4
	glEnd();



	glFlush();									//View the shapes as quickly as possible
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(1080, 600);
	glutCreateWindow("Question 9");
	init();
	glutDisplayFunc(draw);

	glutMainLoop();
}