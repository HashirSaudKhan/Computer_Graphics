//LAB #02

#include <iostream>
#include <fstream>
#include <string>
#include <GL/freeglut.h>
#include <math.h>
using namespace std;

void drawScene() {
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1,0,0);
    glLoadIdentity(); //Reset the drawing perspective
    gluOrtho2D(-12,38,-19,14);//range
    glMatrixMode(GL_MODELVIEW);


    ///sky///
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(135,206,250);//sky blue
    glVertex2f(38.0f,3.0f);
    glVertex2f(38.0f,14.0f);
    glVertex2f(-12.0f,14.0f);
    glVertex2f(-12.0f,3.0f);

    glEnd();

     ///sun///
    glPushMatrix();//This function saves the current matrix onto the matrix stack. It's often used to preserve the current transformation state.
    glColor3d(255,255,0);//Yellow
    glTranslatef(30.0, 7.0, 0);//This translates the current modelview matrix by moving it 30 units in the X-axis and 7 units in the Y-axis. This will position the sun at the specified location.

    glutSolidSphere(1.0, 250, 250);// This function draws a solid sphere with a radius of 1.0 unit and 250 slices and 250 stacks, which results in a fairly smooth sphere.

    glPopMatrix();//This restores the previously saved transformation state using 


  ///sea portion///
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(65,105,225);//blue
    glVertex2f(38.0f,-19.0f);
    glVertex2f(38.0f,3.0f);
    glVertex2f(-12.0f,3.0f);
    glVertex2f(-12.0f,-19.0f);

    glEnd();

/////soil portion///
////polygon 
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0,128,0);//Dark green
    glVertex2f(-12.0f,-9.5f);
    glVertex2f(38.0f,-9.5f);
    glVertex2f(38.0f,3.0f);
    glVertex2f(-12.0f,3.0f);



//polygon

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0,128,0);
    glVertex2f(-0.4f,1.1f);
    glVertex2f(-0.4f,1.5f);
    glVertex2f(-0.6f,1.5f);
    glVertex2f(-0.6f,1.1f);

    glEnd();


///house on left side///
//polygon 1
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(139,69,19);//Dark brown
    glVertex2f(-2.7f,1.2f);
    glVertex2f(-6.7f,1.2f);
    glVertex2f(-5.0f,-1.0f);
    glVertex2f(-1.0f,-1.0f);

    glEnd();


//polygon 2
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(139,69,19);
    glVertex2f(-6.5f,1.0f);
    glVertex2f(-6.7f,1.2f);
    glVertex2f(-8.5f,-1.0f);
    glVertex2f(-8.0f,-1.0f);

    glEnd();

//polygon 3
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(205,133,63);
    glVertex2f(-6.5f,1.0f);
    glVertex2f(-8.0f,-1.0f);
    glVertex2f(-8.0f,-2.5f);
    glVertex2f(-5.0f,-3.0f);
    glVertex2f(-5.0f,-1.0f);

    glEnd();

//polygon 4
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(128,135,32);//green
    glVertex2f(-6.0f,-2.0f);
    glVertex2f(-6.0f,-1.0f);
    glVertex2f(-7.0f,-1.0f);
    glVertex2f(-7.0f,-2.0f);

    glEnd();

//polygon 5
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(139,69,19);
    glVertex2f(-5.0f,-3.0f);
    glVertex2f(-8.0f,-2.5f);
    glVertex2f(-8.3f,-2.9f);
    glVertex2f(-5.0f,-3.5f);

    glEnd();

//polygon 6
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(184,134,11);
    glVertex2f(-1.5f,-3.0f);
    glVertex2f(-1.5f,-1.0f);
    glVertex2f(-5.0f,-1.0f);
    glVertex2f(-5.0f,-3.0f);

    glEnd();

//polygon 7
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(139,69,19);
    glVertex2f(-5.0f,-3.0f);
    glVertex2f(-5.0f,-3.5f);
    glVertex2f(-1.0f,-3.5f);
    glVertex2f(-1.5f,-3.0f);

    glEnd();



///house on right side///

//polygon1//
    glBegin(GL_POLYGON);

    //glColor3ub(25,25,112);
    glColor3ub(47,79,79);// Dark gray
    glVertex2f(25.3,1.2);
    glVertex2f(21.3,1.2);
    glVertex2f(23,-1);
    glVertex2f(27,-1);

    glEnd();

//polygon2//
    glBegin(GL_POLYGON);
      glColor3ub(47,79,79);
    //glColor3ub(139,69,19);
    glVertex2f(21.5,1);
    glVertex2f(21.3,1.2);
    glVertex2f(19.5,-1);
    glVertex2f(20,-1);

    glEnd();

