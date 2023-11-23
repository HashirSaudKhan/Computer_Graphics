#include <iostream>
#include <fstream>
#include <string>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <cmath>

//LAB # 07
/*
class Canvas {
public:
    int width, height;

    Canvas(int width, int height) : width(width), height(height) {}

    void initialize() {
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glMatrixMode(GL_PROJECTION);
        glOrtho(0, width, 0, height, -1.0, 1.0);
    }
    

    void moveTo(float x, float y) {
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);

    }

    void lineTo(float x, float y) {
        glVertex2f(x, y);
    }

    void display() {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 1.0);
        glEnd();
        glFlush();
    }
    void drawingMarker(float x, float y) {

    glBegin(GL_LINE_STRIP);
    glVertex2f(x, y + 10);       // Top
    glVertex2f(x + 2, y + 2);    // Top right
    glVertex2f(x + 10, y);       // Right
    glVertex2f(x + 2, y - 2);    // Bottom right
    glVertex2f(x, y - 10);       // Bottom
    glVertex2f(x - 2, y - 2);    // Bottom left
    glVertex2f(x - 10, y);       // Left
    glVertex2f(x - 2, y + 2);    // Top left
    glVertex2f(x, y + 10);       // Top
    glEnd();
//
//      // Draw the circle
//    glBegin(GL_LINE_STRIP);
//    for (int i = 0; i <= 360; ++i) {
//        float angle = i * 3.14159265 / 180.0;
//        float cx = x + 15 * cos(angle);  // 15 is the radius of the circle
//        float cy = y + 15 * sin(angle);
//        glVertex2f(cx, cy);
//    }
//    glEnd();
}
};

Canvas cvs(700, 400);

void drawMarker() {
	cvs.drawingMarker(0.0, 100.0);
	//1st
    cvs.moveTo(0, 100);
    cvs.lineTo(100, 200);
    cvs.drawingMarker(100.0, 200.0);
    //2nd
    cvs.moveTo(100, 200);
    cvs.lineTo(200, 300);
    cvs.drawingMarker(200.0, 300.0);
    //3rd
    cvs.moveTo(200, 300);
    cvs.lineTo(300, 10);
    cvs.drawingMarker(300.0, 10.0);
    //4th
    cvs.moveTo(300, 10);
    cvs.lineTo(500, 200);
    cvs.drawingMarker(500.0, 200.0);
    //5th
    cvs.moveTo(500,200);
    cvs.lineTo(600, 10);
    cvs.drawingMarker(600.0, 10.0);

}

void display() {
    
    cvs.display();
    drawMarker();
	glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(cvs.width, cvs.height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Marker Drawing");

    cvs.initialize();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
*/

