#include <stdio.h>   // use as needed for your system
#include <stdlib.h>

#include <GL/glut.h>
#include "canvas.h"

Canvas cvs(640, 480, "My Polyspirals"); //global canvas object
float angle = 87, inc = 0.5;


//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	cvs.clearScreen();
	float length = 1;
	cvs.moveTo(0.0,0.0);
	for(int i = 0; i < 100; i++)
	{
		cvs.forward(length,1);
		cvs.turn(angle);
		length += inc;

	}
	glFlush();		                 // send all output to display
}


void main(int argc, char **argv)
{
	if (argc == 3)  //user has supplied the angle and increment
	{
		angle = atof(argv[1]);
		inc = atof(argv[2]);
		printf("%f %f\n", angle, inc);
	}
	
	cvs.setWindow(-100.0, 100.0, -100.0, 100.0);
	cvs.setViewport(-100, 100, -100, 100);
	cvs.setBackgroundColor(0.0, 0.0, 0.0);
	cvs.setColor(1.0, 1.0, 0.0);

	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutDisplayFunc(myDisplay);
	glutMainLoop();

}