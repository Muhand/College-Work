#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/GLU.h>
#include <iostream>

#define TRI_TRIANGLE 1
#define PENTA_TRIANGLE 2
#define STAR  3
#define PENTA_STAR 4

int screenW = 600, screenH = 600;
double size = 1;
GLfloat r = 1.0, g = 0.0, b = 0.0; /* drawing color */
int draw_mode = 0;


void color_menu(int id);
void right_menu(int id);
void menu_Backgriund();
void renderer();
void penta_star(int x, int y);
void star_Line(int x, int y);
void penta_Triangle(int x, int y);
void tripple_Triangle(int x, int y);

int pick(int x, int y)
{
	if (y < 100 && x <= 90)
	{
		return TRI_TRIANGLE;
	}
	else if (y < 100 && x <= 175)
	{
		return PENTA_TRIANGLE;
	}
	else if (y < 100 && x <= 270)
	{
		return STAR;
	}
	else if(y < 100 && x>270 && x < 370)
	{
		return PENTA_STAR;
	}
	else return 0;
	
}

void right_menu(int id)
{
	if (id == 1) exit(0);
	else if (id == 2)
	{
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
		renderer();
	}
	else renderer();
}

void color_menu(int id)
{
	if (id == 1) { r = 1.0; g = 0.0; b = 0.0; }
	else if (id == 2) { r = 0.0; g = 1.0; b = 0.0; }
	else if (id == 3) { r = 0.0; g = 0.0; b = 1.0; }
	else if (id == 4) { r = 0.0; g = 1.0; b = 1.0; }
	else if (id == 5) { r = 1.0; g = 0.0; b = 1.0; }
	else if (id == 6) { r = 1.0; g = 1.0; b = 0.0; }
	else if (id == 7) { r = 1.0; g = 1.0; b = 1.0; }
	else if (id == 8) { r = 0.0; g = 0.0; b = 0.0; }
}

void menu_Backgriund()
{
	glColor3f(0.0f, 0.6f, 0.8f);
	glBegin(GL_POLYGON);
	glVertex3i(0, 0, 0);
	glVertex3i(0, 100, 0);
	glVertex3i(370, 100, 0);
	glVertex3i(370, 0, 0);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex3i(0, 0, 0);
	glVertex3i(0, 100, 0);
	glVertex3i(370, 100, 0);
	glVertex3i(370, 0, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(90, 0, 0);
	glVertex3i(90, 100, 0);
	glVertex3i(175, 0, 0);
	glVertex3i(175, 100, 0);
	glVertex3i(270, 0, 0);
	glVertex3i(270, 100, 0);
	glEnd();
}

void penta_star(int x, int y)
{
	const float PI = 3.141592654;
	float x_coord, y_coord;
	float radius = 10.0f;

	glBegin(GL_TRIANGLES);
	glVertex2i(x - 5, y + 7);
	glVertex2i(x + 5, y + 7);
	glVertex2i(x, y + 40);

	glVertex2i(x + 5, y + 8);
	glVertex2i(x + 7, y - 3);
	glVertex2i(x + 35, y + 20);

	glVertex2i(x + 7, y);
	glVertex2i(x + 3, y - 10);
	glVertex2i(x + 35, y - 25);

	glVertex2i(x - 5, y - 7);
	glVertex2i(x + 5, y - 7);
	glVertex2i(x, y - 40);

	glVertex2i(x - 7, y);
	glVertex2i(x - 3, y - 10);
	glVertex2i(x - 35, y - 25);

	glVertex2i(x - 5, y + 8);
	glVertex2i(x - 7, y - 3);
	glVertex2i(x - 35, y + 20);

	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(x, y + 40);
	glVertex2i(x + 35, y + 20);

	glVertex2i(x + 35, y - 25);
	glVertex2i(x, y - 40);

	glVertex2i(x - 35, y - 25);
	glVertex2i(x - 35, y + 20);
	glEnd();


	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle <= 360; angle += 1.0f)
	{
		float rad = PI * angle / 180;
		x_coord = (float)x + radius*cos(rad);
		y_coord = (float)y + radius*sin(rad);
		glVertex3i(x_coord, y_coord, 0.0f);
	}
	glEnd();

	glColor3f(r, g, b);

	
	glFlush();
}

