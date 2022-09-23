#include <iostream>
#include <GL/glut.h>
#include <windows.h>

void myInit(void){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void){
	glColor3f(0.0,1.0,0.0);//atur warna
	glRectf(300.0, 200.0, 400.0, 300.0);
	
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	
	//translasi (geser)
	//glTranslatef(277.5,-176.5,0); //parameter x,y,z
	
	//rotasi (muter)
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f); //parameter derajat, x, y, z
	
	//skala (perbesaran)
	//glScalef(0.5f, 0.5f, 1.0f); //parameter x,y,z
	
	glRectf(300.0, 200.0, 400.0, 300.0);
	glPopMatrix();
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Transformasi");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}
