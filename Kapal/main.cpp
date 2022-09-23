#include <windows.h>
#include <GL\glut.h>
#include <math.h>

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

void myInit(void){
	glClearColor(0.1, 0.1, 0.1, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,450,0.0,450);
}

void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);
    int i, j, k, l;
    
    //===============================LAUT===============================

    //laut
    glColor3f(0.184314, 0.184314, 0.309804);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);//kiri bawah
    glVertex2i(450, 0);//kanan bawah
    glVertex2i(450, 175);//kanan atas
    glVertex2i(0, 175);//kiri atas
    glEnd();
    
    //garis arus
    for(i = 0; i < 7; i++){
    	k = rand()%450;
    	l = rand()%160;
    	glColor3f(0.560784, 0.560784, 0.737255);
    	glLineWidth(3.0);
    	glBegin(GL_LINES);
    	glVertex2i(k,l);
    	glVertex2i(k+50,l);
    	glEnd();
	}
    
    //karang 1-1.0
    glColor3f(0.796078, 0.86274, 0.93725);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(175,0);
    glVertex2i(140,75);
    glVertex2i(115,85);
    glVertex2i(100,65);
    glVertex2i(30,90);
    glVertex2i(0,80);
    glEnd();
    
    //karang 1-2.0
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(10,0);
    glVertex2i(165,0);
    glVertex2i(140,65);
    glVertex2i(115,75);
    glVertex2i(100,55);
    glVertex2i(40,80);
    glVertex2i(5,70);
    glEnd();
    
    //karang 2
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(315,50);
    glVertex2i(375,50);
    glVertex2i(365,75);
    glVertex2i(350,75);
    glVertex2i(340,85);
    glVertex2i(330,85);
    glEnd();
    
    
	//===============================BINTANG===============================
    
    //bintang random
    for(i = 0; i < 50; i++){
    	glColor3f(1.0, 1.0, 1.0);
	    glBegin(GL_POINTS);
	    glVertex2f(rand()%450, 180 + rand()%270);//kiri bawah
	    glEnd();
	}
	
	//bintang jatuh
	for(j = 0; j < 5; j++){
		k = 150+rand()%300;
		l = 300+rand()%150;
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2i(k, l);
		glVertex2i(k+50, l+30);
		glVertex2i(k-2, l);
		glEnd();
	}
    
	//===============================BULAN===============================
    
    //bulan luar
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    ngon(100, 380, 380, 30, 0);
    glEnd();
    
    //bulan dalam
    glColor3f(1.0, 1.0, 0.6682);
    glBegin(GL_POLYGON);
	ngon(100, 383, 380, 25, 0);
    glEnd();
    
	//===============================KAPAL===============================
	
	//cerobong
	for(i = 0; i < 3; i++){
		glColor3f(0.329412,0.329412,0.329412);
		glBegin(GL_POLYGON);
		glVertex2i(140+(i*30), 230-(i*10));
		glVertex2i(155+(i*30), 230-(i*10));
		glVertex2i(155+(i*30), 270-(i*10));
		glVertex2i(140+(i*30), 270-(i*10));
		glEnd();
	}
	
	//body kapal
	glColor3f(0.658824,0.658824,0.658824);
	glBegin(GL_POLYGON);
	glVertex2i(100, 160);
	glVertex2i(350, 160);
	glVertex2i(375, 200);
	glVertex2i(375, 230);
	glVertex2i(60, 230);
	glEnd();
	
	//tempat nahkoda
	glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2i(230, 230);
	glVertex2i(350, 230);
	glVertex2i(270, 250);
	glVertex2i(250, 250);
	glEnd();
	
	//ban
	for(i = 0; i < 2; i++){
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.25,0.0);
		ngon(500, 100+(i*25), 210, 10, 0);
		glEnd();
		
		glBegin(GL_POLYGON);
		glColor3f(0.658824,0.658824,0.658824);
		ngon(500, 100+(i*25), 210, 5, 0);
		glEnd();
	}
	
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.25,0.0);
	ngon(500, 175+(i*25), 210, 10, 0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.658824,0.658824,0.658824);
	ngon(500, 175+(i*25), 210, 5, 0);
	glEnd();
	
	for(i = 0; i < 3; i++){
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.25,0.0);
		ngon(500, 300+(i*25), 210, 10, 0);
		glEnd();
		
		glBegin(GL_POLYGON);
		glColor3f(0.658824,0.658824,0.658824);
		ngon(500, 300+(i*25), 210, 5, 0);
		glEnd();
	}

    glFlush();
}

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("KAPAL - CARENS KURNIAWAN WIJAYA - 672019084");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
    return 0;
}
