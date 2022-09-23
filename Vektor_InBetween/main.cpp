#include <iostream>
#include <Windows.h>
#include <GL/glut.h>
#include <stdlib.h>

void myInit(void)
 {
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
 	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 75.0, 0.0, 15.0);
}


class GLintPoint
{
public:
		GLint x, y;
};


class Point2
{
public:
	float x,y;
	void set(float dx,float dy)
	{
		x = dx;
		y = dy;
	}
	void set(Point2 &p)
	{
		x = p.x;
		y = p.y;
	}
	Point2(float xx,float yy)
	{
		x = xx;
		y = yy;
	}
	Point2()
	{
		x = y = 0;
	}
};


GLintPoint CP;


float lerp (float a, float b, float t)
{
	return a + (b - a) *t;
}


Point2 Tween(Point2 A, Point2 B ,float t)
	{
		Point2 P;
		P.x = lerp(A.x,B.x,t);
		P.y = lerp(A.y,B.y,t);
		return P;
	}


void moveTo(GLint x ,GLint y)
{
	CP.x = x; CP.y = y;
}


void lineTo(GLint x ,GLint y)
{
	glBegin (GL_LINES);
	glVertex2i(CP.x,CP.y);
	glVertex2i(x,y);
	glEnd();
	glutSwapBuffers();
	CP.x = x; CP.y = y;
}


void drawTween (Point2 A[], Point2 B[], int n, float t)
{
     for (int i = 0; i < n; i++)
     {
        Point2 P;
        P = Tween (A[i], B[i], t);
        if (i == 0) moveTo (P.x, P.y);
        else lineTo (P.x, P.y);
       }
}


void myDisplay(void)
{
	int x;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);

	Point2 A[8];
		A [0].set(4,2);
		A [1].set(12,2);
		A [2].set(12,8);
		A [3].set(2,8);
		A [4].set(8,12);
		A [5].set(14,8);
		A [6].set(4,8);
		A [7].set(4,2);

	Point2 B[8];
		B [0].set (66,2);
		B [1].set (70,2);
		B [2].set (68,4);
		B [3].set (62,8);
		B [4].set (68,12);
		B [5].set (74,8);
		B [6].set (68,4);
		B [7].set (66,2);

	glColor3f(1,0,0);
	drawTween(A,B,8,0.0);

	glColor3f(0,0,1);
	for(x=1;x<=5;x+=1)
	{
		drawTween(A,B,8,0.17*x);
	}

	glColor3f(1,0,0);
	drawTween(A,B,8,0.991);

	glFlush();
	glutSwapBuffers();
}

main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
	glutInitWindowSize(1000,300);
	glutInitWindowPosition(100,150);
	glutCreateWindow("RUMAH JADI LAYANGAN - CARENS KURNIAWAN WIJAYA (672019084)");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
