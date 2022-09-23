#include <iostream>
#include <windows.h>
#include <GL\glut.h>
#include <math.h>

float angle = 0.0f; //sudut awal
float delta_angle = 30.0f; //perubahan sudut
float translasi;//nilai translasi
float scale;//nilai scaling
float r,g,b;//buat warna

bool cek = false;

void ngon(int n, float cx, float cy, float radius, float rotAngle){
    double angle, angleInc;
    int k;
    if (n < 3) return;
    angle = rotAngle * 3.14159265 / 180;
    angleInc = 2 * 3.14159265 / n;

    glVertex2f(radius * cos(angle) + cx, radius * sin(angle) + cy);

    for (k = 0; k < n; k++) {
        angle += angleInc;
        glVertex2f(radius * cos(angle) + cx, radius * sin(angle) + cy);
    }
}

void timer(int){
	glutPostRedisplay();
	glutTimerFunc(500, timer, 0);
	angle += delta_angle;
}

void myInit(void){
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50.0, 50.0, -50.0, 50.0);
}

void myDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	//buat background
	r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	glColor3f(r,g,b);
	glBegin(GL_POLYGON);
	ngon(4, 0.0, 0.0, 75.0, 45.0);
	glEnd();
	
	
	//buat segi 4 sama 8 muter searah
	glPushMatrix();
		//bikin semua muter
		glRotatef(angle, 0.0f, 0.0f, 1.0f);
		
		//bikin segi 8
		r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		glColor3f(r,g,b);
		glBegin(GL_POLYGON);
			ngon(8, 0.0f, 0.0f, 10, 0.0f);
		glEnd();
		
		//translasi selang seling
		if(cek){
			translasi = 7.0f;
			scale = 0.8f;
		}else{
			translasi = 10.0f;
			scale = 1.0f;
		}
		glTranslatef(translasi, translasi, 0.0f);
		glScalef(scale, scale, 1.0f);
		cek = !cek;
		
		//bikin segi 4
		r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		glColor3f(r,g,b);
		glBegin(GL_POLYGON);
			ngon(4, 0.0f, 30.0f, 5, 0.0f);
		glEnd();
	glPopMatrix();
	
	//buat lingkaran
	glPushMatrix();
		//dikali -1 biar arahnya berlawanan, scaling translate samain aja
		glRotatef(angle*(-1),0.0f, 0.0f, 1.0f);
		glScalef(scale, scale, 1.0f);
		glTranslatef(translasi, translasi, 0.0f);
		
		//bikin lingkarannya
		r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		glColor3f(r,g,b);
		glBegin(GL_POLYGON);
			ngon(500, 0.0f, 15.0f, 5, 0.0f);
		glEnd();
	glPopMatrix();
	glutSwapBuffers();
}

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("CARENS KURNIAWAN WIJAYA - 672019084");
	glutDisplayFunc(myDisplay);
	myInit();
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
    return 0;
}
