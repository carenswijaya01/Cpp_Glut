#include <windows.h>
#include <GL\glut.h>
#include <iostream>

using namespace std;

void myInit(void){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 20, 0.0, 13);
}

void myDisplay(void){
	glClear(GL_COLOR_BUFFER_BIT);
	
	float Xa = 11, Ya =  7;
	float Xb = 7, Yb = 7;
	float Xc = 7, Yc = 3;
	float Xd = 11, Yd = 3;
	float Xe = 6, Ye = 6;
	float Xf = 8, Yf = 2;
	float Xg = 6, Yg = 4;
	float Xh = 8, Yh = 8;
	
	//gambar garis
	glColor3f(1.0,0.0,1.0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(Xa, Ya);
	glVertex2f(Xb, Yb);
	glEnd();
	
	glColor3f(0.0,0.0,1.0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(Xc, Yc);
	glVertex2f(Xd, Yd);
	glEnd();
	
	glColor3f(0.0,1.0,0.0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(Xe, Ye);
	glVertex2f(Xf, Yf);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(Xg, Yg);
	glVertex2f(Xh, Yh);
	glEnd();
	
	//rumus perpotongan
	float Mab = (Yb - Ya) / (Xb - Xa);
	float Mcd = (Yd - Yc) / (Xd - Xc);
	float Mef = (Yf - Ye) / (Xf - Xe);
	float Mgh = (Yh - Yg) / (Xh - Xg);
	
	float Cab = Ya - (Mab * Xa);
	float Ccd = Yc - (Mcd * Xc);
	float Cef = Ye - (Mef * Xe);
	float Cgh = Yg - (Mgh * Xg);
	
	//cari titik potong AB - GH
	float X1 = (Cgh - Cab) / (Mab - Mgh);
	float Y1 = (Mab * X1) + Cab;
	
	//cari titik potong CD - EF
	float X2 = (Cef - Ccd) / (Mcd - Mef);
	float Y2 = (Mcd * X2) + Ccd;
	
	//cari titik potong EF - GH
	float X3 = (Cgh - Cef) / (Mef - Mgh);
	float Y3 = (Mef * X3) + Cef;
	
	
	//Gambar titik potong
	glPointSize(7);
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(X1, Y1);
	glEnd();
	
	glPointSize(7);
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(X2, Y2);
	glEnd();
	
	glPointSize(7);
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(X3, Y3);
	glEnd();
	
	/*cout << Mab << endl;
	cout << Mcd << endl;
	cout << Mef << endl;
	cout << Mgh << endl;
	cout << Cab << endl;
	cout << Ccd << endl;
	cout << Cef << endl;
	cout << Cgh << endl;
	cout << X1 << endl;
	cout << Y1 << endl;
	cout << X2 << endl;
	cout << Y2 << endl;
	cout << X3 << endl;
	cout << Y3 << endl;*/
	
	glFlush();
}

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100,100);
	glutCreateWindow("CARENS KURNIAWAN WIJAYA - 672019084");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
    return 0;
}