// Example 3.5.1 Model of an arrow 
/*
#include <cmath>
#include <GL/glut.h>

class Canvas {
public:
    int width, height;

    Canvas(int width, int height) : width(width), height(height) {}

    void initialize() {
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glMatrixMode(GL_PROJECTION);
        glOrtho(0, width, 0, height, -1.0, 1.0);
    }

    class Point {
    public:
        float x, y;

        void set(float newX, float newY) {
            x = newX;
            y = newY;
        }
    };

    Point CP;

    void moveTo(float x, float y) {
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        CP.set(x, y);
    }

    void lineTo(float x, float y) {
        glVertex2f(x, y);
        //CP.set(x, y);
    }

    void moveRel(float dx, float dy);

    void lineRel(float dx, float dy);

    void display() {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 1.0);
    }
};

Canvas cvs(700, 400);

void arrow(float f, float h, float t, float w) {
    cvs.lineRel(-w - t / 2, -f); // down the left side
    cvs.lineRel(w, 0);
    cvs.lineRel(0, -h);
    cvs.lineRel(t, 0); // across
    cvs.lineRel(0, h); // back up
    cvs.lineRel(w, 0);
    cvs.lineRel(-w - t / 2, f);
}

void Canvas :: moveRel(float dx, float dy) {// :: scope resolution operator 
    CP.set(CP.x + dx, CP.y + dy);
}
void Canvas :: lineRel(float dx, float dy)
{
    float x = CP.x + dx, y = CP.y + dy;
    lineTo(x, y);
    CP.set(x, y);
}


void display() {
    cvs.display();
    cvs.moveTo(350.0, 300.0);
    arrow(100.0, 120.0, 100.0, 120.0);
    glEnd();  // Add this line to end the GL_LINE_LOOP
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(cvs.width, cvs.height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Arrow  Drawing");

    cvs.initialize();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
*/
/*
//3.5.2 Building a Figure upon a hook motif

#include <cmath>
#include <GL/glut.h>

class Canvas {
public:
    int width, height;
    float CD;

    Canvas(int width, int height) : width(width), height(height) {}

    void initialize() {
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glMatrixMode(GL_PROJECTION);
        glOrtho(0, width, 0, height, -1.0, 1.0);
    }

    class Point {
    public:
        float x, y;

        void set(float newX, float newY) {
            x = newX;
            y = newY;
        }
    };

    Point CP;

    void moveTo(float x, float y) {
        glBegin(GL_LINE_STRIP);
        glVertex2f(x, y);
        CP.set(x, y);
    }

    void lineTo(float x, float y) {
        glVertex2f(x, y);
        CP.set(x, y);
    }

    void moveRel(float dx, float dy);

    void lineRel(float dx, float dy);
    
    void turnTo(float angle);
    
    void turn(float angle);
    
    void forward(float dist, int isVisible);

    void display() {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 1.0);
    }
};

Canvas cvs(700, 400);

void Canvas :: moveRel(float dx, float dy) {// :: scope resolution operator 
    CP.set(CP.x + dx, CP.y + dy);
}
void Canvas :: lineRel(float dx, float dy)
{
    float x = CP.x + dx, y = CP.y + dy;
    lineTo(x, y);
    CP.set(x, y);
}
void Canvas:: turnTo(float angle){
    CD = angle;
}
void Canvas:: turn(float angle){
    CD += angle;
}

void Canvas::forward(float dist, int isVisible)
{
    const float RadPerDeg = 0.017453393; // radians per degree
    float x = CP.x + dist * cos(RadPerDeg * CD);
    float y = CP.y + dist * sin(RadPerDeg * CD);

    if (isVisible)
        lineTo(x, y);
    else
        moveTo(x, y);
}



void display() {
    cvs.display();
    cvs.moveTo(150.0, 280.0);
    cvs.forward(3 * 100, 1); // L is the length of the short sides
    cvs.turn(90);
    cvs.forward(100, 1);
    cvs.turn(90);
    cvs.forward(100, 1);
    cvs.turn(90);
    cvs.forward(3 * 100, 1);
    cvs.turn(90);
    cvs.forward(100, 1);
    cvs.turn(90);
    cvs.forward(100, 1);
    cvs.turn(90);
    cvs.forward(3 * 100, 1);
    cvs.turn(90);
    cvs.forward(100, 1);
    cvs.turn(90);
    cvs.forward(100, 1);
    cvs.turn(90);
    cvs.forward(3 * 100, 1);
    cvs.turn(90);
    cvs.forward(100, 1);
    cvs.turn(90);
    cvs.forward(100, 1);

    glEnd();  // Add this line to end the GL_LINE_LOOP
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(cvs.width, cvs.height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Turtle  Drawing");

    cvs.initialize();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
*/
// 3.5.2 Polyspirals
/*
#include <cmath>
#include <GL/glut.h>

class Canvas {
public:
    int width, height;
    float CD;

    Canvas(int width, int height) : width(width), height(height) {}

    void initialize() {
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glMatrixMode(GL_PROJECTION);
        glOrtho(0, width, 0, height, -1.0, 1.0);
    }

    class Point {
    public:
        float x, y;

        void set(float newX, float newY) {
            x = newX;
            y = newY;
        }
    };

    Point CP;

    void moveTo(float x, float y) {
        glBegin(GL_LINE_STRIP);
        glVertex2f(x, y);
        CP.set(x, y);
    }

    void lineTo(float x, float y) {
        glVertex2f(x, y);
        CP.set(x, y);
    }

    void moveRel(float dx, float dy);

    void lineRel(float dx, float dy);
    
    void turnTo(float angle);
    
    void turn(float angle);
    
    void forward(float dist, int isVisible);

    void display() {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 1.0);
    }
};

Canvas cvs(640, 480);

void Canvas :: moveRel(float dx, float dy) {// :: scope resolution operator 
    CP.set(CP.x + dx, CP.y + dy);
}
void Canvas :: lineRel(float dx, float dy)
{
    float x = CP.x + dx, y = CP.y + dy;
    lineTo(x, y);
    CP.set(x, y);
}
void Canvas:: turnTo(float angle){
    CD = angle;
}
void Canvas:: turn(float angle){
    CD += angle;
}

void Canvas::forward(float dist, int isVisible)
{
    const float RadPerDeg = 0.017453393; // radians per degree
    float x = CP.x + dist * cos(RadPerDeg * CD);
    float y = CP.y + dist * sin(RadPerDeg * CD);

    if (isVisible)
        lineTo(x, y);
    else
        moveTo(x, y);
}

float L = 50.0;
float first_angle = 60.0; 
float Second_angle = 89.5;
float Third_angle = -144.0;
float Fourth_angle = 170.0;

void display() {
    cvs.display();
    cvs.moveTo(240.0, 210.0);
	for (int i = 0; i < 100; i++) {
		cvs.forward(L,1);
		cvs.turn(first_angle);
		//cvs.turn(Second_angle);
		//cvs.turn(Third_angle);
		//cvs.turn(Fourth_angle);
		L  += 2;
	}
	
	glEnd();  // Add this line to end the GL_LINE_LOOP
    glFlush();
	
}

   


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(cvs.width, cvs.height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Turtle  Drawing");

    cvs.initialize(); 

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
*/
/* 
// Practice Exercises.
//3.5.1 Drawing Turtle figuers

#include <cmath>
#include <GL/glut.h>

class Canvas {
public:
    int width, height;
    float CD;

    Canvas(int width, int height) : width(width), height(height) {}

    void initialize() {
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glMatrixMode(GL_PROJECTION);
        glOrtho(0, width, 0, height, -1.0, 1.0);
    }

    class Point {
    public:
        float x, y;

        void set(float newX, float newY) {
            x = newX;
            y = newY;
        }
    };

    Point CP;

    void moveTo(float x, float y) {
        glBegin(GL_LINE_STRIP);
        glVertex2f(x, y);
        CP.set(x, y);
    }

    void lineTo(float x, float y) {
        glVertex2f(x, y);
        CP.set(x, y);
    }

    void moveRel(float dx, float dy);

    void lineRel(float dx, float dy);
    
    void turnTo(float angle);
    
    void turn(float angle);
    
    void forward(float dist, int isVisible);

    void display() {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 1.0);
    }
};

Canvas cvs(700, 400);

void Canvas :: moveRel(float dx, float dy) {// :: scope resolution operator 
    CP.set(CP.x + dx, CP.y + dy);
}
void Canvas :: lineRel(float dx, float dy)
{
    float x = CP.x + dx, y = CP.y + dy;
    lineTo(x, y);
    CP.set(x, y);
}
void Canvas:: turnTo(float angle){
    CD = angle;
}
void Canvas:: turn(float angle){
    CD += angle;
}

void Canvas::forward(float dist, int isVisible)
{
    const float RadPerDeg = 0.017453393; // radians per degree
    float x = CP.x + dist * cos(RadPerDeg * CD);
    float y = CP.y + dist * sin(RadPerDeg * CD);

    if (isVisible >= 1 )
        lineTo(x, y);
    else
        moveTo(x, y);
}

float L = 150.0;
float L1 = 50.0;
float L2 = 100.0;
float L3 = 150.0;
float L4 = 200.0;

void display() {
    cvs.display();
    cvs.moveTo(250.0, 120.0);
    // Part a)
//	for (int i = 0; i < 4; i++) {
//		cvs.forward( L1, 1);
//		cvs.turn(90);
//		cvs.forward(L1, 1);
//		cvs.turn(90);
//		cvs.forward(L1, 1);
//		cvs.turn(90);
//	}
//	for (int i = 0; i < 4; i++) {
//		cvs.forward(L2, 1);
//		cvs.turn(90);
//		cvs.forward(L2, 1);
//		cvs.turn(90);
//		cvs.forward(L2, 1);
//		cvs.turn(90);
//	}
//	for (int i = 0; i < 4; i++) {
//		cvs.forward(L3, 1);
//		cvs.turn(90);
//		cvs.forward(L3, 1);
//		cvs.turn(90);
//		cvs.forward(L3, 1);
//		cvs.turn(90);
//	}
//	for (int i = 0; i < 4; i++) {
//		cvs.forward(L4, 1);
//		cvs.turn(90);
//		cvs.forward(L4, 1);
//		cvs.turn(90);
//		cvs.forward(L4, 1);
//		cvs.turn(90);
//	}

    //Part b)
    
//    	for (int i = 0; i < 8; i++) {
//    		cvs.forward(L - (i * 20), 1);
//	        cvs.turn(90);
//	        cvs.forward(L - (i * 20), 1);
//	        cvs.turn(90);
//
//	}
    
    //Part c)
    
//    cvs.forward(L/2, 1);
//	cvs.turn(120);
//	cvs.forward(L/1, 1);
//	cvs.turn(120);
//	cvs.forward(L/1, 1);
//	cvs.turn(120);
//	cvs.forward(L/2, 1);
//	cvs.turn(60);
//	cvs.forward(L/2, 1);
//    cvs.turn(120);
//	cvs.forward(L/2, 1);
//	cvs.turn(120);
//	cvs.forward(L/2, 1);

	

	glEnd();  // Add this line to end the GL_LINE_LOOP
    glFlush();
	
}

   


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(cvs.width, cvs.height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Turtle  Drawing");

    cvs.initialize();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
*/

