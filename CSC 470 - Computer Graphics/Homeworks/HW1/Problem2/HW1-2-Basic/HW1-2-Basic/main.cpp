////////////////////////////////////////////////////////////////////
//			 Muhand Jumah, George Shafik, Anas Mutwakil
//					CSC 470 - Computer Graphics
//					Homework #1 - Basic work
////////////////////////////////////////////////////////////////////
#include<GL\GLUT\glut.h>
#include<math.h>

///////////////////////////////////
//Global Masks
///////////////////////////////////
GLubyte lineMask[] = {
	0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
	0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
	0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,
	0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
	0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,
	0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
	0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
	0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
	0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,
	0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
	0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
	0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
	0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,  0xFF,
	0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
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

////////////////////////////////////
//Structs
////////////////////////////////////
struct Point
{
	GLfloat X;
	GLfloat Y;

	Point(GLfloat x, GLfloat y)
	{
		X = x;
		Y = y;
	}
};

struct Color
{
	GLfloat Red;
	GLfloat Green;
	GLfloat Blue;

	Color(GLfloat red, GLfloat green, GLfloat blue)
	{
		Red = red;
		Green = green;
		Blue = blue;
	}
};

struct Dimension4
{
	GLfloat X1;
	GLfloat Y1;
	GLfloat X2;
	GLfloat Y2;

	Dimension4(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
	{
		X1 = x1;
		Y1 = y1;
		X2 = x2;
		Y2 = y2;
	}
};

/////////////////////////////////////
//Constant Global Variables
/////////////////////////////////////
const float PI = 3.141592653589793238462643383279;
const Point WINDOW_DIM(960, 720);

/////////////////////////////////////
//Global Variables
/////////////////////////////////////
//Objects
Dimension4 grassDim(0, 0, WINDOW_DIM.X, (WINDOW_DIM.Y * 40) / 100);

//Colors
Color redColor(1, 0, 0);
Color greenColor(0, 1, 0);
Color blueColor(0, 0, 1);
Color roadColor(0.2, 0.2, 0.2);
Color daySkyColor(0.0f, 0.7f, 1.0f);
Color nightSkyColor(0.0f, 0.0f, 0.0f);
Color doorColor(0.7, 0.7, 1.0);
Color chimneyColor(1.0, 0.5, 0.0);

/////////////////////////////////////
//Prototypes
/////////////////////////////////////
void init(void);
void drawWorld(void);
void drawGround();
void drawDay();
void drawNight();
void drawCircle(GLfloat, GLfloat, GLfloat, GLfloat, GLint);
void drawHouse(GLfloat, GLfloat, GLfloat, GLfloat);
void drawWindow(GLfloat, GLfloat, GLfloat, GLfloat);
void drawDoor(GLfloat, GLfloat, GLfloat, GLfloat);

/////////////////////////////////////
//Menu Prototypes
/////////////////////////////////////
void rightMenu(int);
void skyColor(int);


void main(int argc, char** argv)
{
	//Initialize window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_DIM.X, WINDOW_DIM.Y);
	glutCreateWindow("Problem 2");
	init();



	//////////////////////////////////////
	//Create menu
	//////////////////////////////////////
	int cc_menu;
	cc_menu = glutCreateMenu(skyColor);
	glutAddMenuEntry("Day", 1);
	glutAddMenuEntry("Night", 2);

	glutCreateMenu(rightMenu);
	glutAddSubMenu("Sky Color", cc_menu);
	glutAddMenuEntry("Quit", 1);

	glutAttachMenu(GLUT_RIGHT_BUTTON);


	///////////////////////////////////////
	//Show window and draw the world 
	//and set it to fullscreen
	///////////////////////////////////////
	glutDisplayFunc(drawWorld);
	//glutFullScreen();
	glutMainLoop();
}

void init(void)
{
	//Initialize the window
	glClearColor(0.0, 0.7, 1, 1.0);								//Set Sky Color
	glMatrixMode(GL_PROJECTION);								//Use Projection
	glLoadIdentity();
	gluOrtho2D(0.0, WINDOW_DIM.X, 0.0, WINDOW_DIM.Y);			//Set max x,y plane
}

void drawWorld(void)
{
	glClear(GL_COLOR_BUFFER_BIT);								//Clear the window

	drawDay();
	drawGround();
	drawHouse((WINDOW_DIM.X*20)/100,(WINDOW_DIM.Y*15)/100,100,75);
	drawHouse((WINDOW_DIM.X * 40) / 100, (WINDOW_DIM.Y * 20) / 100, 90, 65);
	drawHouse((WINDOW_DIM.X * 93) / 100, (WINDOW_DIM.Y * 12) / 100, 100, 75);
	drawHouse((WINDOW_DIM.X * 80) / 100, (WINDOW_DIM.Y * 30) / 100, 75, 50);

	glFlush();													//View the shapes as quickly as possible
}

////////////////////////////////////////////
//Drawing Functions
////////////////////////////////////////////
//Steps needed to draw ground
//1. Draw a big rectanlge and fill it with ground color (Greenish)
//<-OLD->2. Draw 2 parallel lines at an angle and set X to be a different number in order to create gap between them,
//2. Draw a polygon that looks like a road and fill it with blackish color
//	 This will create a street effect.
void drawGround()
{
	//Draw the big rectangle
	glColor3f(greenColor.Red, greenColor.Green, greenColor.Blue);
	glRecti(grassDim.X1, grassDim.Y1, grassDim.X2, grassDim.Y2);


	//Draw the lines
	glColor3f(roadColor.Red, roadColor.Green, roadColor.Blue);
	glBegin(GL_POLYGON);
	glVertex2i((WINDOW_DIM.X*80)/100, 0);
	glVertex2i((WINDOW_DIM.X*50)/100, grassDim.Y2);
	glVertex2i((WINDOW_DIM.X*60)/100, grassDim.Y2);
	glVertex2i((WINDOW_DIM.X*90)/100, 0);
	glEnd();

}
void drawNight()
{
	glClearColor(nightSkyColor.Red, nightSkyColor.Green, nightSkyColor.Blue, 1.0f);
}
void drawDay()
{
	glClearColor(daySkyColor.Red, daySkyColor.Green, daySkyColor.Blue, 1.0f);
}

////////////////////////////////////////////
//Draw Objects
////////////////////////////////////////////
void drawHouse(GLfloat centerX, GLfloat centerY, GLfloat width, GLfloat height)
{
	////////////////////////////////////////
	//Local Variables
	////////////////////////////////////////
	Point baseBottomLeftVert(centerX - (width / 2), centerY - (height / 2));
	Point baseTopLeftVert(centerX - (width / 2), centerY + (height / 2));
	Point baseTopRightVert(centerX + (width / 2), centerY + (height / 2));
	Point baseBottomRightVert(centerX + (width / 2), centerY - (height / 2));
	GLfloat doorHeight = (height * 60) / 100;
	GLfloat doorWidth = (width * 20) / 100;
	Point doorStepLeftVert(((baseBottomLeftVert.X + baseBottomRightVert.X) / 2) - (doorWidth / 1.3), baseBottomLeftVert.Y);
	Point doorStepRightVert(((baseBottomLeftVert.X + baseBottomRightVert.X) / 2) + (doorWidth / 1.3), baseBottomLeftVert.Y + ((height * 6) / 100));

	///////////////////////////////////////
	//Draw Chimney
	///////////////////////////////////////
	//Chimney's Base
	glColor3f(chimneyColor.Red, chimneyColor.Green, chimneyColor.Blue);									//Set base color for the chimeny
	glRecti(baseTopLeftVert.X + ((width * 10) / 100.0), baseTopLeftVert.Y-20,
		baseTopLeftVert.X+((width*30)/100), baseTopLeftVert.Y+((height*75)/100));						//Draw the base of the chimney

	//Mask chimney's base
	glColor3f(0.0, 0.0, 0.0);																			//Set mask color to black
	glEnable(GL_POLYGON_STIPPLE);																		//Enable stippling/masking
	glPolygonStipple(Bricks);																			//Choose mask
	glRecti(baseTopLeftVert.X + ((width * 10) / 100.0), baseTopLeftVert.Y - 20,
		baseTopLeftVert.X + ((width * 30) / 100), baseTopLeftVert.Y + ((height * 75) / 100));			//Draw mask						
	glDisable(GL_POLYGON_STIPPLE);																		//Disable Mask

	//Border Chimney's base
	glColor3f(0, 0, 0);																					//Set border color to black
	glLineWidth(1);																						//Set Linewidth to 1
	glBegin(GL_LINES);																					//Start drawing Lines
	glVertex2i(baseTopLeftVert.X + ((width * 10) / 100.0), baseTopLeftVert.Y - 20);											//Draw vertex 1
	glVertex2i(baseTopLeftVert.X + ((width * 10) / 100.0), baseTopLeftVert.Y + ((height * 75) / 100));						//Draw vertex 2
	glVertex2i(baseTopLeftVert.X + ((width * 30) / 100), baseTopLeftVert.Y - 20);						//Draw vertex 3
	glVertex2i(baseTopLeftVert.X + ((width * 30) / 100), baseTopLeftVert.Y + ((height * 75) / 100));	//Draw vertex 4
	glEnd();																							//Connect and end drawing
	
	//Chimney's Top
	glColor3f(chimneyColor.Red, chimneyColor.Green, chimneyColor.Blue);									//Set background to orig color
	glRecti(baseTopLeftVert.X + ((width * 4.0f) / 100), baseTopLeftVert.Y + ((height * 75) / 100), 
		baseTopLeftVert.X + ((width * 35) / 100), baseTopLeftVert.Y + ((height * 85) / 100));

	//Mask Chimney's Top
	glColor3f(0.0, 0.0, 0.0);																			//Set mask color to black
	glEnable(GL_POLYGON_STIPPLE);																		//Enable stippling/masking
	glPolygonStipple(Bricks);																			//Choose mask
	glRecti(baseTopLeftVert.X + ((width * 4.0f) / 100), baseTopLeftVert.Y + ((height * 75) / 100),
		baseTopLeftVert.X + ((width * 35) / 100), baseTopLeftVert.Y + ((height * 85) / 100));			//Draw mask						
	glDisable(GL_POLYGON_STIPPLE);																		//Disable Mask


	//Border Chimney's top
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(1);
	glBegin(GL_LINES);						
	glVertex2i(baseTopLeftVert.X + ((width * 4.0f) / 100), baseTopLeftVert.Y + ((height * 75) / 100));
	glVertex2i(baseTopLeftVert.X + ((width * 4.0f) / 100), baseTopLeftVert.Y + ((height * 85) / 100));
	glVertex2i(baseTopLeftVert.X + ((width * 35) / 100), baseTopLeftVert.Y + ((height * 75) / 100));
	glVertex2i(baseTopLeftVert.X + ((width * 35) / 100), baseTopLeftVert.Y + ((height * 85) / 100));
	glVertex2i(baseTopLeftVert.X + ((width * 35) / 100), baseTopLeftVert.Y + ((height * 75) / 100));
	glVertex2i(baseTopLeftVert.X + ((width * 4.0f) / 100), baseTopLeftVert.Y + ((height * 75) / 100));
	glVertex2i(baseTopLeftVert.X + ((width * 35) / 100), baseTopLeftVert.Y + ((height * 85) / 100));
	glVertex2i(baseTopLeftVert.X + ((width * 4.0f) / 100), baseTopLeftVert.Y + ((height * 85) / 100));
	glEnd();									
	
	

	///////////////////////////////////////
	//Draw Base
	///////////////////////////////////////
	//Base
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2i(baseBottomLeftVert.X, baseBottomLeftVert.Y);
	glVertex2i(baseTopLeftVert.X, baseTopLeftVert.Y);
	glVertex2i(baseTopRightVert.X, baseTopLeftVert.Y);
	glVertex2i(baseBottomRightVert.X, baseBottomRightVert.Y);
	glEnd();

	//Base's Border
	glColor3f(0, 0, 0);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2i(baseTopLeftVert.X, baseBottomLeftVert.Y);
	glVertex2i(baseTopLeftVert.X, baseTopLeftVert.Y);
	glVertex2i(baseTopRightVert.X, baseTopLeftVert.Y);
	glVertex2i(baseBottomRightVert.X, baseBottomRightVert.Y);
	glEnd();
	glBegin(GL_LINES);						
	glVertex2i(baseTopLeftVert.X, baseTopLeftVert.Y);						
	glVertex2i(baseTopRightVert.X, baseTopRightVert.Y);						
	glEnd();									

	///////////////////////////////////////
	//Draw roof
	///////////////////////////////////////
	glColor3f(1.0, 0.1, 0.0);
	glBegin(GL_TRIANGLES);						
	glVertex2i(baseTopLeftVert.X, baseTopLeftVert.Y);						
	glVertex2i(baseTopRightVert.X, baseTopRightVert.Y);						
	glVertex2i(centerX, baseTopRightVert.Y + (height/1.5));						
	glEnd();

	//Mask the roof
	glColor3f(0.0, 0.0, 0.0);							//Set mask color to black
	glEnable(GL_POLYGON_STIPPLE);						//Enable stippling/masking
	glPolygonStipple(lineMask);							//Choose mask
	glBegin(GL_TRIANGLES);								//Start drawing the triangle
	glVertex2i(baseTopLeftVert.X, baseTopLeftVert.Y);
	glVertex2i(baseTopRightVert.X, baseTopRightVert.Y);
	glVertex2i(centerX, baseTopRightVert.Y + (height / 1.5));
	glEnd();											//Stop drawing									
	glDisable(GL_POLYGON_STIPPLE);						//Disable stippling/masking

	//Border the roof
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(1);
	glBegin(GL_LINES);						
	glVertex2i(baseTopLeftVert.X, baseTopLeftVert.Y);						
	glVertex2i(centerX, baseTopRightVert.Y + (height / 1.5));
	glVertex2i(baseTopRightVert.X, baseTopRightVert.Y);
	glVertex2i(centerX, baseTopRightVert.Y + (height / 1.5));
	glEnd();		

	//Double Border the roof with a little extension
	glLineWidth(1);
	glBegin(GL_LINES);						
	glVertex2i(baseTopLeftVert.X-3, baseTopLeftVert.Y-3);
	glVertex2i(centerX, baseTopRightVert.Y + (height / 1.5)+3);
	glVertex2i(baseTopRightVert.X+3, baseTopRightVert.Y-3);
	glVertex2i(centerX, baseTopRightVert.Y + (height / 1.5) + 3);
	glEnd();									

	///////////////////////////////////////
	//Draw windows
	///////////////////////////////////////
	//Right Window
	drawWindow(baseBottomRightVert.X - ((width * 20) / 100) ,baseTopRightVert.Y - ((height * 32) / 100), (width*20)/100, (height*40)/100);

	//Left Window
	drawWindow(baseBottomLeftVert.X + ((width * 20) / 100), baseTopLeftVert.Y - ((height * 32) / 100), (width * 20) / 100, (height * 40) / 100);

	//////////////////////////////////////
	//Draw Door
	//////////////////////////////////////
	//Draw the door base
	drawDoor((baseBottomLeftVert.X + baseBottomRightVert.X)/2, baseBottomLeftVert.Y+doorHeight/2, doorWidth, doorHeight);

	//Draw Door step
	glColor3f(doorColor.Red, doorColor.Green, doorColor.Blue);
	glRecti(doorStepLeftVert.X, doorStepLeftVert.Y, doorStepRightVert.X, doorStepRightVert.Y);

	//Border the step
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(1);
	glBegin(GL_LINES);						
	glVertex2i(doorStepLeftVert.X, doorStepLeftVert.Y);
	glVertex2i(doorStepLeftVert.X, doorStepRightVert.Y);
	glVertex2i(doorStepRightVert.X, doorStepLeftVert.Y);
	glVertex2i(doorStepRightVert.X, doorStepRightVert.Y);
	glVertex2i(doorStepLeftVert.X, doorStepLeftVert.Y);
	glVertex2i(doorStepRightVert.X, doorStepLeftVert.Y);
	glVertex2i(doorStepLeftVert.X, doorStepRightVert.Y);
	glVertex2i(doorStepRightVert.X, doorStepRightVert.Y);						
	glEnd();									

}
void drawDoor(GLfloat centerX, GLfloat centerY, GLfloat width, GLfloat height)
{
	///////////////////////////////////////
	//Local Variables
	///////////////////////////////////////
	Point doorBottomLeftVert(centerX - (width / 2), centerY - (height / 2));
	Point doorTopRightVert(centerX + (width / 2), centerY + (height / 2));

	//Draw wood
	glColor3f(doorColor.Red, doorColor.Green, doorColor.Blue);
	glRecti(doorBottomLeftVert.X, doorBottomLeftVert.Y, doorTopRightVert.X, doorTopRightVert.Y);

	//Draw border
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(1);
	glBegin(GL_LINES);						
	glVertex2i(doorBottomLeftVert.X, doorBottomLeftVert.Y);						
	glVertex2i(doorBottomLeftVert.X, doorTopRightVert.Y);						
	glVertex2i(doorTopRightVert.X, doorBottomLeftVert.Y);						
	glVertex2i(doorTopRightVert.X, doorTopRightVert.Y);						
	glVertex2i(doorBottomLeftVert.X, doorBottomLeftVert.Y);						
	glVertex2i(doorTopRightVert.X, doorBottomLeftVert.Y);						
	glVertex2i(doorBottomLeftVert.X, doorTopRightVert.Y);						
	glVertex2i(doorTopRightVert.X, doorTopRightVert.Y);						
	glEnd();									

	//Draw door lock
	glColor3f(1.0, 0.5, 0.0);
	drawCircle(doorTopRightVert.X-5, (doorBottomLeftVert.Y + doorTopRightVert.Y) / 2, 0, 2, 360);
	//drawCircle(95, 117.5, 2.5, 400);
}
void drawWindow(GLfloat centerX, GLfloat centerY, GLfloat width, GLfloat height)
{
	///////////////////////////////////////
	//Local Variables
	///////////////////////////////////////
	Point windowBottomLeftVert(centerX - (width/2), centerY-(height/2));
	Point windowTopRightVert(centerX + (width / 2), centerY + (height / 2));

	//Draw Glass
	glColor3f(daySkyColor.Red, daySkyColor.Green, daySkyColor.Blue);					
	glRecti(windowBottomLeftVert.X, windowBottomLeftVert.Y, windowTopRightVert.X, windowTopRightVert.Y);
	
	//Draw border
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(1);
	glBegin(GL_LINES);						
	glVertex2i(windowBottomLeftVert.X, windowBottomLeftVert.Y);
	glVertex2i(windowBottomLeftVert.X, windowTopRightVert.Y);
	glVertex2i(windowTopRightVert.X, windowBottomLeftVert.Y);
	glVertex2i(windowTopRightVert.X, windowTopRightVert.Y);						
	glVertex2i(windowTopRightVert.X, windowTopRightVert.Y);						
	glVertex2i(windowBottomLeftVert.X, windowTopRightVert.Y);
	glVertex2i(windowTopRightVert.X, windowBottomLeftVert.Y);
	glVertex2i(windowBottomLeftVert.X, windowBottomLeftVert.Y);
	glLineWidth(2);
	glVertex2i(windowTopRightVert.X, (windowBottomLeftVert.Y+windowTopRightVert.Y)/2);						
	glVertex2i(windowBottomLeftVert.X, (windowBottomLeftVert.Y + windowTopRightVert.Y) / 2);
	glVertex2i((windowBottomLeftVert.X + windowTopRightVert.X) / 2, windowBottomLeftVert.Y);
	glVertex2i((windowBottomLeftVert.X + windowTopRightVert.X) / 2, windowTopRightVert.Y);
	glEnd();									

}
void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat r, GLint numberOfSides)
{
	GLint numberOfVert = numberOfSides + 2;
	GLfloat doublePI = 2.0f * PI;
	GLfloat *circleVerticesX = new GLfloat[numberOfVert];
	GLfloat *circleVerticesY = new GLfloat[numberOfVert];
	GLfloat *circleVerticesZ = new GLfloat[numberOfVert];

	circleVerticesX[0] = x;
	circleVerticesY[0] = y;
	circleVerticesZ[0] = z;

	for (int i = 1; i < numberOfVert; i++)
	{
		circleVerticesX[i] = x + (r * cos(i*doublePI / numberOfSides));
		circleVerticesY[i] = y + (r * sin(i*doublePI / numberOfSides));
		circleVerticesZ[i] = z;
	}

	
	GLfloat *allCircleVertices = new GLfloat[(numberOfVert * 3)];

	for (int i = 0; i < numberOfVert; i++)
	{
		allCircleVertices[i * 3] = circleVerticesX[i];
		allCircleVertices[(i * 3) + 1] = circleVerticesY[i];
		allCircleVertices[(i * 3) + 2] = circleVerticesZ[i];
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, allCircleVertices);
	glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVert);
	glDisableClientState(GL_VERTEX_ARRAY);

	delete []circleVerticesX;
	delete []circleVerticesY;
	delete []circleVerticesZ;
	delete []allCircleVertices;
}



////////////////////////////////////////////
//Menu Functions
////////////////////////////////////////////
void rightMenu(int id)
{
	if (id == 1)								//Check pressed menu ID, if it was 1 then
		exit(0);								//Exist
}
void skyColor(int id)
{
	//Switch between menu items and change the background color respectivly.
	switch (id)
	{
	case 1:
		//glClearColor(0.0f, 0.7f, 1.0f, 1.0f);
		drawDay();
		break;
	case 2:
		//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		drawNight();
		break;
	default:
		break;
	}
	glutPostRedisplay();
}