////////////////////////////////////////////////////////////////////
//							Muhand Jumah
//					CSC 470 - Computer Graphics
//					  Project #1 - Problem #1
////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <GL/GLUT/glut.h>

//Masks
GLubyte random[] = {
	0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,
	0xFF,  0xFF,  0xC0,  0x20,  0x01,  0x01,  0xFF,  0xFF,
	0xFF,  0xFF,  0xC0,  0x20,  0x01,  0x01,  0xFF,  0xFF,
	0xFF,  0xFF,  0xC0,  0x20,  0x01,  0x01,  0xFF,  0xFF,
	0x00,  0x00,  0x40,  0x20,  0x01,  0x01,  0x00,  0x00,
	0x00,  0x00,  0x40,  0x20,  0x01,  0x01,  0x00,  0x00,
	0x00,  0x00,  0x40,  0x20,  0x01,  0x01,  0x00,  0x00,
	0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,
	0x00,  0x00,  0x40,  0x20,  0x01,  0x01,  0x00,  0x00,
	0x00,  0x00,  0x40,  0x20,  0x01,  0x01,  0x00,  0x00,
	0x00,  0x00,  0x40,  0x20,  0x01,  0x01,  0x00,  0x00,
	0xFF,  0xFF,  0xC0,  0x20,  0x01,  0x01,  0xFF,  0xFF,
	0xFF,  0xFF,  0xC0,  0x20,  0x01,  0x01,  0xFF,  0xFF,
	0xFF,  0xFF,  0xC0,  0x20,  0x01,  0x01,  0xFF,  0xFF,
	0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,
	0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00
};

GLubyte Bricks[] = {
	0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,
	0x81,  0x00,  0x60,  0x08,  0x04,  0x00,  0x08,  0x01,
	0x81,  0x00,  0xC0,  0x08,  0x04,  0x00,  0x08,  0x01,
	0x81,  0x00,  0x00,  0x08,  0x04,  0x00,  0x08,  0x01,
	0x81,  0x00,  0x00,  0x08,  0x04,  0x00,  0x08,  0x01,
	0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,
	0x80,  0x40,  0x04,  0x00,  0x40,  0x08,  0x08,  0x09,
	0x80,  0x60,  0x04,  0x00,  0x20,  0x08,  0x04,  0x09,
	0x80,  0x20,  0x04,  0x00,  0x10,  0x08,  0x02,  0x09,
	0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,
	0x80,  0x02,  0x00,  0x20,  0x10,  0x01,  0x01,  0x01,
	0x80,  0x02,  0x00,  0x08,  0x10,  0x02,  0x01,  0x01,
	0x80,  0x02,  0x00,  0x02,  0x10,  0x04,  0x01,  0x01,
	0x80,  0x02,  0x00,  0x01,  0x10,  0x08,  0x01,  0x01,
	0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,
	0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00
};
//Global Variables
static bool rotating = true;
static bool day = true;
double tire_rotate_v = 0;
double tree_rotate_v = 0;
float rtri = 0.0f;
float rtri1 = 0.0f;
int rotation_stopper = 0;

//Menus
static int mMenu;
static int day_menu;
static int animation_menu;

//Prototypes
void roofMaterial();
void houseMaterial();
void dayNight(bool isDay);
void carMaterial();
void treeTop();
void treeStick();
void metalMaterial();
void chimneyMaterial();
void createMenu();
void menu(int num);

