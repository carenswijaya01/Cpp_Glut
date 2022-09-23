#include <iostream>
#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void ngon(int n, float cx, float cy, float radius, float rotAngle){
    double angle, angleInc;
    int k;

    if(n<3) return;
    angle=rotAngle*3.14159265/180;
    angleInc=2*3.14159265/n;

    glVertex2f(radius*cos(angle)+cx, radius*sin(angle)+cy);

    for(k=0;k<n;k++){
        angle+=angleInc;
        glVertex2f(radius*cos(angle)+cx, radius*sin(angle)+cy);
    }
}

void init(void){
	glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glLineWidth(3.0);
	glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0, 15.0);
	glViewport(40,400,60,300);
}

void display(void){
	int i,j,k=1,l;
	glClear(GL_COLOR_BUFFER_BIT);

	//bikin pola lingkaran
	for(i = 0; i < 2; i++){
		if(i%2 == 0){//kalo lapis 1
			for(j = 0; j < 2; j++){
				for(l = 0; l<70; l++){
					glBegin(GL_LINES);
					glColor3f(0.0,0.0+(0.05*l),0.0+(0.1*l));
					ngon(500,7*k,0,7-(0.1*l),0);
					glEnd();
				}
				k = k * -1;
			}
			
			for(j = 0; j < 2; j++){
				for(l = 0; l<70; l++){
					glBegin(GL_LINES);
					glColor3f(0.0,0.0+(0.05*l),0.0+(0.1*l));
					ngon(500,0,7*k,7-(0.1*l),0);
					glEnd();
				}
				k = k * -1;
			}
		}else{//kalo lapis 2
			for(j = 0; j < 2; j++){
				for(l = 0; l < 50; l++){
					glBegin(GL_LINES);
					glColor3f(0.0,0.0+(0.1*l),0.0+(0.05*l));
					ngon(500,6*k,6*k,6-(0.1*l),0);
					glEnd();
				}
				k = k * -1;
			}
			
			for(j = 0; j < 2; j++){
				for(l = 0; l < 50; l++){
					glBegin(GL_LINES);
					glColor3f(0.0,0.0+(0.1*l),0.0+(0.05*l));
					ngon(500,-6*k,6*k,6-(0.1*l),0);
					glEnd();
				}
				k = k * -1;
			}
		}
	}
	
	//bikin segi 6 besar
	for(i = 0; i < 25; i++){
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0+(0.75*i),0.0,0.0+(0.2*i));
		ngon(6,0,0,8-(0.4*i),90);
		glEnd();
	}
	
	//bikin segitiga
	for(i = 0; i < 20; i++){
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0+(0.1*i),0.0,0.0+(0.05*i));
		ngon(3,0,0,8-(0.4*i),90);
		glEnd();
	}
	
	//bikin segi 6 kecil
	for(i = 0; i < 10; i++){
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0+(0.1*i),0.0+(0.2*i),0.0);
		ngon(6,0,0,3-(0.3*i),90);
		glEnd();
	}
	
	glFlush();
	glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 150);
    glutCreateWindow("Ornamen Carens- 672019084");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
