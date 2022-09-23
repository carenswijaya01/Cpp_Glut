#include <iostream>
#include <GL/glut.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void init(void){
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glLineWidth(3.0);
	glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0, 15.0); //buat canvas
	glViewport(40,400,60,300); //titik awal titik akhir
}

void ngon(int n, float cx, float cy, float radius, float rotAngle){
    double angle, angleInc;
    int k;
    if (n < 3) return;
    angle = rotAngle * 3.14159265 / 180;
    angleInc = 2 * 3.14159265 / n;

    //Titik pertama
    glVertex2f(radius * cos(angle) + cx, radius * sin(angle) + cy);

    //Titik berikutnya
    for (k = 0; k < n; k++) {
        angle += angleInc;
        glVertex2f(radius * cos(angle) + cx, radius * sin(angle) + cy);
    }
}

void display(void){
	double angleInc, i;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	angleInc=2*3.14159265/500;
	
	//besar kecil bidang
	for(i=0; i<10;i++){
		glBegin(GL_LINE_STRIP);
		ngon(5,0,0,i,180+2*i);
		glEnd();
	}
	
	glFlush();
	glutSwapBuffers();//fungsi perpindahan
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 150);
    glutCreateWindow("N-GON");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
