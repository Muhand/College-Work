// File: Fig3_13/fig3_13.cpp
//
// F. S. Hill, Jr., Computer Graphics: Using OpenGL, second edition,
//       Prentice Hall, 2001.
// Figure 3.12 Zooming in on the swirl of hexagons
//


#include <windows.h>   // use as needed for your system
#include <gl/Gl.h>
#include <gl/glut.h>

#include "../Appendix/canvas.h"
const float aspect = 0.7;
const int screenWidth  = 400;
const int screenHeight = screenWidth*aspect;
const int numFrames = 10;

Canvas cvs(screenWidth, screenHeight, "Figure 3.12 Zooming in on the swirl of hexagons");

//<<<<<<<<<<<<<<<<<<<<<<<< hexSwirl >>>>>>>>>>>>>>>>>
void hexSwirl(Canvas cvs, const float radius,
              const int n, const float r)
{
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


void delay(const int n) {
   float x = 1.0;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         x = sin(1.8*x);
}

void display(void) {
   float cx = 0, cy = 0;  // center of the window
   float W = 150;         // window properties
   float H = W*aspect;
   cvs.setViewport(0, screenWidth, 0, screenHeight);
   for (int frame = 0; frame < numFrames; frame++) {
      cout << "next ..." << endl;
      cvs.clearScreen();
      cvs.setColor(0.0, 0.0, 0.0);
      cvs.setWindow(cx - W, cx + W, cy - H, cy + H);
      hexSwirl(cvs, 100.0, 30, 5.0);
      W *= 0.82;       // Reduce the window width
      H = W*aspect;   // Maintain the same aspect ratio
      cx += 0.1*W;
      cy += 0.05*H;

      cvs.setColor(1.0, 0.0, 0.0);  // Draw the next window
//      glBegin(GL_LINE_LOOP);
//         glVertex2f((GLfloat)(cx - W), (GLfloat)(cy - H));
//         glVertex2f((GLfloat)(cx + W), (GLfloat)(cy - H));
//         glVertex2f((GLfloat)(cx + W), (GLfloat)(cy + H));
//         glVertex2f((GLfloat)(cx - W), (GLfloat)(cy + H));
//      glEnd();
      RealRect r(cx-W, cy+H, cx+W, cy-H);
      r.draw(cvs);
      glFlush();                        // send all output to display
      delay(3000);
   }
   cout << "Done." << endl;
}


int main(int argc, char** argv) {
  // Window is opened in the Canvas constructor
  glutDisplayFunc(display);
  glutMainLoop();
  return (0);
}
