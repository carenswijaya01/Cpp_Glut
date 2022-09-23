/*#include <windows.h>
#include <GL\glut.h>

void myInit(void){
	glClearColor(0.1, 0.1, 0.1, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,450,0.0,450);
}

void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);
    
    //halaman
    glColor3f(0.1, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);//kiri bawah
    glVertex2i(450, 0);//kanan bawah
    glVertex2i(450, 175);//kanan atas
    glVertex2i(0, 175);//kiri atas
    glEnd();
    
    //jalan
	glColor3f(0.658824, 0.658824, 0.658824);
    glBegin(GL_POLYGON);
    glVertex2i(195, 130);
    glVertex2i(255, 130);
    glVertex2i(280, 0);
    glVertex2i(170, 0);
    glEnd();
    
    //===============================RUMAH===============================
    
    //tembok depan
    glColor3f(0.847059, 0.847059, 0.74902);
    glBegin(GL_POLYGON);
    glVertex2i(125, 130);//kiri bawah
    glVertex2i(325, 130);//kanan bawah
    glVertex2i(325, 275);//kanan atas
    glVertex2i(125, 275);//kiri atas
    glEnd();
    
    //pintu depan
	glColor3f(0.36, 0.25, 0.20);
    glBegin(GL_POLYGON);
    glVertex2i(195, 130);
    glVertex2i(255, 130);
    glVertex2i(255, 210);
    glVertex2i(195, 210);
    glEnd();
    
    //gagang pintu
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(200, 170);
    glVertex2i(205, 170);
    glVertex2i(205, 175);
    glVertex2i(200, 175);
    glEnd();
    
    //cerobong asap
    glColor3f(0.65, 0.50, 0.39);
    glBegin(GL_POLYGON);
    glVertex2i(140, 320);
    glVertex2i(165, 320);
    glVertex2i(165, 370);
    glVertex2i(140, 370);
    glEnd();
    
    //pinggiran cerobong asap
    glColor3f(0.35, 0.16, 0.14);
    glBegin(GL_POLYGON);
    glVertex2i(135, 360);
    glVertex2i(170, 360);
    glVertex2i(170, 370);
    glVertex2i(135, 370);
    glEnd();
    
    //atap
    glColor3f(0.35, 0.16, 0.14);
    glBegin(GL_TRIANGLES);
    glVertex2i(225, 400);//puncak
    glVertex2i(90, 275);//kiri bawah
    glVertex2i(360, 275);//kanan bawah
    glEnd();
    
    //jendela kiri
    glColor3f(0.560784, 0.560784, 0.737255);
    glBegin(GL_POLYGON);
    glVertex2i(140, 165);
    glVertex2i(180, 165);
    glVertex2i(180, 210);
    glVertex2i(140, 210);
    glEnd();
    
    //garis jendela kiri
    glColor3f(0.35, 0.16, 0.14);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(160, 210);
    glVertex2i(160, 165);
    glVertex2i(140, 187);
    glVertex2i(180, 187);
    glEnd();
    
    //jendela kanan
    glColor3f(0.560784, 0.560784, 0.737255);
    glBegin(GL_POLYGON);
    glVertex2i(270, 165);
    glVertex2i(310, 165);
    glVertex2i(310, 210);
    glVertex2i(270, 210);
    glEnd();
    
    //garis jendela kiri
    glColor3f(0.35, 0.16, 0.14);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(290, 210);
    glVertex2i(290, 165);
    glVertex2i(270, 187);
    glVertex2i(310, 187);
    glEnd();
    
    //===============================BENDERA===============================
    
    //tiang bendera
    glColor3f(0.35, 0.16, 0.14);
    glBegin(GL_POLYGON);
    glVertex2i(30, 20);
    glVertex2i(38, 20);
    glVertex2i(38, 200);
    glVertex2i(30, 200);
    glEnd();
    
    //bendera merah
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(38, 170);
    glVertex2i(75, 170);
    glVertex2i(75, 190);
    glVertex2i(38, 190);
    glEnd();
    
    //bendera putih
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(38, 150);
    glVertex2i(75, 150);
    glVertex2i(75, 170);
    glVertex2i(38, 170);
    glEnd();
    
    //bendera merah (lekukan)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(75, 170);
    glVertex2i(83, 160);
    glVertex2i(83, 180);
    glVertex2i(75, 190);
    glEnd();
    
    //bendera putih (lekukan)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(75, 150);
    glVertex2i(83, 140);
    glVertex2i(83, 160);
    glVertex2i(75, 170);
    glEnd();
    
    //bendera merah (setelah lekukan)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(83, 160);
    glVertex2i(110, 160);
    glVertex2i(110, 180);
    glVertex2i(83, 180);
    glEnd();
    
    //bendera putih (setelah lekukan)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(83, 140);
    glVertex2i(110, 140);
    glVertex2i(110, 160);
    glVertex2i(83, 160);
    glEnd();
    
    //===============================LAMPU TAMAN===============================
    
    //tiang lampu taman kanan
    glColor3f(0.184314, 0.184314, 0.309804);
    glBegin(GL_POLYGON);
    glVertex2i(285, 5);
    glVertex2i(295, 5);
    glVertex2i(295, 50);
    glVertex2i(285, 50);
    glEnd();
    
    //lampu taman kanan
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(280, 66);
    glVertex2i(280, 58);
    glVertex2i(285, 50);
    glVertex2i(295, 50);
    glVertex2i(300, 58);
    glVertex2i(300, 66);
    glVertex2i(295, 74);
    glVertex2i(285, 74);
    glEnd();
    
    //tiang lampu taman kiri
    glColor3f(0.184314, 0.184314, 0.309804);
    glBegin(GL_POLYGON);
    glVertex2i(155, 5);
    glVertex2i(165, 5);
    glVertex2i(165, 50);
    glVertex2i(155, 50);
    glEnd();
    
    //lampu taman kiri
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(150, 66);
    glVertex2i(150, 58);
    glVertex2i(155, 50);
    glVertex2i(165, 50);
    glVertex2i(170, 58);
    glVertex2i(170, 66);
    glVertex2i(165, 74);
    glVertex2i(155, 74);
    glEnd();
    
	//===============================BULAN===============================
    
    //bulan luar
    glColor3f(1.0, 1.0, 0.0);
    //glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2i(350, 425);
    glVertex2i(350, 405);
    glVertex2i(358, 390);
    glVertex2i(370, 385);
    glVertex2i(390, 385);
    glVertex2i(402, 390);
    glVertex2i(410, 405);
    glVertex2i(410, 425);
    glVertex2i(402, 438);
    glVertex2i(390, 445);
    glVertex2i(370, 445);
    glVertex2i(358, 438);
    glEnd();
    
    //bulan dalam
    glColor3f(1.0, 1.0, 0.6682);
    //glColor3f(0.98, 0.98, 0.98);
    glBegin(GL_POLYGON);
    glVertex2i(355, 425);
    glVertex2i(355, 405);
    glVertex2i(363, 390);
    glVertex2i(375, 385);
    glVertex2i(395, 385);
    glVertex2i(407, 390);
    glVertex2i(415, 405);
    glVertex2i(415, 425);
    glVertex2i(407, 438);
    glVertex2i(395, 445);
    glVertex2i(375, 445);
    glVertex2i(363, 438);
    glEnd();
    
    //===============================KOTAK POS===============================
    
    //tiang kotak pos 1
    glColor3f(0.65, 0.50, 0.39);
    glBegin(GL_POLYGON);
    glVertex2i(377, 50);
    glVertex2i(382, 50);
    glVertex2i(382, 110);
    glVertex2i(377, 110);
    glEnd();
    
    //kotak pos
    glColor3f(0.35, 0.16, 0.14);
    glBegin(GL_POLYGON);
    glVertex2i(365, 110);
    glVertex2i(393, 110);
    glVertex2i(393, 125);
    glVertex2i(385, 140);
    glVertex2i(373, 140);
    glVertex2i(365, 125);
    glEnd();
    
    //tarikan
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(393, 120);
    glVertex2i(395, 120);
    glVertex2i(395, 145);
    glVertex2i(393, 145);
    glEnd();
    
    //lobang kotak pos
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(368, 115);
    glVertex2i(390, 115);
    glVertex2i(390, 120);
    glVertex2i(368, 120);
    glEnd();
    
    //===============================BINTANG===============================
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(20, 315);//kiri bawah
    glVertex2i(22, 315);//kanan bawah
    glVertex2i(22, 317);//kanan atas
    glVertex2i(20, 317);//
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(127, 375);
    glVertex2i(129, 375);
    glVertex2i(129, 377);
    glVertex2i(127, 377);
    glEnd();
    
    //bintang gede
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(37, 355);
    glVertex2i(41, 355);
    glVertex2i(41, 359);
    glVertex2i(37, 359);
    glEnd();
    
    //bintang gede
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(337, 255);
    glVertex2i(341, 255);
    glVertex2i(341, 259);
    glVertex2i(337, 259);
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(227, 405);
    glVertex2i(229, 405);
    glVertex2i(229, 407);
    glVertex2i(227, 407);
    glEnd();
    
    //bintang gede
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(37, 255);
    glVertex2i(41, 255);
    glVertex2i(41, 259);
    glVertex2i(37, 259);
    glEnd();
    
    glFlush();
}

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("RUMAH SEDERHANA");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
    return 0;
}*/