void star_Line(int x, int y)
{
	glBegin(GL_LINE_LOOP);

	glVertex2i(x, y + 5);
	glVertex2i(x + 20, y +30);

	glVertex2i(x + 10, y + 3);
	glVertex2i(x+35, y + 3);

	glVertex2i(x + 10, y - 7);
	glVertex2i(x + 35, y -25);

	glVertex2i(x + 5, y - 15);
	glVertex2i(x, y - 45);

	glVertex2i(x - 5, y - 15);
	glVertex2i(x - 35, y - 25);

	glVertex2i(x - 10, y - 7);
	glVertex2i(x - 35, y + 3);
	glVertex2i(x - 10, y + 3);

	glVertex2i(x - 20, y + 30);
	glVertex2i(x, y + 5);

	glEnd();
	glFlush();
}

void penta_Triangle(int x, int y)
{
	glBegin(GL_TRIANGLES);
	///First Triangle is the bottom one
	///All other triangles going counter clock-wise
	glVertex2i(x - 20, y + 30);
	glVertex2i(x + 20, y + 30);
	glVertex2i(x, y + 5);

	glVertex2i(x + 20, y + 30);
	glVertex2i(x + 30, y - 10);
	glVertex2i(x + 7, y);

	glVertex2i(x + 30, y - 10);
	glVertex2i(x, y - 40);
	glVertex2i(x +5, y - 10);

	glVertex2i(x, y - 40);
	glVertex2i(x - 30, y - 10);
	glVertex2i(x-5, y - 10);

	glVertex2i(x - 20, y + 30);
	glVertex2i(x - 30, y - 10);
	glVertex2i(x - 5, y);

	glEnd();
	glFlush();
}

void tripple_Triangle(int x, int y)
{
	glBegin(GL_TRIANGLES);
	glVertex2i(x - 33, y + 30);
	glVertex2i(x, y + 14);
	glVertex2i(x + 33, y + 30);


	glVertex2i(x + 33, y + 30);
	glVertex2i(x + 3, y + 5);
	glVertex2i(x, y - 30);

	glVertex2i(x, y - 30);
	glVertex2i(x - 3, y + 5);
	glVertex2i(x - 33, y + 30);
	glEnd();
	glFlush();
}

void intitialize()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	gluOrtho2D(0, screenW, screenH, 0);
	
	r = 1.0f;
	glFlush();

}

void mouse(int m_button, int state, int x, int y)
{
	glColor3f(r, g, b);
	int where;

	if (m_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		where = pick(x, y);
		if (where != 0)
		{
			draw_mode = where;
		}
		else switch (draw_mode)
		{
		case(TRI_TRIANGLE):
				tripple_Triangle(x, y);
				break;
		case(PENTA_TRIANGLE):
			penta_Triangle(x, y);
			break;
		case(STAR):
			star_Line(x, y);
			break;
		case(PENTA_STAR):
			penta_star(x, y);
			break;
		}
	}
}

void renderer()
{
	menu_Backgriund();
	glColor3f(1.0f, 0.0f, 0.0f);
	tripple_Triangle(45, 55);
	penta_Triangle(130, 55);
	star_Line(220, 55);
	penta_star(320, 55);
	glFlush();
	glColor3f(r, g, b);
}

void menu(int){}

int main(int argc, char** argv)
{
	int color_m, file;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Lab1 Part 3");
	glutDisplayFunc(renderer);
	
	color_m = glutCreateMenu(color_menu);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	glutAddMenuEntry("Cyan", 4);
	glutAddMenuEntry("Magenta", 5);
	glutAddMenuEntry("Yellow", 6);
	glutAddMenuEntry("White", 7);
	glutAddMenuEntry("Black", 8);

	file = glutCreateMenu(right_menu);
	glutAddMenuEntry("clear", 2);
	glutAddMenuEntry("quit", 1);

	glutCreateMenu(menu);
	glutAddSubMenu("menu", file);
	glutAddSubMenu("Colors", color_m);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	intitialize();

	glutMouseFunc(mouse);

	glutMainLoop();

}