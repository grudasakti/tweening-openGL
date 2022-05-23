/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>
#define RATIO 1.200
#define WW    100
#define WH    (WW/RATIO)
#define HALFX ((int) (WW/2))
#define HALFY ((int) (WH/2))
#define deltat .001
int WindowWidth;
int WindowHeight;

void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-HALFX, HALFX, -HALFY, HALFY);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0, 0, 0, 0);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glShadeModel(GL_SMOOTH);
    glViewport(0, 0, WindowWidth, WindowHeight);
}

void Display(){
 glLineWidth(4.0);
 float StartShape[12][2] = {{5,25},{-15,25},{-15,-15},{5,-15},{5,5},{-5,5},{-5,-2},{2,-2},{2,-7},{-10,-7},{-10,20},{5,20}}; // huruf G
 float EndShape[12][2] = {{5,25},{0,25},{-2,22},{-7,22},{-7,17},{-2,17},{-2,-10},{-7,-10},{-7,-15},{10,-15},{10,-10},{5,-10}}; // angka 1
 float IntermediateShape[12][2];
 float VertexColors[12][3]={{1,0,0},{1,1,0},{1,0,1},{0,1,0},{0,1,1},{0,0,1},{1,0.5,0},{1,0,0.5},{0.5,1,0},{0.5,0,1},{1,0,0.5},{0,1,0.5}};
 static float Tween = 0.0 - deltat;
 if (Tween<1){
  Tween += deltat;
 }

 for (int Vtx = 0; Vtx<12; Vtx++){
  IntermediateShape[Vtx][0] = (1.0 - Tween)*StartShape[Vtx][0] + Tween*EndShape[Vtx][0];
  IntermediateShape[Vtx][1] = (1.0 - Tween)*StartShape[Vtx][1] + Tween*EndShape[Vtx][1];
 }

 glVertexPointer(2, GL_FLOAT, 0, IntermediateShape);
 glColorPointer(3, GL_FLOAT, 0, VertexColors);
 for (int i = 0; i < 1500000; i++);
 glClear(GL_COLOR_BUFFER_BIT);
 glDrawArrays(GL_LINE_LOOP, 0, 12);
 glutSwapBuffers();
 glutPostRedisplay();
}

void InitGL(){
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-HALFX, HALFX, -HALFY, HALFY);
 glMatrixMode(GL_MODELVIEW);
 glClearColor(0, 0, 0, 0);
 glEnableClientState(GL_VERTEX_ARRAY);
 glEnableClientState(GL_COLOR_ARRAY);
 glShadeModel(GL_SMOOTH);
 glViewport(0, 0, WindowWidth, WindowHeight);
}

void Reshape(int w, int h){
 glutReshapeWindow(w, (int)(w / RATIO));
 WindowWidth = w;
 WindowHeight = (int)(w / RATIO);
 InitGL();
}

int main(int argc, char **argv){
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
 WindowWidth = (int)(glutGet((GLenum)GLUT_SCREEN_WIDTH)*.4);
 WindowHeight = (int)(WindowWidth / RATIO);
 glutInitWindowSize(WindowWidth, WindowHeight);
 glutInitWindowPosition((int)(glutGet((GLenum)GLUT_SCREEN_WIDTH)*.1), (glutGet((GLenum)GLUT_SCREEN_HEIGHT)/2)-(WindowHeight/2));
 glutCreateWindow("Gruda Sakti Krida Prastya - 672019252");
 glutDisplayFunc(Display);
 glutReshapeFunc(Reshape);
 InitGL();
 glutMainLoop();
}
