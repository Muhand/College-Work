// File: Fig3_38/fig3_38.cpp
//
// F. S. Hill, Jr., Computer Graphics: Using OpenGL, second edition,
//       Prentice Hall, 2001.
// Figure 3.38 Example of a meander



#include <windows.h>   // use as needed for your system
#include <gl/Gl.h>
#include <gl/glut.h>

#include "../Appendix/canvas.h"
const int numMeander   = 5;
const int screenWidth  = (numMeander+1)*100;
const int screenHeight = 200;
const int diagnosticLevel = 20;

Canvas cvs(screenWidth, screenHeight, "Figure 3.38 Example of a meander");

class Meander {
private:
   int which;
public:
   Meander (int w) { which = w; }
   void draw (Canvas cvs) {
   // void draw (Canvas& cvs) {  // Pass by reference to change global cvs
      switch (which) {
        case 1:
           cvs.forward(80);   cvs.turnLeft();   // right
           cvs.forward(50);   cvs.turnLeft();   // up
           cvs.forward(30);   cvs.turnLeft();   // left
           cvs.forward(25);   cvs.turnRight();  // down
           cvs.forward(30);   cvs.turnRight();  // left
           cvs.forward(50);   cvs.turnRight();  // up
           cvs.forward(80);   cvs.turnRight();  // right
           cvs.forward(75);   cvs.turnLeft();   // down
           break;
        case 2:
           cvs.forward(40);   cvs.turnLeft();   // right
           cvs.forward(40);   cvs.turnLeft();   // up
           cvs.forward(20);   cvs.turnRight();  // left
           cvs.forward(20);   cvs.turnRight();  // up
           cvs.forward(60);   cvs.turnRight();  // right
           cvs.forward(20);   cvs.turnRight();  // down
           cvs.forward(20);   cvs.turnLeft();   // left
           cvs.forward(40);   cvs.turnLeft();   // down
           cvs.forward(40);                     // right
           break;
        default:
           cvs.forward (100);
      }
      Point2 CP = cvs.getCP();
      cout << "CP x, y: " << CP.x << ", " << CP.y << endl;
   }
};

Meander m(1);
// Meander m(2);


void display(void) {
   Point2 CP;
   cvs.clearScreen();
   cvs.setWindow(0, screenWidth, 0, screenHeight);
   cvs.moveTo(50, 50);
   for (int i = 0; i < numMeander; i++ ) {
      if (diagnosticLevel >= 20) {
         CP = cvs.getCP();
         cout << "CP x, y: " << CP.x << ", " << CP.y << endl;
      }
      m.draw(cvs);
         CP = cvs.getCP();
         cout << "CP x, y: " << CP.x << ", " << CP.y << endl;
   }
   glFlush();                        // send all output to display
}


int main(int argc, char** argv) {
  // Window is opened in the Canvas constructor
  cvs.setViewport(0, screenHeight, 0, screenHeight);
  glLineWidth(5.0);
  glutDisplayFunc(display);
  glutMainLoop();
  return (0);
}
