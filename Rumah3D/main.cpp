/*#include <iostream>
#include <GL/glut.h>
#include <windows.h>

//SOAL BONUS
//Asal Kak Devy = Toraja, Kak Fanny = Medan, Kak Benedict = Tangerang

int is_depth;
int cekAsbes = 1;
int kbmouse = 0;

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

void myInit(void){
	glClearColor(0.74902, 0.847059, 0.847059, 0.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	is_depth=1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);
}

void asbes_pintu(){
	//pintu depan
	glColor3f(0.29, 0.46, 0.43);
	glBegin(GL_POLYGON);
	glVertex3f(-25.0, -13.0, 10.0);
	glVertex3f(-25.0, 7.0, 10.0);
	glVertex3f(25.0, 7.0, 10.0);
	glVertex3f(25.0, -13.0, 10.0);
	glEnd();
	
	//asbes
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-33.0, 7.0, -20.0);
	glVertex3f(33.0, 7.0, -20.0);
	glVertex3f(33.0, 13.0, -40.0);
	glVertex3f(-33.0, 13.0, -40.0);
	glEnd();
}

void rumahdepan(){
	//depan kiri
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-33.0, -13.0, 10.0);
	glVertex3f(-25.0, -13.0, 10.0);
	glVertex3f(-25.0, 13.0, 10.0);
	glVertex3f(-33.0, 13.0, 10.0);
	glEnd();
	
	//depan tengah
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-25.0, 7.0, 10.0);
	glVertex3f(25.0, 7.0, 10.0);
	glVertex3f(25.0, 13.0, 10.0);
	glVertex3f(-25.0, 13.0, 10.0);
	glEnd();
	
	//depan kanan
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(25.0, -13.0, 10.0);
	glVertex3f(33.0, -13.0, 10.0);
	glVertex3f(33.0, 13.0, 10.0);
	glVertex3f(25.0, 13.0, 10.0);
	glEnd();
	
	//sekat tengah kiri
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-33.0, -13.0, -20.0);
	glVertex3f(-25.0, -13.0, -20.0);
	glVertex3f(-25.0, 13.0, -20.0);
	glVertex3f(-33.0, 13.0, -20.0);
	glEnd();
	
	//sekat tengah tengah
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-25.0, 7.0, -20.0);
	glVertex3f(3.0, 7.0, -20.0);
	glVertex3f(3.0, 13.0, -20.0);
	glVertex3f(-25.0, 13.0, -20.0);
	glEnd();
	
	//sekat tengah kanan
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(3.0, -13.0, -20.0);
	glVertex3f(33.0, -13.0, -20.0);
	glVertex3f(33.0, 13.0, -20.0);
	glVertex3f(3.0, 13.0, -20.0);
	glEnd();
	
	//kanan
	glBegin(GL_QUADS);
	glColor3f(0.65, 0.50, 0.39);
	glVertex3f(33.0, 13.0, 10.0);
	glVertex3f(33.0, -13.0, 10.0);
	glVertex3f(33.0, -13.0, -20.0);
	glVertex3f(33.0, 13.0, -20.0);
	glEnd();
	
	//kiri
	glBegin(GL_QUADS);
	glColor3f(0.65, 0.50, 0.39);
	glVertex3f(-33.0, 13.0, 10.0);
	glVertex3f(-33.0, -13.0, 10.0);
	glVertex3f(-33.0, -13.0, -20.0);
	glVertex3f(-33.0, 13.0, -20.0);
	glEnd();
	
	//atas
	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-33.0, 13.0, 10.0);
	glVertex3f(33.0, 13.0, 10.0);
	glVertex3f(33.0, 13.0, -20.0);
	glVertex3f(-33.0, 13.0, -20.0);
	glEnd();
}

void halamantengah(){
	//tembok kanan
	glBegin(GL_QUADS);
	glColor3f(0.65, 0.50, 0.39);
	glVertex3f(33.0, 7.0, -20.0);
	glVertex3f(33.0, -13.0, -20.0);
	glVertex3f(33.0, -13.0, -40.0);
	glVertex3f(33.0, 7.0, -40.0);
	glEnd();
	
	//tembok kiri
	glBegin(GL_QUADS);
	glColor3f(0.65, 0.50, 0.39);
	glVertex3f(-33.0, 7.0, -20.0);
	glVertex3f(-33.0, -13.0, -20.0);
	glVertex3f(-33.0, -13.0, -40.0);
	glVertex3f(-33.0, 7.0, -40.0);
	glEnd();
}

void rumahbelakang(){
	//depan kiri
	glBegin(GL_POLYGON);
	glColor3f(0.91, 0.76, 0.65);
	glVertex3f(-33.0, -13.0, -40.0);
	glVertex3f(-18.0, -13.0, -40.0);
	glVertex3f(-18.0, 20.0, -40.0);
	glVertex3f(-33.0, 20.0, -40.0);
	glEnd();
	
	//depan tengah
	glBegin(GL_POLYGON);
	glColor3f(0.91, 0.76, 0.65);
	glVertex3f(-18.0, 5.0, -40.0);
	glVertex3f(18.0, 5.0, -40.0);
	glVertex3f(18.0, 20.0, -40.0);
	glVertex3f(-18.0, 20.0, -40.0);
	glEnd();
	
	//depan kanan
	glBegin(GL_POLYGON);
	glColor3f(0.91, 0.76, 0.65);
	glVertex3f(18.0, -13.0, -40.0);
	glVertex3f(33.0, -13.0, -40.0);
	glVertex3f(33.0, 20.0, -40.0);
	glVertex3f(18.0, 20.0, -40.0);
	glEnd();
	
	//belakang-1.1
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(-33.0, -13.0, -50.0);
	glVertex3f(-33.0, 40.0, -50.0);
	glVertex3f(-28.0, 40.0, -50.0);
	glVertex3f(-28.0, -13.0, -50.0);
	glEnd();
	
	//belakang-1.2
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(-20.0, -13.0, -50.0);
	glVertex3f(-20.0, 40.0, -50.0);
	glVertex3f(-18.0, 40.0, -50.0);
	glVertex3f(-18.0, -13.0, -50.0);
	glEnd();
	
	//belakang-1.3
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(-13.0, -13.0, -50.0);
	glVertex3f(-13.0, 40.0, -50.0);
	glVertex3f(-10.0, 40.0, -50.0);
	glVertex3f(-10.0, -13.0, -50.0);
	glEnd();
	
	//belakang-1.4
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(-2.0, -13.0, -50.0);
	glVertex3f(-2.0, 40.0, -50.0);
	glVertex3f(0.0, 40.0, -50.0);
	glVertex3f(0.0, -13.0, -50.0);
	glEnd();
	
	//belakang-1.5
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(5.0, -13.0, -50.0);
	glVertex3f(5.0, 40.0, -50.0);
	glVertex3f(8.0, 40.0, -50.0);
	glVertex3f(8.0, -13.0, -50.0);
	glEnd();
	
	//belakang-1.6
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(13.0, -13.0, -50.0);
	glVertex3f(13.0, 40.0, -50.0);
	glVertex3f(15.0, 40.0, -50.0);
	glVertex3f(15.0, -13.0, -50.0);
	glEnd();
	
	//belakang-1.7
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(23.0, -13.0, -50.0);
	glVertex3f(23.0, 40.0, -50.0);
	glVertex3f(33.0, 40.0, -50.0);
	glVertex3f(33.0, -13.0, -50.0);
	glEnd();
	
	//belakang-1.Atas
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(-33.0, 30.0, -50.0);
	glVertex3f(-33.0, 40.0, -50.0);
	glVertex3f(33.0, 40.0, -50.0);
	glVertex3f(33.0, 30.0, -50.0);
	glEnd();
	
	//Tengah.Atas
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(-33.0, 3.0, -50.0);
	glVertex3f(-33.0, 15.0, -50.0);
	glVertex3f(33.0, 15.0, -50.0);
	glVertex3f(33.0, 3.0, -50.0);
	glEnd();
	
	//belakang-1.Bawah.1
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(-28.0, -13.0, -50.0);
	glVertex3f(-28.0, 20.0, -50.0);
	glVertex3f(-20.0, 20.0, -50.0);
	glVertex3f(-20.0, -13.0, -50.0);
	glEnd();
	
	//belakang-1.Bawah.2
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(-10.0, -13.0, -50.0);
	glVertex3f(-10.0, 20.0, -50.0);
	glVertex3f(-2.0, 20.0, -50.0);
	glVertex3f(-2.0, -13.0, -50.0);
	glEnd();
	
	//belakang-1.Bawah.3
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(15.0, -13.0, -50.0);
	glVertex3f(15.0, 20.0, -50.0);
	glVertex3f(23.0, 20.0, -50.0);
	glVertex3f(23.0, -13.0, -50.0);
	glEnd();
	
	//tembok kanan
	glBegin(GL_POLYGON);
	glColor3f(0.65, 0.50, 0.39);
	glVertex3f(33.0, 40.0, -50.0);
	glVertex3f(33.0, 35.0, -40.0);
	glVertex3f(33.0, -13.0, -40.0);
	glVertex3f(33.0, -13.0, -60.0);
	glVertex3f(33.0, 35.0, -60.0);
	glEnd();
	
	//tembok kiri
	glBegin(GL_POLYGON);
	glColor3f(0.65, 0.50, 0.39);
	glVertex3f(-33.0, 40.0, -50.0);
	glVertex3f(-33.0, 35.0, -40.0);
	glVertex3f(-33.0, -13.0, -40.0);
	glVertex3f(-33.0, -13.0, -60.0);
	glVertex3f(-33.0, 35.0, -60.0);
	glEnd();
	
	//belakang-2
	glBegin(GL_QUADS);
	glColor3f(0.65, 0.50, 0.39);
	glVertex3f(-33.0, -13.0, -60.0);
	glVertex3f(-33.0, 35.0, -60.0);
	glVertex3f(33.0, 35.0, -60.0);
	glVertex3f(33.0, -13.0, -60.0);
	glEnd();
	
	//belakang-2.1
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-33.0, -13.0, -59.9);
	glVertex3f(-33.0, 35.0, -59.9);
	glVertex3f(33.0, 35.0, -59.9);
	glVertex3f(33.0, -13.0, -59.9);
	glEnd();
	
	//lantai 2
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-33.0, 15.0, -40.0);
	glVertex3f(33.0, 15.0, -40.0);
	glVertex3f(33.0, 15.0, -60.0);
	glVertex3f(-33.0, 15.0, -60.0);
	glEnd();
	
	//atap depan
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(-35.0, 34.0, -38.0);
	glVertex3f(35.0, 34.0, -38.0);
	glVertex3f(35.0, 40.0, -50.0);
	glVertex3f(-35.0, 40.0, -50.0);
	glEnd();
	
	//atap belakang
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(-35.0, 34.0, -62.0);
	glVertex3f(35.0, 34.0, -62.0);
	glVertex3f(35.0, 40.0, -50.0);
	glVertex3f(-35.0, 40.0, -50.0);
	glEnd();
	
	//pintu
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(-18.0, 15.0, -55);
	glVertex3f(-13.0, 15.0, -50);
	glVertex3f(-13.0, 30.0, -50);
	glVertex3f(-18.0, 30.0, -55);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(0.0, 15.0, -55);
	glVertex3f(5.0, 15.0, -50);
	glVertex3f(5.0, 30.0, -50);
	glVertex3f(0.0, 30.0, -55);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(8.0, 15.0, -50);
	glVertex3f(13.0, 15.0, -55);
	glVertex3f(13.0, 30.0, -55);
	glVertex3f(8.0, 30.0, -50);
	glEnd();
	
	//jendela
	glBegin(GL_LINE_LOOP);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(-28.0, 20.0, -48.0);
	glVertex3f(-28.0, 30.0, -50.0);
	glVertex3f(-20.0, 30.0, -50.0);
	glVertex3f(-20.0, 20.0, -48.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(-10.0, 20.0, -48.0);
	glVertex3f(-10.0, 30.0, -50.0);
	glVertex3f(-2.0, 30.0, -50.0);
	glVertex3f(-2.0, 20.0, -48.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(15.0, 20.0, -48.0);
	glVertex3f(15.0, 30.0, -50.0);
	glVertex3f(23.0, 30.0, -50.0);
	glVertex3f(23.0, 20.0, -48.0);
	glEnd();
	
	//kaca
	glBegin(GL_POLYGON);
	glColor4f(0.0, 0.0, 0.0, 0.7);
	glVertex3f(-28.0, 20.0, -48.0);
	glVertex3f(-28.0, 30.0, -50.0);
	glVertex3f(-20.0, 30.0, -50.0);
	glVertex3f(-20.0, 20.0, -48.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor4f(0.0, 0.0, 0.0, 0.7);
	glVertex3f(-10.0, 20.0, -48.0);
	glVertex3f(-10.0, 30.0, -50.0);
	glVertex3f(-2.0, 30.0, -50.0);
	glVertex3f(-2.0, 20.0, -48.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor4f(0.0, 0.0, 0.0, 0.7);
	glVertex3f(15.0, 20.0, -48.0);
	glVertex3f(15.0, 30.0, -50.0);
	glVertex3f(23.0, 30.0, -50.0);
	glVertex3f(23.0, 20.0, -48.0);
	glEnd();
}

void objekdalam(){
	//meja
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(15.0, -7.0, -23.0);
	glVertex3f(28.0, -7.0, -23.0);
	glVertex3f(28.0, -7.0, -36.0);
	glVertex3f(15.0, -7.0, -36.0);
	glEnd();
	
	//tiang meja
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(21.5, -7.0, -29.5);
	glVertex3f(21.5, -12.9, -29.5);
	glEnd();
	
	//kaki meja
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(18.0, -12.9, -26.0);
	glVertex3f(25.0, -12.9, -26.0);
	glVertex3f(25.0, -12.9, -33.0);
	glVertex3f(18.0, -12.9, -33.0);
	glEnd();
	
	//lemari atas
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(-33.0, -4.0, -23.0);
	glVertex3f(-25.0, -4.0, -23.0);
	glVertex3f(-25.0, -4.0, -39.9);
	glVertex3f(-33.0, -4.0, -39.9);
	glEnd();
	
	//lemari bawah
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-33.0, -12.9, -23.0);
	glVertex3f(-25.0, -12.9, -23.0);
	glVertex3f(-25.0, -12.9, -39.9);
	glVertex3f(-33.0, -12.9, -39.9);
	glEnd();

	//lemari belakang
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-32.9, -4.0, -23.0);
	glVertex3f(-32.9, -12.9, -23.0);
	glVertex3f(-32.9, -12.9, -39.9);
	glVertex3f(-32.9, -4.0, -39.9);
	glEnd();
	
	//lemari kiri
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(-25, -4.0, -23.0);
	glVertex3f(-25, -12.9, -23.0);
	glVertex3f(-25, -12.9, -29.0);
	glVertex3f(-25, -4.0, -29.0);
	glEnd();
	
	//pintu kiri lemari
	glBegin(GL_QUADS);
	glColor3f(0.52, 0.37, 0.26);
	glVertex3f(-25, -4.0, -29.0);
	glVertex3f(-25, -12.9, -29.0);
	glVertex3f(-23, -12.9, -34.45);
	glVertex3f(-23, -4.0, -34.45);
	glEnd();
	
	//pintu kanan lemari
	glBegin(GL_QUADS);
	glColor3f(0.52, 0.37, 0.26);
	glVertex3f(-20, -4.0, -34.45);
	glVertex3f(-20, -12.9, -34.45);
	glVertex3f(-25, -12.9, -39.9);
	glVertex3f(-25, -4.0, -39.9);
	glEnd();
	
	//pinggir kiri
	glBegin(GL_POLYGON);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(-32.9, -12.9, -23.0);
	glVertex3f(-25.0, -12.9, -23.0);
	glVertex3f(-25.0, -4.0, -23.0);
	glVertex3f(-32.9, -4.0, -23.0);
	glEnd();
	
	//pinggir kanan
	glBegin(GL_POLYGON);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(-32.9, -12.9, -39.9);
	glVertex3f(-25.0, -12.9, -39.9);
	glVertex3f(-25.0, -4.0, -39.9);
	glVertex3f(-32.9, -4.0, -39.9);
	glEnd();
	
	//rak sepatu
	int i;
	for(i = 0; i < 3; i++){
		glBegin(GL_QUADS);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(10.0, -5.0-(i*2.5), -20.0);
		glVertex3f(28.0, -5.0-(i*2.5), -20.0);
		glVertex3f(28.0, -7.0-(i*2.5), -18.0);
		glVertex3f(10.0, -7.0-(i*2.5), -18.0);
		glEnd();
	}
}

void tampil(void){
	//keyboard
	if(kbmouse){
		if(is_depth) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		else glClear(GL_COLOR_BUFFER_BIT);
	}
	//mouse
	else{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
		glRotatef(xrot, 1.0f, 0.0f, 0.0f);
		glRotatef(yrot, 0.0f, 1.0f, 0.0f);
		glPushMatrix();
	}

	//alas
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-50.0, -13.0, 30.0);
	glVertex3f(50.0, -13.0, 30.0);
	glVertex3f(50.0, -13.0, -70.0);
	glVertex3f(-50.0, -13.0, -70.0);
	glEnd();
	
	if(cekAsbes){
		asbes_pintu();
	}
	rumahdepan();
	halamantengah();
	rumahbelakang();
	objekdalam();
	
	glPushMatrix();
	glPopMatrix();
	
	glutSwapBuffers();
}

void idle(){
	if(!mouseDown){
		xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){
	switch(key){
		//zoom_in
		case 'w':
		case 'W':
			glTranslatef(0.0,0.0,3.0);
			break;
		
		//geser kiri
		case 'a':
		case 'A':
			glTranslatef(-3.0,0.0,0.0);
			break;
			
		//zoom_out
		case 's':
		case 'S':
			glTranslatef(0.0,0.0,-3.0);
			break;
			
		//geser kanan
		case 'd':
		case 'D':
			glTranslatef(3.0,0.0,0.0);
			break;
		
		//naik
		case'7':
			glTranslatef(0.0,3.0,0.0);
			break;
		
		//turun
		case'9':
			glTranslatef(0.0,-3.0,0.0);
			break;
		
		//miring depan
		case'2':
			glRotatef(2.0, 1.0, 0.0, 0.0);
			break;
		
		//miring belakang
		case'8':
			glRotatef(-2.0, 1.0, 0.0, 0.0);
			break;
		
		//miring depan kanan
		case'6':
			glRotatef(2.0, 0.0, 1.0, 0.0);
			break;
		
		//miring depan kiri
		case'4':
			glRotatef(-2.0, 0.0, 1.0, 0.0);
			break;
			
		//miring kiri
		case'1':
			glRotatef(2.0, 0.0, 0.0, 1.0);
			break;
			
		//miring kanan
		case'3':
			glRotatef(-2.0, 0.0, 0.0, 1.0);
			break;
			
		//on off gl depth
		case'5':
			if(is_depth){
				is_depth = 0;
				glDisable(GL_DEPTH_TEST);
			}else{
				is_depth = 1;
				glEnable(GL_DEPTH_TEST);
			}
			break;
		
		//on off pintu sama asbes
		case'0':
			if(cekAsbes){
				cekAsbes = 0;
			}else{
				cekAsbes = 1;
			}
			break;
		
		//switch keyboard - mouse
		case'-':
			if(kbmouse){
				kbmouse = 0;
			}else{
				kbmouse = 1;
			}
			break;
	}
	tampil();
}

void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}else{
		mouseDown = false;
	}
}

void mouseMotion(int x, int y){
	if(!mouseDown){
		xrot = y + ydiff;
		yrot = x - xdiff;
		glutPostRedisplay();
	}	
}

void ukuran(int lebar, int tinggi){
	if(tinggi == 0) tinggi = 1;
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, lebar/tinggi, 5.0, 500.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(250,80);
	glutCreateWindow("CARENS KURNIAWAN WIJAYA - 672019084");
	myInit();
	glutDisplayFunc(tampil);
	glutReshapeFunc(ukuran);
	
	glutKeyboardFunc(keyboard);
	
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	
	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}*/

