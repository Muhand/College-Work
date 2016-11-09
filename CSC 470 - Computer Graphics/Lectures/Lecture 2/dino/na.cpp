#include <stdio.h> // use proper includes for your system
#include <fstream.h>
#include <math.h>
#include <GL/glut.h>
const int screenWidth = 640;	   // width of screen window in pixels 
const int screenHeight = 480;	   // height of screen window in pixels
GLdouble A, B, C, D;  // values used for scaling and shifting
GLfloat xmin = 0.0, xmax = 350.0, ymin = -10.0, ymax = 150.0;

void drawPolyLineFile(char * fileName)
{
	fstream inStream;
	inStream.open(fileName, ios ::in);	// open the file
	if(inStream.fail())
		return;
	glClear(GL_COLOR_BUFFER_BIT);      // clear the screen
	GLint numpolys, numLines, x ,y;
	inStream >> numpolys;		           // read the number of polylines
	for(int j = 0; j < numpolys; j++)  // read each polyline
	{
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);	     // draw the next polyline
		for (int i = 0; i < numLines; i++)
		{
			inStream >> x >> y;        // read the next x, y pair
			glVertex2i(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
 void myInit(void)
 {
    	glClearColor(1.0,1.0,1.0,0.0);       // background color is white
    	glColor3f(0.0f, 0.0f, 0.0f);         // drawing color is black
 	glPointSize(2.0);		          // a 'dot' is 2 by 2 pixels
	glMatrixMode(GL_PROJECTION); 	   // set "camera shape"
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
	A = screenWidth / (xmax-xmin); // set values used for scaling and shifting
	B = 0 - xmin*A;
	C = screenHeight / (ymax - ymin);
	D = 0 - ymin*C;
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	drawPolyLineFile("Brontoi.dat");		   // send all output to display
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Dino Line Drawing"); // open the screen window
	glutDisplayFunc(myDisplay);     // register redraw function
	myInit();                   
	glutMainLoop(); 		     // go into a perpetual loop
	return 1;
}