//polygon3//
    glBegin(GL_POLYGON);

    glColor3ub(184,134,11);
    glVertex2f(21.5,1);
    glVertex2f(20,-1);
    glVertex2f(20,-2.5);
    glVertex2f(23,-3);
    glVertex2f(23,-1);

    glEnd();

//polygon4//
   glBegin(GL_POLYGON);

    glColor3ub(160,82,45);
    glVertex2f(22,-2);
    glVertex2f(22,-1);
   glVertex2f(21,-1);
    glVertex2f(21,-2);

    glEnd();

//polygon5//
    glBegin(GL_POLYGON);
     glColor3ub(47,79,79);
    //glColor3ub(139,69,19);
    glVertex2f(23,-3);
    glVertex2f(20,-2.5);
    glVertex2f(19.7,-2.9);
    glVertex2f(23,-3.5);

    glEnd();

//polygon6//
   glBegin(GL_POLYGON);

   glColor3ub(205,133,63);
    glVertex2f(26.5,-3);
    glVertex2f(26.5,-1);
    glVertex2f(23,-1);
    glVertex2f(23,-3);

    glEnd();

//polygon7//
    glBegin(GL_POLYGON);
     glColor3ub(47,79,79);
    //glColor3ub(139,69,19);
    glVertex2f(23,-3);
    glVertex2f(23,-3.5);
    glVertex2f(27,-3.5);
    glVertex2f(26.5,-3);

    glEnd();


///hillview///
///hill-1///
//polygon1//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(-12,3);
    glVertex2f(-11.5,4.5);
    glVertex2f(-7.5,4.5);
    glVertex2f(-7,3);
    //glVertex2f();
    glEnd();

//polygon2//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(-11.5,4.5);
    glVertex2f(-11,5.5);
    glVertex2f(-8,5.5);
    glVertex2f(-7.5,4.5);
    //glVertex2f();
    glEnd();

//polygon3//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(-11,5.5);
    glVertex2f(-10.5,6);
    glVertex2f(-8.5,6);
    glVertex2f(-8,5.5);
    //glVertex2f();
    glEnd();

//polygon4//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(-10.5,6);
    glVertex2f(-10.3,6.2);
    glVertex2f(-8.7,6.2);
    glVertex2f(-8.5,6);
    //glVertex2f();
    glEnd();

//polygon5//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(-10.3,6.2);
    glVertex2f(-10.2,6.3);
    glVertex2f(-8.8,6.3);
    glVertex2f(-8.7,6);
    //glVertex2f();
    glEnd();

///Hill 2///
//polygon1//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(-7,3);
    glVertex2f(-6.5,4);
    glVertex2f(-4.5,4);
    glVertex2f(-4,3);
    //glVertex2f();
    glEnd();

//polygon2//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(-6.5,4);
    glVertex2f(-6,4.5);
    glVertex2f(-5,4.5);
    glVertex2f(-4.5,4);
    //glVertex2f();
    glEnd();

///Hill 3///
//polygon1//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(-4,3);
    glVertex2f(-3.5,4.5);
    glVertex2f(-1.5,4.5);
    glVertex2f(-1,3);
    //glVertex2f();
    glEnd();

//polygon2//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(-3.5,4.5);
    glVertex2f(-3,5);
    glVertex2f(-2,5);
    glVertex2f(-1.5,4.5);
    //glVertex2f();
    glEnd();

///Hill 4///
//polygon1//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(-1,3);
    glVertex2f(-0.5,6);
    glVertex2f(4.5,6);
    glVertex2f(5,3);
    //glVertex2f();
    glEnd();

//polygon2//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(-0.5,6);
    glVertex2f(0,7);
    glVertex2f(4,7);
    glVertex2f(4.5,6);
    //glVertex2f();
    glEnd();

//polygon3//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(0,7);
    glVertex2f(1,8);
    glVertex2f(3,8);
    glVertex2f(4,7);
    //glVertex2f();
    glEnd();
//triangle//
    glBegin(GL_TRIANGLES);
    glColor3ub(139, 69, 19);
    glVertex2f(1,8);
    glVertex2f(3,8);
    glVertex2f(2,8.3);
    glEnd();

///hill 5///
//polygon1//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(5,3);
    glVertex2f(5.5,4);
    glVertex2f(6.5,4);
    glVertex2f(7,3);
    //glVertex2f();
    glEnd();

//triangle//
    glBegin(GL_TRIANGLES);
    glColor3ub(139, 69, 19);
    glVertex2f(5.5,4);
    glVertex2f(6.5,4);
    glVertex2f(6,4.5);
    glEnd();