void display() {
	//Background
	glPushMatrix();
	glScalef(3.0, 0.5, 3.0);
	glTranslatef(-1, -3.5, -1.2);
	glRotatef(-45, 0, 1, 0);
	glutSolidCube(1);
	glPopMatrix();

	// house
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(Bricks);
	glPushMatrix();
	metalMaterial();
	glScalef(0.35, 0.5, 0.35);
	glTranslatef(0.0, 0, -0.8);
	glutSolidCube(2);
	glPopMatrix();
	glDisable(GL_POLYGON_STIPPLE);

	glPushMatrix();
	houseMaterial();
	glScalef(0.35, 0.5, 0.35);
	glTranslatef(0.0, 0, -0.8);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.35, 0.5, 0.35);
	glTranslatef(0.0, 0, -0.8);
	glutSolidCube(2);
	glPopMatrix();

	// roof
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(random);
	glPushMatrix();
	metalMaterial();
	glScalef(0.35, 0.50, 0.35);
	glTranslatef(0.5, 1.2, -0.3);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(1.5, 1, 16, 8);
	glPopMatrix();
	glDisable(GL_POLYGON_STIPPLE);

	glPushMatrix();
	roofMaterial();
	glScalef(0.35, 0.50, 0.35);
	glTranslatef(0.5, 1.2, -0.3);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(1.5, 1, 16, 8);
	glPopMatrix();
	
	// chimney
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(Bricks);
	glPushMatrix();
	metalMaterial();
	glScalef(0.35, 1.0, 0.35);
	glTranslatef(1.0, 0.8, -1.3);
	glutSolidCube(0.25);
	glPopMatrix();
	glDisable(GL_POLYGON_STIPPLE);

	glPushMatrix();
	chimneyMaterial();
	glScalef(0.35, 1.0, 0.35);
	glTranslatef(1.0, 0.8, -1.3);
	glutSolidCube(0.25);
	glPopMatrix();

	treeStick();
	glPushMatrix();
	glScalef(0.35, 1.0, 0.01);
	glTranslatef(-0.0, -0.2, 10.0);
	glutSolidCube(0.5);
	glPopMatrix();

	//Tree
	treeTop();
	glPushMatrix();
	glScalef(0.15, 0.30, 0.15);
	glTranslatef(-6.0, 0.2, -0.9);
	glRotatef(-90, 1, 0, 0);
	glRotatef(tree_rotate_v, 0, 0, -1);
	glutSolidCone(1.7, 1, 16, 8);
	glPopMatrix();

	treeStick();
	glPushMatrix();
	glScalef(0.15, 0.80, 0.15);
	glTranslatef(-6, -0.4, -1.0);
	glutSolidCube(0.60);
	glPopMatrix();


	//Tree
	treeTop();
	glPushMatrix();
	glScalef(0.15, 0.30, 0.15);
	glTranslatef(-8.0, 1.2, -0.9);
	glRotatef(-90, 1, 0, 0);
	glRotatef(tree_rotate_v, 0, 0, -1);
	glutSolidCone(1.7, 1, 16, 8);
	glPopMatrix();

	treeStick();
	glPushMatrix();
	glScalef(0.15, 1.6, 0.15);
	glTranslatef(-8, 0.0, -1.0);
	glutSolidCube(0.60);
	glPopMatrix();


	//Tree
	treeTop();
	glPushMatrix();
	glScalef(0.10, 0.25, 0.10);
	glTranslatef(11, 2.0, -0.9);
	glRotatef(-90, 1, 0, 0);
	glRotatef(tree_rotate_v, 0, 0, -1);
	glutSolidCone(1.7, 1, 16, 8);
	glPopMatrix();

	treeStick();
	glPushMatrix();
	glScalef(0.10, 1.1, 0.10);
	glTranslatef(11, 0.2, -1.0);
	glutSolidCube(0.60);
	glPopMatrix();
	//Car
	//Body
	if (rtri1 > 0.5)
	{
		rtri1 = -1;
	}
	if (rtri > 0.9)
	{
		rtri = -1.85;
	}

	carMaterial();
	glPushMatrix();
	glScalef(0.65, 0.25, 0.40);
	glTranslatef(rtri1 + 0.7, -0.3f, 2.5f);
	glutSolidCube(0.5);
	glPopMatrix();

	//Black Box
	metalMaterial();
	glPushMatrix();
	glScalef(0.35, 0.15, 0.20);
	glTranslatef(rtri + 1.3, -0.2f, 5.0f);
	glutSolidCube(0.5);
	glPopMatrix();

	//Front Right Wheel
	houseMaterial();
	glPushMatrix();
	glScalef(0.35, 0.35, 0.35);
	glTranslatef(rtri + 2.0, -0.1, 3.5);
	glRotatef(tire_rotate_v, 0, 0, -1);
	glutSolidTorus(.05, .1, 8, 8);
	glPopMatrix();

	//Back Right Wheel
	glPushMatrix();
	glScalef(0.35, 0.35, 0.35);
	glTranslatef(rtri + 1.2, -.1, 3.5);
	glRotatef(tire_rotate_v, 0, 0, -1);
	glutSolidTorus(.05, .1, 8, 8);
	glPopMatrix();

	//Front Left Wheel
	glPushMatrix();
	glScalef(0.35, 0.35, 0.35);
	glTranslatef(rtri + 0.7, -1.4, 1.5);
	glRotatef(tire_rotate_v, 0, 0, -1);
	glutSolidTorus(.05, .1, 8, 8);
	glPopMatrix();

	//rotation_stopper = 5;
	if (rotation_stopper == 0)
	{
		rtri += 0.001f;                    // Increase The Rotation Variable For The Cube

		if (rtri > 2)
		{
			rtri = -2.0f;
		}

		rtri1 += 0.000545f;                    // Increase The Rotation Variable For The Cube

		if (rtri1 > 2)
		{
			rtri1 = -2.0f;
		}
	}

	/* flush drawing routines to the window */
	glFlush();
	glPopMatrix();
}
void reshape() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(4.0, 4.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	display();
	glutAttachMenu(GLUT_LEFT_BUTTON);

	if (day)
		dayNight(true);
	else
		dayNight(false);

	if (rotating)
	{
		tire_rotate_v += 0.20;
		tree_rotate_v += 0.15;
	}
	glutSwapBuffers();
	glutPostRedisplay();
}
void setLighting()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}
void init()
{

	GLfloat lightPosition[] = { 1.0f,1.0f,3.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	GLfloat lightIntensity[] = { 0.5f, 0.5f, 0.5f, 0.5f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}


int main(int argc, char * argv[]) {

	///* initialize GLUT, using any commandline parameters passed to the
	//program */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(GLUT_SCREEN_WIDTH, GLUT_SCREEN_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Project1 - 1");
	glutReshapeWindow(1000, 800);
	glColor3f(1.0, 0.0, 0.0);
	day = true;
	setLighting();
	glutDisplayFunc(display);
	glutDisplayFunc(reshape);
	createMenu();
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glClearColor(0.0f, 0.6f, 0.1f, 1.0f);
	glViewport(0, 0, GLUT_SCREEN_WIDTH, GLUT_SCREEN_HEIGHT);
	init();
	glutMainLoop();
	return 0;
}
void metalMaterial()
{
	GLfloat mat_ambient[] = { 0.0f, 0.0f, 0.0f,0.0f };
	GLfloat mat_diffuse[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	GLfloat mat_specular[] = { 0.0,0.0,0.0,0 };
	GLfloat mat_shininess[] = { 1.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}
void roofMaterial()
{
	GLfloat mat_ambient[] = { 0.0f, 0.0f, 0.0f,0.0f };
	GLfloat mat_diffuse[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	GLfloat mat_specular[] = { 0.000, 0.749, 1.000,0 };
	GLfloat mat_shininess[] = { 1.5f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void houseMaterial()
{
	GLfloat mat_ambient[] = { 0.0f, 0.0f, 0.0f,0.0f };
	GLfloat mat_diffuse[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	GLfloat mat_specular[] = { 0.000, 0.749, 1.000,0 };
	GLfloat mat_shininess[] = { 1.5f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}
void dayNight(bool isDay)
{
	if (!isDay)
	{
		GLfloat mat_ambient[] = { 0.0f, 0.0f, 0.0f,0.0f };
		GLfloat mat_diffuse[] = { 0.0f, 0.0f, 0.0f, 0.0f };
		GLfloat mat_specular[] = { 0.282, 0.239, 0.545,0 };
		GLfloat mat_shininess[] = { 1.9f };
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	}
	else
	{
		GLfloat mat_ambient[] = { 0.0f, 0.0f, 0.0f,0.0f };
		GLfloat mat_diffuse[] = { 0.0f, 0.0f, 0.0f, 0.0f };
		GLfloat mat_specular[] = { 0.0,1.0,1.0,0 };
		GLfloat mat_shininess[] = { 1.0f };
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	}
}

void carMaterial()
{
	GLfloat mat_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat mat_diffuse[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat mat_specular[] = { 1, 0.0, 0.0,1.0 };
	GLfloat mat_shininess[] = { 1.5f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}
void treeTop()
{
	GLfloat mat_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat mat_diffuse[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat mat_specular[] = { 0.196, 0.804, 0.196,1.0 };
	GLfloat mat_shininess[] = { 0.7f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void treeStick()
{
	GLfloat mat_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat mat_diffuse[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat mat_specular[] = { 0.627, 0.322, 0.176,1.0 };
	GLfloat mat_shininess[] = { 0.7f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}
void chimneyMaterial()
{
	GLfloat mat_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat mat_diffuse[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat mat_specular[] = { 1, 0.0, 0.0,1.0 };
	GLfloat mat_shininess[] = { 1.5f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void menu(int num) {
	switch (num)
	{
		case(0):
		{
			break;
		}
		case(1):
		{
			day = true;
			break;
		}
		case(2):
		{
			day = false;
			break;
		}
		case(3):
		{
			rotating = true;
			rotation_stopper = 0;
			break;
		}
		case(4):
		{
			rotating = false;
			rotation_stopper = 5;
			break;
		}
	}
}
void createMenu(void) {
	day_menu = glutCreateMenu(menu);
	glutAddMenuEntry("Day", 1);
	glutAddMenuEntry("Night", 2);

	animation_menu = glutCreateMenu(menu);
	glutAddMenuEntry("On", 3);
	glutAddMenuEntry("Off", 4);

	mMenu = glutCreateMenu(menu);
	glutAddSubMenu("Day", day_menu);
	glutAddSubMenu("Animation", animation_menu);



	glutAttachMenu(GLUT_LEFT_BUTTON);
}