/*
//3.5.2 Drawing a Well-known logo
#include <cmath>
#include <GL/glut.h>

class Canvas {
public:
    int width, height;
    float CD;

    Canvas(int width, int height) : width(width), height(height) {}

    void initialize() {
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glMatrixMode(GL_PROJECTION);
        glOrtho(0, width, 0, height, -1.0, 1.0);
    }

    class Point {
    public:
        float x, y;

        void set(float newX, float newY) {
            x = newX;
            y = newY;
        }
    };

    Point CP;

    void moveTo(float x, float y) {
        glBegin(GL_LINE_STRIP);
        glVertex2f(x, y);
        CP.set(x, y);
    }

    void lineTo(float x, float y) {
        glVertex2f(x, y);
        CP.set(x, y);
    }

    void moveRel(float dx, float dy);

    void lineRel(float dx, float dy);
    
    void turnTo(float angle);
    
    void turn(float angle);
    
    void forward(float dist, int isVisible);

    void display() {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 1.0);
    }
};

Canvas cvs(700, 400);

void Canvas :: moveRel(float dx, float dy) {// :: scope resolution operator 
    CP.set(CP.x + dx, CP.y + dy);
}
void Canvas :: lineRel(float dx, float dy)
{
    float x = CP.x + dx, y = CP.y + dy;
    lineTo(x, y);
    CP.set(x, y);
}
void Canvas:: turnTo(float angle){
    CD = angle;
}
void Canvas:: turn(float angle){
    CD += angle;
}

void Canvas::forward(float dist, int isVisible)
{
    const float RadPerDeg = 0.017453393; // radians per degree
    float x = CP.x + dist * cos(RadPerDeg * CD);
    float y = CP.y + dist * sin(RadPerDeg * CD);

    if (isVisible)
        lineTo(x, y);
    else
        moveTo(x, y);
}

float L = 80.0;

void display() {
    cvs.display();
    cvs.moveTo(300.0, 220.0);
        //1
        cvs.turn(60);// /
		cvs.forward(L, 1); // /
		
		cvs.turn(60);// \.
		cvs.forward(L, 1); // \.
		
		cvs.turn(120); // /
		cvs.forward(L, 1);// /
		
		cvs.turn(60); // \.
		cvs.forward(L, 1); // \.
		
		//2
		cvs.turn(60); // -
		cvs.forward(L, 1);// -
		
		cvs.turn(-60);// \.
		cvs.forward(L, 1);// \.
		
		cvs.turn(-120);// _
		cvs.forward(L, 1);// _
		
		cvs.turn(-60);// \.
		cvs.forward(L, 1);// \.
		
		//3
		cvs.turn(60);// _
		cvs.forward(L, 1);// _
		
		cvs.turn(60);// /
		cvs.forward(L, 1);// /
		
		cvs.turn(120);// _
		cvs.forward(L, 1);// _
		
		cvs.turn(60);// /
		cvs.forward(L, 1); // /

	glEnd();  // Add this line to end the GL_LINE_LOOP
    glFlush();
	
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(cvs.width, cvs.height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Turtle  Drawing");

    cvs.initialize();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
*/