///hill 6///
//polygon1//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(7,3);
    glVertex2f(8,5);
    glVertex2f(13,5);
    glVertex2f(14,3);
    //glVertex2f();
    glEnd();

//polygon2//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(8,5);
    glVertex2f(9,6);
    glVertex2f(12,6);
    glVertex2f(13,5);
    //glVertex2f();
    glEnd();
//triangle//
    glBegin(GL_TRIANGLES);
    glColor3ub(139, 69, 19);
    glVertex2f(9,6);
    glVertex2f(12,6);
    glVertex2f(10.5,6.5);
    glEnd();

///hill 7///
//polygon1//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(14,3);
    glVertex2f(15,5);
    glVertex2f(20,5);
    glVertex2f(21,3);
    //glVertex2f();
    glEnd();

//polygon2//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(15,5);
    glVertex2f(16,6);
    glVertex2f(19,6);
    glVertex2f(20,5);
    //glVertex2f();
    glEnd();

//triangle//
    glBegin(GL_TRIANGLES);
    glColor3ub(139, 69, 19);
    glVertex2f(16,6);
    glVertex2f(19,6);
    glVertex2f(17.5,6.5);
    glEnd();

///hill 8///
//polygon1//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(21,3);
    glVertex2f(22,5);
    glVertex2f(24,5);
    glVertex2f(25,3);
    //glVertex2f();
    glEnd();

//polygon2//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(22,5);
    glVertex2f(22.5,5.5);
    glVertex2f(23.5,5.5);
    glVertex2f(24,5);
    //glVertex2f();
    glEnd();

///hill 9///
//polygon1//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(25,3);
    glVertex2f(25.5,4.5);
    glVertex2f(28.5,4.5);
    glVertex2f(29,3);
    //glVertex2f();
    glEnd();

//polygon2//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(25.5,4.5);
    glVertex2f(26,5);
    glVertex2f(28,5);
    glVertex2f(28.5,4.5);
    //glVertex2f();
    glEnd();

///hill 10///
//polygon4//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(29,3);
    glVertex2f(29.5,4);
    glVertex2f(30.5,4);
    glVertex2f(31,3);
    //glVertex2f();
    glEnd();

//triangle//
    glBegin(GL_TRIANGLES);
    glColor3ub(139, 69, 19);
    glVertex2f(29.5,4);
    glVertex2f(30,4.5);
    glVertex2f(30.5,4);
    glEnd();

///hill 11///
//polygon1//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(31,3);
    glVertex2f(31.5,4.5);
    glVertex2f(32.5,4.5);
    glVertex2f(33,3);
    //glVertex2f();
    glEnd();

//triangle//
    glBegin(GL_TRIANGLES);
    glColor3ub(139, 69, 19);
    glVertex2f(31.5,4.5);
    glVertex2f(32.5,4.5);
    glVertex2f(32,5);
    glEnd();

///hill 12///
//polygon1//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(33,3);
    glVertex2f(33.5,4.5);
    glVertex2f(37.5,4.5);
    glVertex2f(38,3);
    //glVertex2f();
    glEnd();

//polygon2//
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(33.5,4.5);
    glVertex2f(34,5);
    glVertex2f(37,5);
    glVertex2f(37.5,4.5);
    //glVertex2f();
    glEnd();

//triangle//
    glBegin(GL_TRIANGLES);
    glColor3ub(139, 69, 19);
    glVertex2f(34,5);
    glVertex2f(37,5);
    glVertex2f(35.5,5.5);
    glEnd();

//Boat
   glBegin(GL_QUADS);
    glColor3ub(139,69,19);
        glVertex2f(1.0f, -14.0f);
        glVertex2f(1.50f, -13.0f);
        glVertex2f(-2.0f, -13.0f);
        glVertex2f(-3.0f, -14.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
        glVertex2f(2.0f, -14.5f);
        glVertex2f(2.0f, -14.0f);
        glVertex2f(-3.0f, -14.0f);
        glVertex2f(-3.0f, -14.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
        glVertex2f(-3.0f, -14.5f);
        glVertex2f(-3.0f, -14.0f);
        glVertex2f(-4.5f, -13.7f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
        glVertex2f(2.0f, -14.5f);
        glVertex2f(3.5f, -13.7f);
        glVertex2f(2.0f, -14.0f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
        glVertex2f(2.0f, -14.0f);
        glVertex2f(1.5f, -13.0f);
        glVertex2f(1.0f, -14.0f);

    glEnd();
     glPopMatrix();




    glutSwapBuffers();//This function is used to swap the front and back buffers of the rendering context
}

    

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1500, 1000);
    glutCreateWindow("Transformation");  
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