#include <iostream>
#include <GL/glut.h>
#include <windows.h>

//SOAL BONUS
//Asal Kak Devy = Toraja, Kak Fanny = Pemalang, Kak Benedict = Tangerang

int is_depth;
int cekAsbes = 1;
int kbmouse = 0;

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

void myInit(void){
	glClearColor(0.74902, 0.847059, 0.847059, 0.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	is_depth=1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);
}

void asbes_pintu(){
	//pintu depan
	glColor3f(0.29, 0.46, 0.43);
	glBegin(GL_POLYGON);
	glVertex3f(-25.0, -13.0, 10.0);
	glVertex3f(-25.0, 7.0, 10.0);
	glVertex3f(25.0, 7.0, 10.0);
	glVertex3f(25.0, -13.0, 10.0);
	glEnd();
	
	//asbes
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-33.0, 7.0, -20.0);
	glVertex3f(33.0, 7.0, -20.0);
	glVertex3f(33.0, 13.0, -40.0);
	glVertex3f(-33.0, 13.0, -40.0);
	glEnd();
}

void rumahdepan(){
	//depan kiri
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-33.0, -13.0, 10.0);
	glVertex3f(-25.0, -13.0, 10.0);
	glVertex3f(-25.0, 13.0, 10.0);
	glVertex3f(-33.0, 13.0, 10.0);
	glEnd();
	
	//depan tengah
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-25.0, 7.0, 10.0);
	glVertex3f(25.0, 7.0, 10.0);
	glVertex3f(25.0, 13.0, 10.0);
	glVertex3f(-25.0, 13.0, 10.0);
	glEnd();
	
	//depan kanan
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(25.0, -13.0, 10.0);
	glVertex3f(33.0, -13.0, 10.0);
	glVertex3f(33.0, 13.0, 10.0);
	glVertex3f(25.0, 13.0, 10.0);
	glEnd();
	
	//sekat tengah kiri
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-33.0, -13.0, -20.0);
	glVertex3f(-25.0, -13.0, -20.0);
	glVertex3f(-25.0, 13.0, -20.0);
	glVertex3f(-33.0, 13.0, -20.0);
	glEnd();
	
	//sekat tengah tengah
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-25.0, 7.0, -20.0);
	glVertex3f(3.0, 7.0, -20.0);
	glVertex3f(3.0, 13.0, -20.0);
	glVertex3f(-25.0, 13.0, -20.0);
	glEnd();
	
	//sekat tengah kanan
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(3.0, -13.0, -20.0);
	glVertex3f(33.0, -13.0, -20.0);
	glVertex3f(33.0, 13.0, -20.0);
	glVertex3f(3.0, 13.0, -20.0);
	glEnd();
	
	//kanan
	glBegin(GL_QUADS);
	glColor3f(0.65, 0.50, 0.39);
	glVertex3f(33.0, 13.0, 10.0);
	glVertex3f(33.0, -13.0, 10.0);
	glVertex3f(33.0, -13.0, -20.0);
	glVertex3f(33.0, 13.0, -20.0);
	glEnd();
	
	//kiri
	glBegin(GL_QUADS);
	glColor3f(0.65, 0.50, 0.39);
	glVertex3f(-33.0, 13.0, 10.0);
	glVertex3f(-33.0, -13.0, 10.0);
	glVertex3f(-33.0, -13.0, -20.0);
	glVertex3f(-33.0, 13.0, -20.0);
	glEnd();
	
	//atas
	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-33.0, 13.0, 10.0);
	glVertex3f(33.0, 13.0, 10.0);
	glVertex3f(33.0, 13.0, -20.0);
	glVertex3f(-33.0, 13.0, -20.0);
	glEnd();
}

