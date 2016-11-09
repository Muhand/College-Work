//George Shafik
//Question 9
#include <GL\GLUT\glut.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 640.0, 0.0, 480);
}
void quad(void)
{
	glClear(GL_COLOR_BUFFER_BIT);				

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

	glFlush();
}
void fan(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(600, 400); 
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(650, 450);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(550, 350);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2i(630, 200); 
	glEnd();

	glFlush();
}
void strip(void) {
	glClear(GL_COLOR_BUFFER_BIT);				

	
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(100, 400); 
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(50,300); 
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(150,300); 
	glColor3f(1.0, 0.0, 1.0);
	glVertex2i(100, 200);
	glEnd();

	glFlush();									
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(1080, 600);
	
	glutCreateWindow("quad");
	init();
	glutDisplayFunc(fan);
	
	glutCreateWindow("fan");
	init();
	glutDisplayFunc(quad);

	glutCreateWindow("strip");
	init();
	glutDisplayFunc(strip);

	glutMainLoop();
}