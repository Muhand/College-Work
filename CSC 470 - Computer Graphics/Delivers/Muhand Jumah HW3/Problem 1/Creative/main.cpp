////////////////////////////////////////////////////////////////////
//							Muhand Jumah
//					CSC 470 - Computer Graphics
//				Homework #3 - Problem 1 - Creative Work
////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <Windows.h>
#include <GL/GL.h>
#include <GL/GLUT/glut.h>
#include <math.h>
#include <iostream>
#define DEGREES_TO_RADIANS 3.14159/180.0

static GLfloat spin = 0.0;
GLfloat x, y;


//{r, g, b, a}
const GLfloat light_ambient[] = { 0.4f, 0.4f, 0.4f, 1.0f };
const GLfloat light_diffuse[] = { 0.6f, 0.6f, 0.6f, 1.0f };
const GLfloat light_specular[] = { 0.2f, 0.2f, 0.2f, 1.0f };
const GLfloat light_position[] = { 5.0f, 5.0f, 5.0f, 0.0f };


const GLfloat mat_ambient[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_diffuse[] = { 0.2f, 0.2f, 0.2f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 50.0f };


static int main_menu;
static int shading_menu;
static int rotation_menu;
static int light_menu;
static bool handsRotating = true;
static bool feetRotating = true;
static bool robotRotating = false;
void drawSphere()
{
	glutSolidSphere(0.1, 16, 16);
}

void spinDisplay()
{
	spin = spin + 0.5;
	if (spin > 360.0) spin = spin - 360.0;
	x = 25.0*cos(DEGREES_TO_RADIANS * spin);
	y = 25.0*sin(DEGREES_TO_RADIANS * spin);

	glutPostRedisplay();
}

// Draws right arm, hand, leg, and foot
//
void drawRightSideAppendages()
{
	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix(); // right arm
	glTranslatef(0.40f, 0.7f, 0.0f);
	glRotatef(35, 0, 0, 1);
	glScalef(0.5f, 4.0f, 0.5f);
	drawSphere();
	glPopMatrix();

	glColor3d(1, 1, 1);
	glPushMatrix(); // right arm
	glTranslatef(0.35f, 0.8f, 0.5f);
	glRotatef(35, 0, 0, 1);
	glScalef(0.5f, 2.0f, 0.5f);
	drawSphere();
	glPopMatrix();


	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix(); // right hand
	glTranslatef(0.69f, 0.28f, 0.0f);
	if (handsRotating)
	{
		glRotatef(spin, 0, 0, 1);
	}
	drawSphere();
	glPopMatrix();

	glColor3d(0.2, 0.2, 1);
	glPushMatrix(); // right thigh
	glTranslatef(0.2f, -0.4f, 0.0f);
	glRotatef(15, 0, 0, 1);
	glScalef(0.5f, 3.0f, 0.5f);
	drawSphere();
	glPopMatrix();

	glColor3d(0.2, 0.2, 1);
	glPushMatrix(); // right shin
	glTranslatef(0.3f, -0.985f, 0.0f);
	glRotatef(6, 0, 0, 1);
	glScalef(0.5f, 3.0f, 0.5f);
	drawSphere();
	glPopMatrix();

	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix(); // right foot
	glTranslatef(0.33f, -1.40f, 0.0f);
	glRotatef(spin, 0, 0, 1);
	drawSphere();
	glPopMatrix();
}


void drawEyes()
{
	glColor3d(1, 1, 1);
	glPushMatrix(); // right eye
	glTranslatef(0.15f, 1.555f, 1.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	drawSphere();
	glPopMatrix();

	glColor3d(0, 0, 0);
	glPushMatrix();
	glTranslatef(0.15f, 1.555f, 2.0f);
	glScalef(0.25f, 0.25f, 0.25f);
	drawSphere();
	glPopMatrix();

	glColor3d(1, 1, 1);
	glPushMatrix(); // left eye
	glTranslatef(-0.15f, 1.555f, 1.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	drawSphere();
	glPopMatrix();

	glColor3d(0, 0, 0);
	glPushMatrix();
	glTranslatef(-0.15f, 1.555f, 2.0f);
	glScalef(0.25f, 0.25f, 0.25f);
	drawSphere();
	glPopMatrix();
}

void drawNose()
{
	glColor3d(1, 0, 0);
	glPushMatrix(); // right eye
	glTranslatef(0.0f, 1.46f, 1.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	drawSphere();
	glPopMatrix();
}

void drawMouth()
{
	glColor3d(0, 0, 0);
	glPushMatrix(); // right eye
	glTranslatef(0.0f, 1.3f, 2.0f);
	glScalef(0.7f, 0.3f, 0.5f);
	drawSphere();
	glPopMatrix();
}

void drawTshirtButtons()
{
	glColor3d(0, 0, 0);
	glPushMatrix(); // right eye
	glTranslatef(0.0f, 1.0f, 2.0f);
	glScalef(0.2f, 0.2f, 0.2f);
	drawSphere();
	glPopMatrix();

	glColor3d(0, 0, 0);
	glPushMatrix(); // right eye
	glTranslatef(0.0f, 0.8f, 2.0f);
	glScalef(0.2f, 0.2f, 0.2f);
	drawSphere();
	glPopMatrix();

	glColor3d(0, 0, 0);
	glPushMatrix(); // right eye
	glTranslatef(0.0f, 0.6f, 2.0f);
	glScalef(0.2f, 0.2f, 0.2f);
	drawSphere();
	glPopMatrix();


	glColor3d(0, 0, 0);
	glPushMatrix(); // right eye
	glTranslatef(0.0f, 0.4f, 2.0f);
	glScalef(0.2f, 0.2f, 0.2f);
	drawSphere();
	glPopMatrix();

	glColor3d(0, 0, 0);
	glPushMatrix(); // right eye
	glTranslatef(0.0f, 0.2f, 2.0f);
	glScalef(0.2f, 0.2f, 0.2f);
	drawSphere();
	glPopMatrix();

	glColor3d(0, 0, 0);
	glPushMatrix(); // right eye
	glTranslatef(0.0f, 0.0f, 2.0f);
	glScalef(0.2f, 0.2f, 0.2f);
	drawSphere();
	glPopMatrix();


}

void drawRobot()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	

	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix(); // head
	glTranslatef(0.0f, 1.5f, 0.0f);
	glScalef(3.0f, 3.0f, 3.0f);
	drawSphere();
	glPopMatrix();

	drawEyes();
	drawNose();
	drawMouth();
	drawTshirtButtons();

	glColor3d(1, 1, 1);
	glPushMatrix(); // body
	glTranslatef(0.0f, 0.5f, 1.0f);
	glScalef(3.5f, 7.0f, 2.5f);
	drawSphere();
	glPopMatrix();

	drawRightSideAppendages();

	//Use reflection to draw the left side appendages
	glPushMatrix();
	glScalef(-1.0, 1.0, 1.0);
	drawRightSideAppendages();
	glPopMatrix();
}

// MENU SYSTEM
void menu(int num) {
	switch (num)
	{
		case(0):
		{
			break;
		}
		case(1):
		{
			//Flat shading
			glShadeModel(GL_FLAT);
			break;
		}
		case(2):
		{
			//Smooth shading
			glShadeModel(GL_SMOOTH);
			break;
		}
		case(3):
		{
			handsRotating = true;
			break;
		}
		case(4):
		{
			handsRotating = false;
			break;
		}
		case(5):
		{
			feetRotating = true;
			//glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
			break;
		}
		case(6):
		{
			feetRotating = false;
			break;
		}
		case(7):
		{
			robotRotating = true;
			break;
		}
		case(8):
		{
			robotRotating = false;
			break;
		}
		case(9):
		{
			/*glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LESS);*/

			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);
			glEnable(GL_NORMALIZE);
			glEnable(GL_COLOR_MATERIAL);
			break;
		}
		case(10):
		{
			/*glDisable(GL_DEPTH_TEST);
*/
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT0);
			glDisable(GL_NORMALIZE);
			glDisable(GL_COLOR_MATERIAL);
			break;
		}

	}
}
void createMenu(void) {
	
	shading_menu = glutCreateMenu(menu);
	glutAddMenuEntry("Flat", 1);
	glutAddMenuEntry("Smooth", 2);

	rotation_menu = glutCreateMenu(menu);
	glutAddMenuEntry("Hands Rotation On", 3);
	glutAddMenuEntry("Hands Rotation Off", 4);
	glutAddMenuEntry("Foot Rotation On", 5);
	glutAddMenuEntry("Foot Rotation Off", 6);
	glutAddMenuEntry("Whole Robot Rotation On", 7);
	glutAddMenuEntry("Whole Robot Rotation Off", 8);


	light_menu = glutCreateMenu(menu);
	glutAddMenuEntry("On", 9);
	glutAddMenuEntry("Off", 10);

	main_menu = glutCreateMenu(menu);
	glutAddSubMenu("Shading", shading_menu);
	glutAddSubMenu("Rotation", rotation_menu);
	glutAddSubMenu("Light", light_menu);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void init()
{
	glColor3d(0.9, 0.5, 0.9);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION); // set the view volume shape
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW); // position and aim the camera
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	



	glFlush();
}

void display()
{
	glClearColor(0.7, 0.7, 0.7, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	

	drawRobot();
	if(robotRotating)
	{
		glRotatef(spin, 0, 0, 1);
	}
	glFlush();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 640);
	glutCreateWindow("HW3 - Problem 1 - Basic");

	createMenu();
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	init();
	glutDisplayFunc(display);
	glutIdleFunc(spinDisplay);

	glutMainLoop();
}

