////////////////////////////////////////////////////////////////////
//							Muhand Jumah
//					CSC 470 - Computer Graphics
//					 Homework #3 - Problem 2
////////////////////////////////////////////////////////////////////
#include <ctime>
#include <Windows.h>
#include <GL/GLUT/glut.h>


double hand_and_feet_rotation = 0;
double hand_rotation = 0;
double floor_rotation = 0;
static int main_menu;
static int material_menu;
static int rotation_menu;
static int light_menu;
static bool rotating = true;

void setPolygon1()
{

	GLfloat mat_ambient[] = { 0.0f, 0.1f, 0.1f, 1.0f };
	GLfloat mat_diffuse[] = { 0.0f, 0.14f, 0.1f, 1.0f };

	int x;
	srand(time(0));
	x = rand() % 20 + 1;

	int y;
	srand(time(0));
	y = rand() % 25 + 1;
	int z;
	srand(time(0));
	z = rand() % 30 + 1;

	GLfloat mat_specular[] = { x,y,z,1.0f };
	GLfloat mat_shininess[] = { 5.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void drawPolygon()
{
	glPushMatrix();
	setPolygon1();
	glScalef(5, 1, 2);
	glTranslatef(0.0, -1.3, 0);
	glutSolidCube(1);
	glFlush();
	glPopMatrix();
}


void setMetalMaterial()
{
	GLfloat mat_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat mat_diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 0.5f };
	GLfloat mat_shininess[] = { 50.3f };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}
void setMaterialPlastic()
{
	GLfloat mat_ambient[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat mat_diffuse[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat mat_specular[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat mat_shininess[] = { 15.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}
void setLighting()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}


void setBall()
{
	GLfloat mat_ambient[] = { 0.0f, 0.1f, 0.1f, 1.0f };
	GLfloat mat_diffuse[] = { 0.0f, 0.14f, 0.1f, 1.0f };

	int x;
	srand(time(0));
	x = rand() % 5 + 1;
	
	int y;
	srand(time(0));
	y = rand() % 10 + 1;
	
	int z;
	srand(time(0));
	z = rand() % 15 + 1;

	GLfloat mat_specular[] = { x,y,z,1.0f };
	GLfloat mat_shininess[] = { 5.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void setBall1()
{
	GLfloat mat_ambient[] = { 0.0f, 0.1f, 0.1f, 1.0f };
	GLfloat mat_diffuse[] = { 0.0f, 0.14f, 0.1f, 1.0f };
	
	int x;
	srand(time(0)); 
	x = rand() % 20 + 1;

	int y;
	srand(time(0));
	y = rand() % 25 + 1;
	
	int z;
	srand(time(0));
	z = rand() % 30 + 1;

	GLfloat mat_specular[] = { x,y,z,1.0f };
	GLfloat mat_shininess[] = { 5.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	
}
void setBall2()
{
	GLfloat mat_ambient[] = { 0.0f, 0.1f, 0.1f, 1.0f };
	GLfloat mat_diffuse[] = { 0.0f, 0.14f, 0.1f, 1.0f };

	int x;
	srand(time(0)); 
	x = rand() % 35 + 1;

	int y;
	srand(time(0)); 
	y = rand() % 40 + 1;

	int z;
	srand(time(0));
	z = rand() % 45 + 1;

	GLfloat mat_specular[] = { x,y,z,1.0f };
	GLfloat mat_shininess[] = { 5.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}



void drawSphere()
{
	glutSolidSphere(.1, 16, 16);
}


void drawRightSideAppendages(double scaling, double x_diff, double y_diff, double z_diff)
{

	glPushMatrix(); // right arm
	glTranslatef((0.40f + x_diff)* scaling, (0.7f + y_diff)* scaling, (0.0f + z_diff)* scaling);
	glRotatef(hand_rotation, -1, 0, -1);
	glRotatef(hand_rotation, 0.3, 0.2, 0.5);
	glScalef(0.5f* scaling, 4.0f* scaling, 1.0f* scaling);
	drawSphere();
	glPopMatrix();

	glPushMatrix(); // right thigh
	glTranslatef((0.2f + x_diff)* scaling, (-0.4f + y_diff)* scaling, (0.0f + z_diff)* scaling);
	glRotatef(hand_and_feet_rotation, 0, 1, 0);
	glScalef(0.5f* scaling, 3.0f* scaling, 0.5f* scaling);
	drawSphere();
	glPopMatrix();



	glPushMatrix(); // right shin
	glTranslatef((0.3f + x_diff)* scaling, (-0.985f + y_diff)* scaling, (0.0f + z_diff)* scaling);
	glRotatef(hand_and_feet_rotation, 0, 1, 0);
	glScalef(0.7f* scaling, 3.0f* scaling, 0.5f* scaling);
	drawSphere();
	glPopMatrix();

	glPushMatrix(); // right foot
	glTranslatef((0.33f + x_diff)* scaling, (-1.40f + y_diff)* scaling, (0.0f + z_diff)* scaling);
	glRotatef(hand_and_feet_rotation, 1, 0, 1);
	glScalef(scaling, scaling, scaling);
	drawSphere();
	glPopMatrix();
}


void drawEyes(double scaling, double x_diff, double y_diff, double z_diff)
{
	//glPushMatrix(); // right arm
	//glTranslatef((0.40f + x_diff)* scaling, (0.7f + y_diff)* scaling, (0.0f + z_diff)* scaling);
	//glRotatef(hand_rotation, -1, 0, -1);
	//glRotatef(hand_rotation, 0.3, 0.2, 0.5);
	//glScalef(0.5f* scaling, 4.0f* scaling, 1.0f* scaling);
	//drawSphere();
	//glPopMatrix();
	GLfloat rx, ry, rz, lx, ly, lz;

	rx = (1.35 + x_diff)*scaling;
	ry = (2.15 + y_diff)*scaling;
	rz = (1.0f + z_diff)*scaling;
	lx = rx-0.17;
	ly = ry-0.045;
	lz = rz;

	glColor3d(1, 1, 1);
	glPushMatrix(); // right eye
	glTranslatef(rx, ry, rz);
	glScalef(0.5f*scaling, 0.5f*scaling, 0.5f*scaling);
	drawSphere();
	glPopMatrix();

	glColor3d(0, 0, 0);
	glPushMatrix(); // right eye
	glTranslatef((1.35f + x_diff)*scaling, (2.15 + y_diff)*scaling, (1.0f + z_diff)*scaling);
	glScalef(0.25f*scaling, 0.25f*scaling, 0.25f*scaling);
	drawSphere();
	glPopMatrix();

	glColor3d(1, 1, 1);
	glPushMatrix(); // right eye
	glTranslatef(lx, ly, lz);
	glScalef(0.5f*scaling, 0.5f*scaling, 0.5f*scaling);
	drawSphere();
	glPopMatrix();

	glColor3d(0, 0, 0);
	glPushMatrix(); // right eye
	glTranslatef(lx, ly, lz);
	glScalef(0.25f*scaling, 0.25f*scaling, 0.25f*scaling);
	drawSphere();
	glPopMatrix();

}

void drawNose(double scaling, double x_diff, double y_diff, double z_diff)
{
	GLfloat x, y, z;
	x = (1.14 + x_diff)*scaling;
	y = (2.0 + y_diff)*scaling;
	z = (1.0f + z_diff)*scaling;
	
	glColor3d(1, 0, 0);
	glPushMatrix(); // right eye
	glTranslatef(x, y, z);
	glScalef(0.5f*scaling, 0.5f*scaling, 0.5f*scaling);
	drawSphere();
	glPopMatrix();
}

void drawMouth(double scaling, double x_diff, double y_diff, double z_diff)
{
	GLfloat x, y, z;
	x = (1.14 + x_diff)*scaling;
	y = (1.85 + y_diff)*scaling;
	z = (1.0f + z_diff)*scaling;

	glColor3d(0, 0, 0);
	glPushMatrix(); // right eye
	glTranslatef(x, y, z);
	glScalef(0.8f*scaling, 0.3f*scaling, 0.5f*scaling);
	drawSphere();
	glPopMatrix();
}

double x1 = 0, y1 = 0, z1 = 0, w1 = 0;
void SpecialInput(int key, int x, int y)
{

	switch (key)
	{
	case GLUT_KEY_UP:
		y1 += 0.5;
		x1 += 0;
		w1 += -0.1;
		break;
	case GLUT_KEY_DOWN:
		y1 += -0.5;
		x1 += 0;
		w1 += 0.1;
		break;
	case GLUT_KEY_LEFT:
		x1 += 0;
		y1 += 0;
		z1 += 0.5;
		break;
	case GLUT_KEY_RIGHT:
		x1 += 0;
		y1 += 0;
		z1 += -0.5;
		break;
	}

}

void drawRobot(double scaling, double x_diff, double y_diff, double z_diff)
{

	glPushMatrix(); // head
	glTranslatef((0.0f + x_diff) * scaling, (1.5f + y_diff)* scaling, (0.0f + z_diff)* scaling);
	glScalef(3.0f* scaling, 3.0f* scaling, 3.0f* scaling);
	drawSphere();
	glPopMatrix();

	drawEyes(scaling, x_diff, y_diff, z_diff);
	drawNose(scaling, x_diff, y_diff, z_diff);
	drawMouth(scaling, x_diff, y_diff, z_diff);
	

	glPushMatrix(); // body
	glTranslatef((0.0f + x_diff)* scaling, (0.5f + y_diff)* scaling, (0.0f + z_diff)* scaling);
	glScalef(2.5f* scaling, 7.0f* scaling, 2.5f* scaling);
	drawSphere();
	glPopMatrix();

	drawRightSideAppendages(scaling, x_diff, y_diff, z_diff);

	// use reflection to draw the left side appendages
	glPushMatrix();
	glScalef(-1.0, 1.0, 1.0);
	drawRightSideAppendages(scaling, x_diff, y_diff, z_diff);
	glPopMatrix();

	glFlush();
}


void drawBall(double scaling, double x_diff, double y_diff, double z_diff)
{

	setBall();
	glPushMatrix();
	glTranslatef((0.0f + x_diff) * scaling, (2.0f + y_diff)* scaling, (0.0f + z_diff)* scaling);
	glScalef(3.0f* scaling, 3.0f* scaling, 3.0f* scaling);
	glRotatef(hand_and_feet_rotation, 0, 1, 0);
	drawSphere();
	glPopMatrix();

	setBall1();
	glPushMatrix();
	glTranslatef((0.0f + x_diff) * scaling, (2.0f + y_diff)* scaling, (0.0f + z_diff)* scaling);
	glScalef(3.0f* scaling, 3.0f* scaling, 3.0f* scaling);
	glRotatef(hand_and_feet_rotation, 1, 0, 0);
	drawSphere();
	glPopMatrix();

	setBall2();
	glPushMatrix();
	glTranslatef((0.0f + x_diff) * scaling, (2.0f + y_diff)* scaling, (0.0f + z_diff)* scaling);
	glScalef(3.0f* scaling, 3.0f* scaling, 3.0f* scaling);
	glRotatef(hand_and_feet_rotation, 0, 0, 1);
	drawSphere();
	glPopMatrix();
	glFlush();
	setMetalMaterial();
}
//Creating Menus
void menu(int num) {
	switch (num)
	{
	case(0):
	{
		break;
	}
	case(1):
	{
		setMetalMaterial();
		break;
	}
	case(2):
	{
		setMaterialPlastic();
		break;
	}
	case(3):
	{
		rotating = true;
		break;
	}
	case(4):
	{
		rotating = false;
		break;
	}
	case(5):
	{
		rotating = false;
		glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
		break;
	}
	case(6):
	{
		rotating = true;
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		break;
	}
	}
	glutPostRedisplay();
}
void createMenu(void) {
	material_menu = glutCreateMenu(menu);
	glutAddMenuEntry("Metal", 1);
	glutAddMenuEntry("Plastic", 2);

	rotation_menu = glutCreateMenu(menu);
	glutAddMenuEntry("On", 3);
	glutAddMenuEntry("Off", 4);

	light_menu = glutCreateMenu(menu);
	glutAddMenuEntry("Black", 6);
	glutAddMenuEntry("White", 5);

	main_menu = glutCreateMenu(menu);
	glutAddSubMenu("Material", material_menu);
	glutAddSubMenu("Rotation", rotation_menu);
	glutAddSubMenu("Backgounrd", light_menu);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void drawScene()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.3, 1.3, 2, 0, 0.25, 0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawPolygon();
	glutAttachMenu(GLUT_LEFT_BUTTON);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	drawRobot(.4 + w1, 0 + x1, 0 + y1, 0 + z1);
	drawRobot(.3, 2, -1, 0);
	drawRobot(.3, -2, -1, 0);
	drawRobot(.2, 4.5, -1, 0);
	drawRobot(.2, -4.5, -1, 0);

	glutSwapBuffers();
	glutPostRedisplay();
}

void idle()
{
	glutPostRedisplay();
}

void init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	GLfloat lightPosition[] = { 1.0f,1.0f,3.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	GLfloat lightIntensity[] = { 0.5f, 0.5f, 0.5f, 0.5f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
	glColor3f(1.0, 1.0, 1.0);
	rotating = false;
	setMetalMaterial();
	setLighting();
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glViewport(0, 0, GLUT_SCREEN_WIDTH, GLUT_SCREEN_HEIGHT);

}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(GLUT_SCREEN_WIDTH, GLUT_SCREEN_HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("HW3-2");
	glutReshapeWindow(1000, 800);
	
	
	glutDisplayFunc(drawPolygon);
	glutSpecialFunc(SpecialInput);
	glutDisplayFunc(drawScene);
	createMenu();
	
	
	
	init();
	glutMainLoop();
	return 1;
}



