////////////////////////////////////////////////////////////////////
//			 Muhand Jumah, George Shafik, Anas Mutwakil
//					CSC 470 - Computer Graphics
//				Homework #1 - Problem 1 - Basic work
//	List of creativity
//	1. Menu and submenus
////////////////////////////////////////////////////////////////////
#include <GL\GLUT\glut.h>

/////////////////////////////////
//Prototypes
////////////////////////////////
void rightMenu(int);
void colorMenu(int);

void init(void)
{
	//Initialize the window
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 640.0, 0.0, 480);
}

void creativity(void) {
	glClear(GL_COLOR_BUFFER_BIT);				//Clear the window
	glFlush();
	glDisable(GL_POLYGON_STIPPLE);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(1080, 600);

	glutCreateWindow("Problem 1-creativity");
	init();

	//////////////////////////////////////
	//Create menu
	//////////////////////////////////////
	int cc_menu;
	cc_menu = glutCreateMenu(colorMenu);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);

	glutCreateMenu(rightMenu);
	glutAddSubMenu("Change Background Color to ", cc_menu);
	glutAddMenuEntry("Quit", 1);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(creativity);
	glutMainLoop();
}
void rightMenu(int id)
{
	if (id == 1)
		exit(0);
}
void colorMenu(int id)
{
	switch (id)
	{
	case 1:
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		break;
	case 2:
		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
		break;
	case 3:
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}