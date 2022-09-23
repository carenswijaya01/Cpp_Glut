#include <windows.h>
#include <GL\glut.h>

void myInit(void){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,300,0.0,300);
}

void myDisplay(void){
	glClear(GL_COLOR_BUFFER_BIT);
	
	float A1x = 50, A1y = 50, B1x = 120, B1y = 200,
	A2x = 50, A2y = 160, B2x = 200, B2y = 160,
	A3x = 200, A3y = 200, B3x = 130, B3y = 50,
	A4x = 50, A4y = 90, B4x = 200, B4y = 90;
	
	float Mab1, Mab2, Mab3, Mab4, Cab1, Cab2, Cab3, Cab4;
	
	float Px1, Py1, Px2, Py2, Px3, Py3, Px4, Py4;
	
	//gambar garis
	glColor3f(1.0,1.0,0.0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(A1x, A1y);
	glVertex2f(B1x, B1y);
	glEnd();
	
	glColor3f(0.0,0.0,1.0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(A2x, A2y);
	glVertex2f(B2x, B2y);
	glEnd();
	
	glColor3f(0.0,1.0,0.0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(A3x, A3y);
	glVertex2f(B3x, B3y);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(A4x, A4y);
	glVertex2f(B4x, B4y);
	glEnd();
	
	//rumus perpotongan
	Mab1 = (B1y - A1y) / (B1x - A1x);
	Mab2 = (B2y - A2y) / (B2x - A2x);
	Mab3 = (B3y - A3y) / (B3x - A3x);
	Mab4 = (B4y - A4y) / (B4x - A4x);
	
	Cab1 = A1y - (A1x*Mab1);
	Cab2 = A2y - (A2x*Mab2);
	Cab3 = A3y - (A3x*Mab3);
	Cab4 = A4y - (A4x*Mab4);
	
	//cari titik potong 1-2
	Px1 = (Cab2-Cab1) / (Mab1 - Mab2);
	Py1 = (Mab1 * Px1) + Cab1;
	
	//cari titik potong 3-2
	Px2 = (Cab3-Cab2) / (Mab2 - Mab3);
	Py2 = (Mab2 * Px2) + Cab2;
	
	//cari titik potong 4-3
	Px3 = (Cab3-Cab4) / (Mab4 - Mab3);
	Py3 = (Mab3 * Px3) + Cab3;
	
	//cari titik potong 1-4
	Px4 = (Cab4-Cab1) / (Mab1 - Mab4);
	Py4 = (Mab4 * Px4) + Cab4;
	
	
	//Gambar titik potong
	glPointSize(7);
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(Px1, Py1);
	glEnd();
	
	glPointSize(7);
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(Px2, Py2);
	glEnd();
	
	glPointSize(7);
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(Px3, Py3);
	glEnd();
	
	glPointSize(7);
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(Px4, Py4);
	glEnd();
	
	//bikin border
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(A1x, B1y);
	glVertex2f(A3x, B1y);
	glVertex2f(A3x, B3y);
	glVertex2f(A2x, B3y);
	glEnd();
	
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
