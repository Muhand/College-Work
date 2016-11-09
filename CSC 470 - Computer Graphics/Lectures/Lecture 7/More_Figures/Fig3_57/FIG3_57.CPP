// File: fig3_57.cpp

#include <windows.h>   // use as needed for your system
#include <math.h>
#include <gl/Gl.h>
#include <gl/glut.h>

#include "../Appendix/canvas.h"
const int screenWidth  = 400;
const int screenHeight = screenWidth;
const float aspectRatio = screenWidth / (float)screenHeight;
const int diagnosticLevel = 20;

Canvas cvs(screenWidth, screenHeight, "Figure 3.59 The yin-yang symbol");


void drawArc(Point2 center, float radius,
        float startAngle, float sweep, Canvas& cvs)
{  // startAngle and sweep are in degrees
   const int n = (int)30; // number of intermediate segments in arc
   const double Pi = 4*atan(1.0);
   float angle = startAngle * Pi / 180; // initial angle in radians
   float angleInc = sweep * Pi /(180 * n); // angle increment
   float cx = center.getX(), cy = center.getY();
   cvs.moveTo(cx + radius * cos(angle), cy + radius * sin(angle));
   // Note need to change indexing from book's code
   for(int k = 0; k <= n; k++, angle += angleInc)
      cvs.lineTo(cx + radius * cos(angle),
                 cy + radius * sin(angle));
}

void drawCircle (Point2 center, float radius, Canvas& cvs) {
   drawArc (center, radius, 0.0, 360.0, cvs);
}

class YinYang {
private:
   Point2 center;
   float  radius;
public:
   YinYang (Point2 c, float r) { center = c; radius = r; }
   void draw (Canvas& cvs) {
      drawCircle (center, radius, cvs);
      Point2 a(center.getX()-0.5*radius, center.getY());
      drawCircle (a, 0.15*radius, cvs);
      drawArc (a, 0.5*radius, 180.0, 180.0, cvs);
      Point2 b(center.getX()+0.5*radius, center.getY());
      drawCircle (b, 0.15*radius, cvs);
      drawArc (b, 0.5*radius, 0.0, 180.0, cvs);
   }
};

YinYang y (Point2(0.0, 0.0), 1.0);

void display(void) {
   cvs.clearScreen();
   cvs.setWindow(-1.2, 1.2, -1.2, 1.2);
   y.draw(cvs);
   glFlush();                        // send all output to display
}


void myCenter(GLsizei W, GLsizei H) {
   if (H*aspectRatio > W)  // use (global) window aspect ratio
      // Case (a): R > W/H - Reach all the way across
      cvs.setViewport(0, W, (GLsizei)((H*aspectRatio - W)/(2.0*aspectRatio)),
                      (GLsizei)((H*aspectRatio + W)/(2.0*aspectRatio)) );
   else
      // Case (b): R < W/H - Reach all the way from top to bottom
      cvs.setViewport((GLsizei)((W - H*aspectRatio)/2),
                      (GLsizei)((W + H*aspectRatio)/2), 0, H);
}


int main(int argc, char** argv) {
  cvs.setViewport(0, screenWidth, 0, screenHeight);
  glutReshapeFunc(myCenter);
  glutDisplayFunc(display);
  glutMainLoop();
  return (0);
}