void halamantengah(){
	//tembok kanan
	glBegin(GL_QUADS);
	glColor3f(0.65, 0.50, 0.39);
	glVertex3f(33.0, 7.0, -20.0);
	glVertex3f(33.0, -13.0, -20.0);
	glVertex3f(33.0, -13.0, -40.0);
	glVertex3f(33.0, 7.0, -40.0);
	glEnd();
	
	//tembok kiri
	glBegin(GL_QUADS);
	glColor3f(0.65, 0.50, 0.39);
	glVertex3f(-33.0, 7.0, -20.0);
	glVertex3f(-33.0, -13.0, -20.0);
	glVertex3f(-33.0, -13.0, -40.0);
	glVertex3f(-33.0, 7.0, -40.0);
	glEnd();
}

void rumahbelakang(){
	//depan kiri
	glBegin(GL_POLYGON);
	glColor3f(0.91, 0.76, 0.65);
	glVertex3f(-33.0, -13.0, -40.0);
	glVertex3f(-18.0, -13.0, -40.0);
	glVertex3f(-18.0, 20.0, -40.0);
	glVertex3f(-33.0, 20.0, -40.0);
	glEnd();
	
	//depan tengah
	glBegin(GL_POLYGON);
	glColor3f(0.91, 0.76, 0.65);
	glVertex3f(-18.0, 5.0, -40.0);
	glVertex3f(18.0, 5.0, -40.0);
	glVertex3f(18.0, 20.0, -40.0);
	glVertex3f(-18.0, 20.0, -40.0);
	glEnd();
	
	//depan kanan
	glBegin(GL_POLYGON);
	glColor3f(0.91, 0.76, 0.65);
	glVertex3f(18.0, -13.0, -40.0);
	glVertex3f(33.0, -13.0, -40.0);
	glVertex3f(33.0, 20.0, -40.0);
	glVertex3f(18.0, 20.0, -40.0);
	glEnd();
	
	//belakang-1.1
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(-33.0, -13.0, -50.0);
	glVertex3f(-33.0, 40.0, -50.0);
	glVertex3f(-28.0, 40.0, -50.0);
	glVertex3f(-28.0, -13.0, -50.0);
	glEnd();
	
	//belakang-1.2
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(-20.0, -13.0, -50.0);
	glVertex3f(-20.0, 40.0, -50.0);
	glVertex3f(-18.0, 40.0, -50.0);
	glVertex3f(-18.0, -13.0, -50.0);
	glEnd();
	
	//belakang-1.3
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(-13.0, -13.0, -50.0);
	glVertex3f(-13.0, 40.0, -50.0);
	glVertex3f(-10.0, 40.0, -50.0);
	glVertex3f(-10.0, -13.0, -50.0);
	glEnd();
	
	//belakang-1.4
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(-2.0, -13.0, -50.0);
	glVertex3f(-2.0, 40.0, -50.0);
	glVertex3f(0.0, 40.0, -50.0);
	glVertex3f(0.0, -13.0, -50.0);
	glEnd();
	
	//belakang-1.5
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(5.0, -13.0, -50.0);
	glVertex3f(5.0, 40.0, -50.0);
	glVertex3f(8.0, 40.0, -50.0);
	glVertex3f(8.0, -13.0, -50.0);
	glEnd();
	
	//belakang-1.6
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(13.0, -13.0, -50.0);
	glVertex3f(13.0, 40.0, -50.0);
	glVertex3f(15.0, 40.0, -50.0);
	glVertex3f(15.0, -13.0, -50.0);
	glEnd();
	
	//belakang-1.7
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(23.0, -13.0, -50.0);
	glVertex3f(23.0, 40.0, -50.0);
	glVertex3f(33.0, 40.0, -50.0);
	glVertex3f(33.0, -13.0, -50.0);
	glEnd();
	
	//belakang-1.Atas
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(-33.0, 30.0, -50.0);
	glVertex3f(-33.0, 40.0, -50.0);
	glVertex3f(33.0, 40.0, -50.0);
	glVertex3f(33.0, 30.0, -50.0);
	glEnd();
	
	//Tengah.Atas
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(-33.0, 3.0, -50.0);
	glVertex3f(-33.0, 15.0, -50.0);
	glVertex3f(33.0, 15.0, -50.0);
	glVertex3f(33.0, 3.0, -50.0);
	glEnd();
	
	//belakang-1.Bawah.1
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(-28.0, -13.0, -50.0);
	glVertex3f(-28.0, 20.0, -50.0);
	glVertex3f(-20.0, 20.0, -50.0);
	glVertex3f(-20.0, -13.0, -50.0);
	glEnd();
	
	//belakang-1.Bawah.2
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(-10.0, -13.0, -50.0);
	glVertex3f(-10.0, 20.0, -50.0);
	glVertex3f(-2.0, 20.0, -50.0);
	glVertex3f(-2.0, -13.0, -50.0);
	glEnd();
	
	//belakang-1.Bawah.3
	glBegin(GL_QUADS);
	glColor3f(0.91, 0.86, 0.75);
	glVertex3f(15.0, -13.0, -50.0);
	glVertex3f(15.0, 20.0, -50.0);
	glVertex3f(23.0, 20.0, -50.0);
	glVertex3f(23.0, -13.0, -50.0);
	glEnd();
	
	//tembok kanan
	glBegin(GL_POLYGON);
	glColor3f(0.65, 0.50, 0.39);
	glVertex3f(33.0, 40.0, -50.0);
	glVertex3f(33.0, 35.0, -40.0);
	glVertex3f(33.0, -13.0, -40.0);
	glVertex3f(33.0, -13.0, -60.0);
	glVertex3f(33.0, 35.0, -60.0);
	glEnd();
	
	//tembok kiri
	glBegin(GL_POLYGON);
	glColor3f(0.65, 0.50, 0.39);
	glVertex3f(-33.0, 40.0, -50.0);
	glVertex3f(-33.0, 35.0, -40.0);
	glVertex3f(-33.0, -13.0, -40.0);
	glVertex3f(-33.0, -13.0, -60.0);
	glVertex3f(-33.0, 35.0, -60.0);
	glEnd();
	
	//belakang-2
	glBegin(GL_QUADS);
	glColor3f(0.65, 0.50, 0.39);
	glVertex3f(-33.0, -13.0, -60.0);
	glVertex3f(-33.0, 35.0, -60.0);
	glVertex3f(33.0, 35.0, -60.0);
	glVertex3f(33.0, -13.0, -60.0);
	glEnd();
	
	//belakang-2.1
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-33.0, -13.0, -59.9);
	glVertex3f(-33.0, 35.0, -59.9);
	glVertex3f(33.0, 35.0, -59.9);
	glVertex3f(33.0, -13.0, -59.9);
	glEnd();
	
	//lantai 2
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-33.0, 15.0, -40.0);
	glVertex3f(33.0, 15.0, -40.0);
	glVertex3f(33.0, 15.0, -60.0);
	glVertex3f(-33.0, 15.0, -60.0);
	glEnd();
	
	//atap depan
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(-35.0, 34.0, -38.0);
	glVertex3f(35.0, 34.0, -38.0);
	glVertex3f(35.0, 40.0, -50.0);
	glVertex3f(-35.0, 40.0, -50.0);
	glEnd();
	
	//atap belakang
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(-35.0, 34.0, -62.0);
	glVertex3f(35.0, 34.0, -62.0);
	glVertex3f(35.0, 40.0, -50.0);
	glVertex3f(-35.0, 40.0, -50.0);
	glEnd();
	
	//pintu
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(-18.0, 15.0, -55);
	glVertex3f(-13.0, 15.0, -50);
	glVertex3f(-13.0, 30.0, -50);
	glVertex3f(-18.0, 30.0, -55);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(0.0, 15.0, -55);
	glVertex3f(5.0, 15.0, -50);
	glVertex3f(5.0, 30.0, -50);
	glVertex3f(0.0, 30.0, -55);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(8.0, 15.0, -50);
	glVertex3f(13.0, 15.0, -55);
	glVertex3f(13.0, 30.0, -55);
	glVertex3f(8.0, 30.0, -50);
	glEnd();
	
	//jendela
	glBegin(GL_LINE_LOOP);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(-28.0, 20.0, -48.0);
	glVertex3f(-28.0, 30.0, -50.0);
	glVertex3f(-20.0, 30.0, -50.0);
	glVertex3f(-20.0, 20.0, -48.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(-10.0, 20.0, -48.0);
	glVertex3f(-10.0, 30.0, -50.0);
	glVertex3f(-2.0, 30.0, -50.0);
	glVertex3f(-2.0, 20.0, -48.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(15.0, 20.0, -48.0);
	glVertex3f(15.0, 30.0, -50.0);
	glVertex3f(23.0, 30.0, -50.0);
	glVertex3f(23.0, 20.0, -48.0);
	glEnd();
	
	//kaca
	glBegin(GL_POLYGON);
	glColor4f(0.0, 0.0, 0.0, 0.7);
	glVertex3f(-28.0, 20.0, -48.0);
	glVertex3f(-28.0, 30.0, -50.0);
	glVertex3f(-20.0, 30.0, -50.0);
	glVertex3f(-20.0, 20.0, -48.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor4f(0.0, 0.0, 0.0, 0.7);
	glVertex3f(-10.0, 20.0, -48.0);
	glVertex3f(-10.0, 30.0, -50.0);
	glVertex3f(-2.0, 30.0, -50.0);
	glVertex3f(-2.0, 20.0, -48.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor4f(0.0, 0.0, 0.0, 0.7);
	glVertex3f(15.0, 20.0, -48.0);
	glVertex3f(15.0, 30.0, -50.0);
	glVertex3f(23.0, 30.0, -50.0);
	glVertex3f(23.0, 20.0, -48.0);
	glEnd();
}

void objekdalam(){
	//meja
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(15.0, -7.0, -23.0);
	glVertex3f(28.0, -7.0, -23.0);
	glVertex3f(28.0, -7.0, -36.0);
	glVertex3f(15.0, -7.0, -36.0);
	glEnd();
	
	//tiang meja
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(21.5, -7.0, -29.5);
	glVertex3f(21.5, -12.9, -29.5);
	glEnd();
	
	//kaki meja
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(18.0, -12.9, -26.0);
	glVertex3f(25.0, -12.9, -26.0);
	glVertex3f(25.0, -12.9, -33.0);
	glVertex3f(18.0, -12.9, -33.0);
	glEnd();
	
	//lemari atas
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(-33.0, -4.0, -23.0);
	glVertex3f(-25.0, -4.0, -23.0);
	glVertex3f(-25.0, -4.0, -39.9);
	glVertex3f(-33.0, -4.0, -39.9);
	glEnd();
	
	//lemari bawah
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-33.0, -12.9, -23.0);
	glVertex3f(-25.0, -12.9, -23.0);
	glVertex3f(-25.0, -12.9, -39.9);
	glVertex3f(-33.0, -12.9, -39.9);
	glEnd();

	//lemari belakang
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-32.9, -4.0, -23.0);
	glVertex3f(-32.9, -12.9, -23.0);
	glVertex3f(-32.9, -12.9, -39.9);
	glVertex3f(-32.9, -4.0, -39.9);
	glEnd();
	
	//lemari kiri
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(-25, -4.0, -23.0);
	glVertex3f(-25, -12.9, -23.0);
	glVertex3f(-25, -12.9, -29.0);
	glVertex3f(-25, -4.0, -29.0);
	glEnd();
	
	//pintu kiri lemari
	glBegin(GL_QUADS);
	glColor3f(0.52, 0.37, 0.26);
	glVertex3f(-25, -4.0, -29.0);
	glVertex3f(-25, -12.9, -29.0);
	glVertex3f(-23, -12.9, -34.45);
	glVertex3f(-23, -4.0, -34.45);
	glEnd();
	
	//pintu kanan lemari
	glBegin(GL_QUADS);
	glColor3f(0.52, 0.37, 0.26);
	glVertex3f(-20, -4.0, -34.45);
	glVertex3f(-20, -12.9, -34.45);
	glVertex3f(-25, -12.9, -39.9);
	glVertex3f(-25, -4.0, -39.9);
	glEnd();
	
	//pinggir kiri
	glBegin(GL_POLYGON);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(-32.9, -12.9, -23.0);
	glVertex3f(-25.0, -12.9, -23.0);
	glVertex3f(-25.0, -4.0, -23.0);
	glVertex3f(-32.9, -4.0, -23.0);
	glEnd();
	
	//pinggir kanan
	glBegin(GL_POLYGON);
	glColor3f(0.35, 0.16, 0.14);
	glVertex3f(-32.9, -12.9, -39.9);
	glVertex3f(-25.0, -12.9, -39.9);
	glVertex3f(-25.0, -4.0, -39.9);
	glVertex3f(-32.9, -4.0, -39.9);
	glEnd();
	
	//rak sepatu
	int i;
	for(i = 0; i < 3; i++){
		glBegin(GL_QUADS);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(10.0, -5.0-(i*2.5), -20.0);
		glVertex3f(28.0, -5.0-(i*2.5), -20.0);
		glVertex3f(28.0, -7.0-(i*2.5), -18.0);
		glVertex3f(10.0, -7.0-(i*2.5), -18.0);
		glEnd();
	}
}

void tampil(void){
	//keyboard
	if(kbmouse){
		if(is_depth) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		else glClear(GL_COLOR_BUFFER_BIT);
	}
	//mouse
	else{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
		glRotatef(xrot, 1.0f, 0.0f, 0.0f);
		glRotatef(yrot, 0.0f, 1.0f, 0.0f);
		glPushMatrix();
	}

	//alas
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-50.0, -13.0, 30.0);
	glVertex3f(50.0, -13.0, 30.0);
	glVertex3f(50.0, -13.0, -70.0);
	glVertex3f(-50.0, -13.0, -70.0);
	glEnd();
	
	if(cekAsbes){
		asbes_pintu();
	}
	rumahdepan();
	halamantengah();
	rumahbelakang();
	objekdalam();
	
	glPushMatrix();
	glPopMatrix();
	
	glutSwapBuffers();
}

