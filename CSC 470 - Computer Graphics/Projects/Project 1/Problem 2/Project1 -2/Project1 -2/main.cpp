//#include <GL/GLU.h>
//#include <GL/GLUT/glut.h>
//#include <math.h>
//#define W 600
//#define H 600
//void displaySolid(void)
//{
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-W, W, -H, H, -W, W);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(0, 0, 10, 0, 0, 0, 0.0, 1.0, 0.0);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glutSolidTeapot(300);
//	glFlush();
//	glutSwapBuffers();
//}
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(W, H);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("My Teapot");
//	glutDisplayFunc(displaySolid);
//	glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
//	glViewport(0, 0, W, H);
//	glutMainLoop();
//	return 1;
//}
////Turning on the lights code to be placed WHERE ? ? ?
////glEnable(GL_LIGHTING);
////glEnable(GL_LIGHT0);
////glShadeModel(GL_SMOOTH);
////glEnable(GL_DEPTH_TEST);
////glEnable(GL_NORMALIZE);
////Direction / intensity of the light.
////GLfloat lightPosition[] = { 0.0f,0.0f,100.0f, 0.0f };
////GLfloat lightIntensity[] = { 0.9f, 0.9f, 0.9f, 1.0f };
////glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
////glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
////Add ambient light.
////Materials.
////GLfloat mat_ambient[] = { 0.5f, 0.5f, 0.6f, 1.0f };
////GLfloat mat_diffuse[] = { 0.6f, 0.6f, 0.6f, 1.0f };
////GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
////GLfloat mat_shininess[] = { 90.0f };
////glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
////glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
////7
////glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
////glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
////glutSolidTeapot(300);
////GLfloat mat_ambient1[] = { 0.5f, 0.5f, 0.6f, 1.0f };
////GLfloat mat_diffuse1[] = { 0.6f, 0.6f, 0.6f, 1.0f };
////GLfloat mat_specular1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
////GLfloat mat_shininess1[] = { 90.0f };
////glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);
////glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
////glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
////glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);
////glutSolidSphere(50, 20, 20);

#include <windows.h>
#include <GL/GLUT/glut.h>

#include <math.h>

static bool rotating = true;
double teapot_rotation = 0;
GLfloat r = 0.0f, g = 1.0f, b = 0.0f;
void setMaterialTeapot()
{
	GLfloat mat_ambient[] = { 0.5f, 0.5f, 0.6f, 1.0f };
	GLfloat mat_diffuse[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat mat_shininess[] = { 90.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}
//
void setMaterialTeapot1()
{
	int x1;
	x1 = rand() % 20 + 1;
	int y1;
	y1 = rand() % 25 + 1;
	int z1;
	z1 = rand() % 30 + 1;

	GLfloat mat_specular[] = { x1, y1, z1, 10.0f };
	GLfloat mat_shininess[] = { 20.0f };
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}
void setMaterialRed()
{
	GLfloat mat_ambient[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat mat_diffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat mat_shininess[] = { 90.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}
void setMaterialRed1()
{
	GLfloat mat_ambient[] = { r, g, b, 1.0f };
	GLfloat mat_diffuse[] = { r, g, b, 1.0f };
	GLfloat mat_specular[] = { r, g, b, 1.0f };
	GLfloat mat_shininess[] = { 90.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}
void drawSphere()
{
	glutSolidSphere(50, 20, 20);
}
void setRGB(GLfloat R, GLfloat G, GLfloat B)
{
	r = R;
	g = G;
	b = B;
}
void drawTeapot()
{
	//setMaterialTeapot();
	
	double x = -5000, y = 2000;
	for (int i = 0; i < 8; i++)
	{

		for (int j = 0; j < 8; j++)
		{
			glPushMatrix();
			glScalef(0.1, 0.1, 0.1);
			glTranslatef(x, y, 0);
			glRotatef(-45, 0, -1, 0);
			glRotatef(-45, 1, 0, 0);
			glRotatef(teapot_rotation, 1, -1, 0);
			
			setMaterialRed1();
			r = (1.0 / 8.0)*(j + 1);
		
			
			glutSolidTeapot(300);

			if(j == 7)
			{
			/*	r = 0;
				g = g - ((1.0 / 8.0)*(i + 1));
				b = b + ((1.0 / 8.0)*(i + 1));*/
			}
			glPopMatrix();
			x += 1200;
			y += 600;
		}
		x -= (1200 * 8);
		y -= (600 * 9) + 300;
		
		////g -= 0.1;
	
		////setRGB(r, g-((1.0/8.0)*(i+1)), b + ((1.0 / 8.0)*(i+1)));
		//setMaterialRed1();
	}
	glEnable(GL_NORMALIZE);
	glFlush();
	glPopMatrix();
}

void drawTeapot1()
{
	double x = -5000, y = 2000;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			glPushMatrix();
			setMaterialTeapot1();
			glEnable(GL_BLEND);
			glScalef(0.1, 0.1, 0.1);
			glTranslatef(x, y, 0.1);
			glRotatef(-45, 0, -1, 0);
			glRotatef(-45, 1, 0, 0);
			glRotatef(teapot_rotation, 1, -1, 0);
			glutSolidTeapot(300);
			glPopMatrix();
			x += 1200;
			y += 600;
		}
		x -= (1200 * 8);
		y -= (600 * 9) + 300;
	}
	glEnable(GL_NORMALIZE);
	glFlush();
	glPopMatrix();
}
void setLighting()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}



void init()
{
	GLfloat lightPosition[] = { 0.0f,0.0f,100.0f, 0.0f };
	GLfloat lightIntensity[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

}

void displaySolid(void)
{

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-600, 600, -600, 600, -600, 600.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawTeapot();
	//drawTeapot1();

	//setMaterialRed();
	//glutSolidTeapot(100);
	if (rotating)
		teapot_rotation += 10.0;
	glutSwapBuffers();
	glutPostRedisplay();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My Teapot");
	setLighting();
	rotating = true;
	glutDisplayFunc(displaySolid);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
	glViewport(0, 0, 600, 600);
	init();
	glutMainLoop();
	return 1;
}

