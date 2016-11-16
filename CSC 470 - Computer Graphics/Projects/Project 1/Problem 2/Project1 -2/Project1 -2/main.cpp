#include <windows.h>
#include <GL/GLUT/glut.h>

static bool rotating = true;
double teapot_rotation = 0;
double light_rotation = 0;
GLfloat r = 0.0f, g = 1.0f, b = 0.0f;

void setMaterial()
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

void drawTeapot(double y)
{
	double x = -5000;
	for (int i = 0; i < 1; i++)
	{

		for (int j = 0; j < 8; j++)
		{
			glPushMatrix();
			glScalef(0.1, 0.1, 0.1);
			glTranslatef(x, y, 0);
			glRotatef(-45, 0, -1, 0);
			glRotatef(-45, 1, 0, 0);
			glRotatef(teapot_rotation, 1, -1, 0);


			r = (1.0 / 8.0)*(j + 1);

			setMaterial();

			glutSolidTeapot(300);

			glPopMatrix();
			x += 1200;
			y += 600;
		}

		x -= (1200 * 8);
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

	glPushMatrix();
	glTranslatef(-5000, 2000, 0);
	glRotatef(light_rotation, 0, 1, 0);
	GLfloat lightPosition[] = { 0.0f,0.0f,100.0f, 0.0f };
	GLfloat lightIntensity[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
	glPopMatrix();



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
	
	double y = 2000;
	for(double i = 0, j = 8; i < 8; i++, j--)
	{
		setRGB(0, j/8.0,i/8.0);
		drawTeapot(y);
		y -= 900;
	}

	if (rotating)
	{
		teapot_rotation += 10.0;
		light_rotation += 10.0;
	}
	glutSwapBuffers();
	glutPostRedisplay();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Teapots");
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

