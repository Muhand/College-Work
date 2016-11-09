// File: Fig3_17/fig3_17a.cpp
//
// F. S. Hill, Jr., Computer Graphics: Using OpenGL, second edition,
//       Prentice Hall, 2001.
// Figure 3.17 Using a reshape function to set the largest matching
//       viewport upon a resizing event
//


#include <windows.h>   // use as needed for your system
#include <gl/Gl.h>
#include <gl/glut.h>

#include "../Appendix/canvas.h"
const int screenWidth  = 500;
const int screenHeight = 400;
const float aspectRatio = screenWidth / (float)screenHeight;

Canvas cvs(screenWidth, screenHeight, "Figure 3.14 a)");

void hexSwirl(Canvas cvs, const float radius,
              const int n, const float r) {
   float rad = radius;
   float rot = 0.0;
   float s = -radius / n;
   ngon hex;
   for (int i = 1; i <= n; i++) {
      hex.set(6, 0.0, 0.0, rad, rot);
      hex.draw(cvs);
      rad += s; rot += r;
   }
   glFlush();
}


void display(void) {
   cvs.clearScreen();
   cvs.setWindow(-150.0, 150.0, -150.0, 150.0);
   hexSwirl(cvs, 100.0, 30, 5.0);
   glFlush();                        // send all output to display
}


void myReshape(GLsizei W, GLsizei H) {
   cout << "Resize: W, H: " << W << ", " << H << endl;
   if (H*aspectRatio > W)  // use (global) window aspect ratio
      // Case (a): R > W/H - Reach all the way across
      cvs.setViewport(0, W, 0, (int)((float)W/aspectRatio));
   else
      // Case (b): R < W/H - Reach all the way from top to bottom
      cvs.setViewport(0, (GLsizei)(H*aspectRatio), 0, H);
}


//<<<<<<<<<<<<<<<<<<<<<<<< Figure 2.41 myKeyboard >>>>>>>>>>>>>>>>>
void keyboard(unsigned char theKey, int mouseX, int mouseY) {
  switch(theKey) {
     case 'r':
     case 'R':
        glutReshapeFunc(myReshape);
        break;
     case 'E':
        exit(-1);  // terminate the program
        break;
     default:
        break;
  }
}


int main(int argc, char** argv) {
  // Window is opened in the Canvas constructor
  cvs.setViewport(0, screenHeight, 0, screenHeight);
  glutKeyboardFunc(keyboard);
  glutDisplayFunc(display);
//  glutReshapeFunc(myReshape);
  glutMainLoop();
  return (0);
}