void idle(){
	if(!mouseDown){
		xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){
	switch(key){
		//zoom_in
		case 'w':
		case 'W':
			glTranslatef(0.0,0.0,3.0);
			break;
		
		//geser kiri
		case 'a':
		case 'A':
			glTranslatef(-3.0,0.0,0.0);
			break;
			
		//zoom_out
		case 's':
		case 'S':
			glTranslatef(0.0,0.0,-3.0);
			break;
			
		//geser kanan
		case 'd':
		case 'D':
			glTranslatef(3.0,0.0,0.0);
			break;
		
		//naik
		case'7':
			glTranslatef(0.0,3.0,0.0);
			break;
		
		//turun
		case'9':
			glTranslatef(0.0,-3.0,0.0);
			break;
		
		//miring depan
		case'2':
			glRotatef(2.0, 1.0, 0.0, 0.0);
			break;
		
		//miring belakang
		case'8':
			glRotatef(-2.0, 1.0, 0.0, 0.0);
			break;
		
		//miring depan kanan
		case'6':
			glRotatef(2.0, 0.0, 1.0, 0.0);
			break;
		
		//miring depan kiri
		case'4':
			glRotatef(-2.0, 0.0, 1.0, 0.0);
			break;
			
		//miring kiri
		case'1':
			glRotatef(2.0, 0.0, 0.0, 1.0);
			break;
			
		//miring kanan
		case'3':
			glRotatef(-2.0, 0.0, 0.0, 1.0);
			break;
			
		//on off gl depth
		case'5':
			if(is_depth){
				is_depth = 0;
				glDisable(GL_DEPTH_TEST);
			}else{
				is_depth = 1;
				glEnable(GL_DEPTH_TEST);
			}
			break;
		
		//on off pintu sama asbes
		case'0':
			if(cekAsbes){
				cekAsbes = 0;
			}else{
				cekAsbes = 1;
			}
			break;
		
		//switch keyboard - mouse
		case'-':
			if(kbmouse){
				kbmouse = 0;
			}else{
				kbmouse = 1;
			}
			break;
	}
	tampil();
}

void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}else{
		mouseDown = false;
	}
}

void mouseMotion(int x, int y){
	if(!mouseDown){
		xrot = y + ydiff;
		yrot = x - xdiff;
		glutPostRedisplay();
	}	
}

void ukuran(int lebar, int tinggi){
	if(tinggi == 0) tinggi = 1;
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, lebar/tinggi, 5.0, 500.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(250,80);
	glutCreateWindow("CARENS KURNIAWAN WIJAYA - 672019084");
	myInit();
	glutDisplayFunc(tampil);
	glutReshapeFunc(ukuran);
	
	glutKeyboardFunc(keyboard);
	
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	
	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}