/*
//3.5.3 Driving the Turtle with Strings
#include <cmath>
#include <GL/glut.h>

using namespace std;

//int screenWidth = 640;
//int screenHeight = 480;

class Canvas {
public:
	float x, y;
	int Width = 640;
    int Height = 480;
	float CD;
	
	Canvas() {
		this->x = 225;
		this->y = 200;
	}
	
	void initialize();
	void turnTo(float angle);
	void turn(float angle) ;
	void lineTo(float x, float y);
	void moveTo(float x, float y);
	void forward(float dist, int isVisible);
	void display();
};

void Canvas :: initialize() {
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glMatrixMode(GL_PROJECTION);
        glOrtho(0, Width, 0, Height, -1.0, 1.0);
    }
    
void Canvas :: turnTo(float angle) {
		this->CD = angle;
	}
	
void Canvas :: turn(float angle) {
		this->CD += angle;
	}
	
void Canvas :: lineTo(float x, float y) {
	float t_x = x; float t_y = y;
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(this->x, this->y);
	glVertex2f(x, y);
	glEnd();
	glFlush();
	moveTo(t_x, t_y);
	}
	
void Canvas :: moveTo(float x, float y) {
	this->x = x;
	this->y = y;

	}

void Canvas :: forward(float dist, int isVisible) {
	const float RadPerDeg = 0.017453393;
	float x = this->x + dist * cos(RadPerDeg * this->CD);
	float y = this->y + dist * sin(RadPerDeg * this->CD);
	if (isVisible >= 1) {
		lineTo(x, y);
	}
	else {
		moveTo(x, y);
	}
}
void Canvas :: display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glFlush();
}

Canvas cvs;

void display() {
	cvs.display();
}

// 3.5.3 Driving the turtle with strings
void myKeys(unsigned char key, int x, int y) {
	int L = 30;
	switch (key) {
	case 'f':
		cvs.forward(L, 1);
		break;
	case 'l':
		cvs.turn(60);
		break;
	case 'r':
		cvs.turn(-60);
		break;
	}

}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(cvs.Width, cvs.Height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3.5.3 Driving the Turtle with Strings");
    cvs.initialize();
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeys);

    glutMainLoop();

    return 0;
}
*/
/*
//3.5.4 Driving the Meander
#include <cmath>
#include <GL/glut.h>

class Canvas {
public:
    int width, height;
    float CD;

    //Canvas(int width, int height) : width(width), height(height) {}
    Canvas(int width, int height){
	this->width = width;
	this->height = height;
	}

    void initialize() {
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glMatrixMode(GL_PROJECTION);
        glOrtho(0, width, 0, height, -1.0, 1.0);
    }

    class Point {
    public:
        float x, y;

        void set(float newX, float newY) {
            x = newX;
            y = newY;
        }
    };

    Point CP;

    void moveTo(float x, float y) {
        glBegin(GL_LINE_STRIP);
        glVertex2f(x, y);
        CP.set(x, y);
    }

    void lineTo(float x, float y) {
        glVertex2f(x, y);
        CP.set(x, y);
    }

    void moveRel(float dx, float dy);

    void lineRel(float dx, float dy);
    
    void turnTo(float angle);
    
    void turn(float angle);
    
    void forward(float dist, int isVisible);
    
    void Meander(float dist);

    void display() {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 1.0);
    }
};

Canvas cvs(700, 400);

void Canvas :: moveRel(float dx, float dy) {// :: scope resolution operator 
    CP.set(CP.x + dx, CP.y + dy);
}
void Canvas :: lineRel(float dx, float dy)
{
    float x = CP.x + dx, y = CP.y + dy;
    lineTo(x, y);
    CP.set(x, y);
}
void Canvas:: turnTo(float angle){
    CD = angle;
}
void Canvas:: turn(float angle){
    CD += angle;
}

void Canvas::forward(float dist, int isVisible)
{
    const float RadPerDeg = 0.017453393; // radians per degree
    float x = CP.x + dist * cos(RadPerDeg * CD);
    float y = CP.y + dist * sin(RadPerDeg * CD);

    if (isVisible)
        lineTo(x, y);
    else
        moveTo(x, y);
}

void Canvas::Meander(float L){
    cvs.forward(L/1.3333, 1); // L/1.333 = 75
    cvs.turn(90);
    
    cvs.forward(L/2,1);
    cvs.turn(90);
    
    cvs.forward(L/4,1);
    cvs.turn(90);
    
    cvs.forward(L/4,1);
    cvs.turn(-90);
  
    cvs.forward(L/4,1);
    cvs.turn(-90);
    
	cvs.forward(L/2,1);
    cvs.turn(-90);
	
	cvs.forward(L/1.33333,1);
	cvs.turn(-90);
	
	cvs.forward(L/1.33333,1);
	cvs.turn(90);	
	
}

float number_of_Meanders = 4;

void display() {
    cvs.display();
    cvs.moveTo(50.0, 150.0);
    
    for (int i = 0; i < number_of_Meanders; i++) {
	   cvs.Meander(100);	
}
	
	glEnd();  // Add this line to end the GL_LINE_LOOP
    glFlush();
	
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(cvs.width, cvs.height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Turtle  Drawing");

    cvs.initialize();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
*/





