#include <iostream>
#include <fstream>
#include <string>
#include <GL/freeglut.h>
 
using namespace std;

/*void myDisplay(void)// User defined display function
{
    
    glClear(GL_COLOR_BUFFER_BIT); //clears fb with bg color
    glClearColor(0.9f, 0.9f, 0.9f, 0.0); // set background Color
    glColor3f(1,0,0); // set Foreground Color
    glFlush();// sends buffer pixels to display screen
}

int screenWidth=640;
int screenHeight=480;

int main(int argc,char **argv)
{	
	glutInit(&argc,argv);	
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight); 
	glutInitWindowPosition(30,30);
	glutCreateWindow(" HT First OGL Program");
    glutDisplayFunc(myDisplay); //register display func. as callback
    glutMainLoop(); //qui loop that waits for events to occur
    return 0;
}*/


///The Big Dipper
//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
void myInit(void)
{
glClearColor(1.0,1.0,1.0,0.0); // set white background color
 //glColor3f(0.0f, 0.0f, 0.0f); // set the drawing color
glColor3f(0.0f, 0.0f, 0.0f);//Black
glPointSize(4.0); // a ‘dot’ is 4 by 4 pixels
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, 200,0, 200);
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT); // clear the screen
//glPointSize(10.0);

// Body
glBegin(GL_LINE_LOOP);
glColor3f(0.0f, 0.0f, 1.0f);//Blue
glVertex2f(40.0f,40.0f);
glVertex2f(40.0f,90.0f);
glVertex2f(70.0f,120.0f);
glVertex2f(100.0f,90.0f);
glVertex2f(100.0f,40.0f);
glEnd();

//Chimney
glBegin(GL_LINE_STRIP);
glColor3f(0.0f, 0.0f, 1.0f);//Blue
glVertex2f(50.0f,100.0f);
glVertex2f(50.0f,120.0f);
glVertex2f(60.0f,120.0f);
glVertex2f(60.0f,110.0f);
glEnd();
//
////Gate
glBegin(GL_POLYGON);
glColor3f(0.0f, 0.0f, 1.0f);//Blue
glVertex2f(50.0f,40.0f);
glVertex2f(50.0f,80.0f);
glVertex2f(70.0f,80.0f);
glVertex2f(70.0f,40.0f);
glEnd();

////Window
glBegin(GL_POLYGON);
glColor3f(0.0f, 0.0f, 1.0f);//Blue
glVertex2f(80.0f,80.0f);
glVertex2f(80.0f,90.0f);
glVertex2f(90.0f,90.0f);
glVertex2f(90.0f,80.0f);


//glBegin(GL_POINTS);
//glVertex2i(5, 5); // draw three points
//glVertex2i(10, 10);
//glVertex2i(20, 20);
//glVertex2i(30,30);
glEnd();

glFlush();

}
/*
glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.0f, 1.0f);//Blue
glVertex2f(0.0f,5.0f);
glVertex2f(4.0f,-3.0f);
glVertex2f(-4.0f,-3.0f);
glEnd();

/*
glBegin(GL_QUADS);
glColor3f(0.0f, 1.0f, 0.0f);//Green
glVertex2f(-6.0f,0.0f);
glVertex2f(6.0f,0.0f);
glVertex2f(-8.0f,6.0f);
glVertex2f(-6.0f,-8.0f);
glEnd();

/*
glBegin(GL_POINTS);
glVertex2i(5, 5); // draw three points
glVertex2i(10, 10);
glVertex2i(20, 20);
glVertex2i(30,30);
glEnd();
glFlush(); // send all output to display
}
*/
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
glutInit(&argc, argv); // initialize the toolkit
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
glutInitWindowSize(640,480); // set window size
glutInitWindowPosition(200, 200); // set window position on screen
glutCreateWindow("my first attempt"); // open the screen window
glutDisplayFunc(myDisplay); // register redraw function
myInit();
glutMainLoop(); // go into a perpetual loop
}


