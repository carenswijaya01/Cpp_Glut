#include <iostream>
#include <gl/glut.h>

#define RATIO 1.200  //rasio perbandingan 1:1200
#define WW 100 //lebar viewport 100
#define WH (WW/RATIO) //tinggi viewport
#define HALFX ((int)WW/2) //koor X min / max
#define HALFY ((int)WH/2) //koor Y min / max
#define deltat .001 //menambahkan nilai t

int WindowWidth; //lebar window pixel
int WindowHeight; //tinggi window pixel

void Display(){
	glLineWidth(4.0); //lebar garis
	
	//dua belas titik awal untuk huruf W
	float StartShape[12][2] = {
		{-15,-15}, {-5,-15}, {0,-5}, {5,-15}, {15,-15}, {15,25}, 
		{5,25}, {5,-5}, {0,0}, {-5,-5}, {-5, 25}, {-15,25}
	};
	
	//dua belas titik akhir untuk huruf M
	float EndShape[12][2] = {
		{-15,-15}, {-5,-15}, {-5,10}, {0,0}, {5,10}, {5,-15},
		{15,-15}, {15,25}, {5,25}, {0,15}, {-5, 25}, {-15,25}
	};
	
	//untuk tampung titik proses dari W jadi M
	float IntermediateShape[12][2];
	
	//kasih warna tiap titik (efek gradasi)
	float VertexColors[12][3] = {
		{1,0,0}, {1,1,0}, {1,0,1}, {0,1,0}, {0,1,1}, {0,0,1},
		{1,0.5,0}, {1,0,0.5}, {0.5,1,0}, {0.5,0,1}, {1,0,0.5}, {0,1,0.5}
	};
	
	static float Tween = 0.0 - deltat; //inisialisasi nilai tween, supatya poin pertama tepat
	
	//looping nilai tween terbaru
	if(Tween < 1){
		Tween += deltat;
	}
	
	int Vtx;
	for(Vtx = 0; Vtx < 12; Vtx++){
		IntermediateShape[Vtx][0] = (1.0 - Tween) * StartShape[Vtx][0] + Tween*EndShape[Vtx][0];
		IntermediateShape[Vtx][1] = (1.0 - Tween) * StartShape[Vtx][1] + Tween*EndShape[Vtx][1];
	}
	
	//setting pointer array untuk titik openGL dan warna
	glVertexPointer(2, GL_FLOAT, 0, IntermediateShape);
	glColorPointer(3, GL_FLOAT, 0, VertexColors);
	
	//looping untuk delay supaya lambat
	int i;
	for(i = 0; i < 100000; i++);
	glClear(GL_COLOR_BUFFER_BIT);//clear buffer
	glDrawArrays(GL_LINE_LOOP, 0, 12);//membentuk garis loop
	glutSwapBuffers();//menampilkan frame pada layar
	glutPostRedisplay();//meminta untuk menampilkan frame selanjutnya pada layar
}

void InitGL(){
	//memposisikan tepat ditengah.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-HALFX, HALFX, -HALFY, HALFY);
	glMatrixMode (GL_MODELVIEW);
	glClearColor(0,0,0,0);
	
	//mengatur titik array
	glEnableClientState(GL_VERTEX_ARRAY);
	
	//mengatur array warna
	glEnableClientState(GL_COLOR_ARRAY);
	glShadeModel(GL_SMOOTH);
	glViewport(0,0,WindowWidth,WindowHeight);
}

//untuk reshape window
void Reshape(int w, int h){
	glutReshapeWindow(w, (int)(w/RATIO));
	WindowWidth = w;
	WindowHeight = (int)(w/RATIO);
	InitGL();
}

int main(int argc, char** argv) {
	
	//inisialisasi gliut
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	
	WindowWidth = (int)(glutGet((GLenum)GLUT_SCREEN_WIDTH)*.4);
	WindowHeight = (int)(WindowWidth / RATIO);
	
	//buat window
	glutInitWindowSize(WindowWidth, WindowHeight);
	glutInitWindowPosition((int)(glutGet((GLenum)GLUT_SCREEN_WIDTH)*.1), (glutGet((GLenum)GLUT_SCREEN_HEIGHT) / 2) - (WindowHeight / 2));
	
	//membuat tulisan pada window
	glutCreateWindow("BELAJAR TWEENING");
	
	glutDisplayFunc(Display); //tampilin frame
	glutReshapeFunc(Reshape); //reshape ukuran window
	InitGL();// inisialisasi open gl
	glutMainLoop(); //mulai proses
	return 0;
}