//============================================================ S I A N G =============================================================================

#include <windows.h>
#include <GL\glut.h>

void myInit(void){
	glClearColor(0.196078, 0.6, 0.8, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,450,0.0,450);
}

void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);
    
    //halaman
    glColor3f(0.1, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);//kiri bawah
    glVertex2i(450, 0);//kanan bawah
    glVertex2i(450, 175);//kanan atas
    glVertex2i(0, 175);//kiri atas
    glEnd();
    
    //jalan
	glColor3f(0.658824, 0.658824, 0.658824);
    glBegin(GL_POLYGON);
    glVertex2i(195, 130);
    glVertex2i(255, 130);
    glVertex2i(280, 0);
    glVertex2i(170, 0);
    glEnd();
    
    //===============================RUMAH===============================
    
    //tembok depan
    glColor3f(0.184314, 0.309804, 0.309804);
    glBegin(GL_POLYGON);
    glVertex2i(125, 130);//kiri bawah
    glVertex2i(325, 130);//kanan bawah
    glVertex2i(325, 275);//kanan atas
    glVertex2i(125, 275);//kiri atas
    glEnd();
    
    //pintu depan
	glColor3f(0.74902, 0.847059, 0.847059);
    glBegin(GL_POLYGON);
    glVertex2i(195, 130);
    glVertex2i(255, 130);
    glVertex2i(255, 210);
    glVertex2i(195, 210);
    glEnd();
    
    //gagang pintu
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(200, 170);
    glVertex2i(205, 170);
    glVertex2i(205, 175);
    glVertex2i(200, 175);
    glEnd();
    
    //cerobong asap
    glColor3f(0.65, 0.50, 0.39);
    glBegin(GL_POLYGON);
    glVertex2i(140, 320);
    glVertex2i(165, 320);
    glVertex2i(165, 370);
    glVertex2i(140, 370);
    glEnd();
    
    //pinggiran cerobong asap
    glColor3f(0.35, 0.16, 0.14);
    glBegin(GL_POLYGON);
    glVertex2i(135, 360);
    glVertex2i(170, 360);
    glVertex2i(170, 370);
    glVertex2i(135, 370);
    glEnd();
    
    //atap
    glColor3f(0.35, 0.16, 0.14);
    glBegin(GL_TRIANGLES);
    glVertex2i(225, 400);//puncak
    glVertex2i(90, 275);//kiri bawah
    glVertex2i(360, 275);//kanan bawah
    glEnd();
    
    //jendela kiri
    glColor3f(0.560784, 0.560784, 0.737255);
    glBegin(GL_POLYGON);
    glVertex2i(140, 165);
    glVertex2i(180, 165);
    glVertex2i(180, 210);
    glVertex2i(140, 210);
    glEnd();
    
    //garis jendela kiri
    glColor3f(0.35, 0.16, 0.14);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(160, 210);
    glVertex2i(160, 165);
    glVertex2i(140, 187);
    glVertex2i(180, 187);
    glEnd();
    
    //jendela kanan
    glColor3f(0.560784, 0.560784, 0.737255);
    glBegin(GL_POLYGON);
    glVertex2i(270, 165);
    glVertex2i(310, 165);
    glVertex2i(310, 210);
    glVertex2i(270, 210);
    glEnd();
    
    //garis jendela kiri
    glColor3f(0.35, 0.16, 0.14);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(290, 210);
    glVertex2i(290, 165);
    glVertex2i(270, 187);
    glVertex2i(310, 187);
    glEnd();
    
    //===============================BENDERA===============================
    
    //tiang bendera
    glColor3f(0.35, 0.16, 0.14);
    glBegin(GL_POLYGON);
    glVertex2i(30, 20);
    glVertex2i(38, 20);
    glVertex2i(38, 200);
    glVertex2i(30, 200);
    glEnd();
    
    //bendera merah
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(38, 170);
    glVertex2i(75, 170);
    glVertex2i(75, 190);
    glVertex2i(38, 190);
    glEnd();
    
    //bendera putih
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(38, 150);
    glVertex2i(75, 150);
    glVertex2i(75, 170);
    glVertex2i(38, 170);
    glEnd();
    
    //bendera merah (lekukan)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(75, 170);
    glVertex2i(83, 160);
    glVertex2i(83, 180);
    glVertex2i(75, 190);
    glEnd();
    
    //bendera putih (lekukan)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(75, 150);
    glVertex2i(83, 140);
    glVertex2i(83, 160);
    glVertex2i(75, 170);
    glEnd();
    
    //bendera merah (setelah lekukan)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(83, 160);
    glVertex2i(110, 160);
    glVertex2i(110, 180);
    glVertex2i(83, 180);
    glEnd();
    
    //bendera putih (setelah lekukan)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(83, 140);
    glVertex2i(110, 140);
    glVertex2i(110, 160);
    glVertex2i(83, 160);
    glEnd();
    
    //===============================LAMPU TAMAN===============================
    
    //tiang lampu taman kanan
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2i(285, 5);
    glVertex2i(295, 5);
    glVertex2i(295, 50);
    glVertex2i(285, 50);
    glEnd();
    
    //lampu taman kanan
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(280, 66);
    glVertex2i(280, 58);
    glVertex2i(285, 50);
    glVertex2i(295, 50);
    glVertex2i(300, 58);
    glVertex2i(300, 66);
    glVertex2i(295, 74);
    glVertex2i(285, 74);
    glEnd();
    
    //tiang lampu taman kiri
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2i(155, 5);
    glVertex2i(165, 5);
    glVertex2i(165, 50);
    glVertex2i(155, 50);
    glEnd();
    
    //lampu taman kiri
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(150, 66);
    glVertex2i(150, 58);
    glVertex2i(155, 50);
    glVertex2i(165, 50);
    glVertex2i(170, 58);
    glVertex2i(170, 66);
    glVertex2i(165, 74);
    glVertex2i(155, 74);
    glEnd();
    
	//===============================BULAN===============================
    
    //bulan luar
    glColor3f(1.0, 1.0, 0.0);
    //glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2i(350, 425);
    glVertex2i(350, 405);
    glVertex2i(358, 390);
    glVertex2i(370, 385);
    glVertex2i(390, 385);
    glVertex2i(402, 390);
    glVertex2i(410, 405);
    glVertex2i(410, 425);
    glVertex2i(402, 438);
    glVertex2i(390, 445);
    glVertex2i(370, 445);
    glVertex2i(358, 438);
    glEnd();
    
    //bulan dalam
    glColor3f(1.0, 1.0, 0.6682);
    //glColor3f(0.98, 0.98, 0.98);
    glBegin(GL_POLYGON);
    glVertex2i(355, 425);
    glVertex2i(355, 405);
    glVertex2i(363, 390);
    glVertex2i(375, 385);
    glVertex2i(395, 385);
    glVertex2i(407, 390);
    glVertex2i(415, 405);
    glVertex2i(415, 425);
    glVertex2i(407, 438);
    glVertex2i(395, 445);
    glVertex2i(375, 445);
    glVertex2i(363, 438);
    glEnd();
    
    //===============================KOTAK POS===============================
    
    //tiang kotak pos 1
    glColor3f(0.65, 0.50, 0.39);
    glBegin(GL_POLYGON);
    glVertex2i(377, 50);
    glVertex2i(382, 50);
    glVertex2i(382, 110);
    glVertex2i(377, 110);
    glEnd();
    
    //kotak pos
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(365, 110);
    glVertex2i(393, 110);
    glVertex2i(393, 125);
    glVertex2i(385, 140);
    glVertex2i(373, 140);
    glVertex2i(365, 125);
    glEnd();
    
    //tarikan
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(393, 120);
    glVertex2i(395, 120);
    glVertex2i(395, 145);
    glVertex2i(393, 145);
    glEnd();
    
    //lobang kotak pos
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(368, 115);
    glVertex2i(390, 115);
    glVertex2i(390, 120);
    glVertex2i(368, 120);
    glEnd();
    
    glFlush();
}

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("RUMAH SEDERHANA");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
    return 0;
}
