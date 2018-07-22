#include <GL/glut.h>
#include <math.h>
#include <Windows.h>
#include <cstdio>
#define BASE_HEIGHT 4.0/2 //tinggi badan
#define BASE_RADIUS .8/2 //radius badan
#define HEAD_HEIGHT 1.0/2 //tinggi kepala
#define HEAD_RADIUS 0.65/2 //radius kepala
#define EYE_LEVEL 0.45/2 //jarak mata
#define NOSE_LENGTH 0.2/2 //panjang hidung
#define upper_ARM_HEIGHT 2.0/2 //panjang tangan
#define upper_ARM_WIDTH 0.5/2 //lebar tangan
#define lower_ARM_HEIGHT 1.25/2 //panjang lengan
#define lower_ARM_WIDTH 0.5/2 //lebar lengan
#define ARM_TRANSLATION 0.2/2 //jarak tangan dgn badan
#define	upper_LEG_HEIGHT 2.0/2 //panjang kaki bawah
#define upper_LEG_WIDTH 0.5/2 //lebar kaki bawah
#define lower_LEG_HEIGHT 2.0/2 //panjang kaki atas
#define lower_LEG_WIDTH 0.5/2 //lebar kaki atas
#define LEG_TRANSLATION 1.0/2 //jarak antar kaki
int mv_range = 10; //maksimal jarak maju/mundur
double turn_range = 10; //putaran per klik
#define alpha 0.0
#define pi 3.14159265
static GLfloat theta[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }; //posisi default
static GLfloat thets[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }; //posisi default
static GLint axis = 0;
GLUquadricObj *p;
//deklarasi variabel
GLfloat x = 0.0;
GLfloat y = 0.0;
GLfloat xpos = 0.0; //Posisi X
GLfloat ypos = 0.0; //Posisi Y
GLfloat zpos = 0.0; //Posisi Z
GLfloat ambient[3]; //Deklarasi ambient
GLfloat diffuse[3]; //Deklarasi diffuse
GLfloat specular[3]; //Deklarasi specular
GLfloat shiness[] = { 120.0f }; //Deklarasi Shininess
//mengatur tinggi dan lebar Window program
float width = 800;
float height = 600;

//deklarasi fungsi dan prosedur
void base(void);
void head(void);
void lower_rarm(void);
void lower_larm(void);
void upper_rarm(void);
void upper_larm(void);
void lower_rleg(void);
void lower_lleg(void);
void upper_rleg(void);
void upper_lleg(void);
void init(void);
void display(void);
void reshape(int width, int height);
void keyboard(unsigned char, int, int);
void processSpecialKeys(int, int, int);
void pos1(void);
void init1(void);

//BADAN
void base(void) {
	double angle, angleInc;

	angle = pi / 180;
	angleInc = angle;
	glPushMatrix();
	
	//Warna Badan 
	ambient[0] = 0.698; ambient[1] = 0.133; ambient[2] = 0.133; //warna dasar
	diffuse[0] = 0; diffuse[1] = 0; diffuse[2] = 0; //warna bayangan
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5; //pantulan cahaya

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient); //warna dasar
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse); //bayangan
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular); //pantulan cahaya
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness); //kilapan

	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluQuadricDrawStyle(p, GLU_FILL);
	gluCylinder(p, BASE_RADIUS, BASE_RADIUS, BASE_HEIGHT, 20, 20);

	glPopMatrix();

	glPushMatrix();

	gluQuadricDrawStyle(p, GLU_FILL);
	glTranslatef(0.0, BASE_HEIGHT, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluDisk(p, 0.0, BASE_RADIUS, 20, 20);
	glTranslatef(0.0, 0.0, -BASE_HEIGHT);
	gluDisk(p, 0.0, BASE_RADIUS, 20, 20);
	glPopMatrix();
}

//KEPALA
void head(void) {
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glPushMatrix();

	ambient[0] = 0.96; ambient[1] = 0.80; ambient[2] = 0.69;
	diffuse[0] = 1; diffuse[1] = 1; diffuse[2] = 1;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glutSolidSphere(.4, 20, 16);
	glFlush();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.25, -HEAD_RADIUS + 0.12, EYE_LEVEL);

	//Mata Kiri
	ambient[0] = 0; ambient[1] = 0.0; ambient[2] = 0.0;
	diffuse[0] = 1.0; diffuse[1] = 1.0; diffuse[2] = 1.0;
	specular[0] = 0.5; specular[1] = 0.5; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	gluQuadricDrawStyle(p, GLU_FILL);
	gluSphere(p, 0.125, 6, 6);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.25, -HEAD_RADIUS + 0.12, EYE_LEVEL);
	
	//Mata kanan
	ambient[0] = 0; ambient[1] = 0; ambient[2] = 0.0;
	diffuse[0] = 1.0; diffuse[1] = 1.0; diffuse[2] = 1.0;
	specular[0] = 0.5; specular[1] = 0.5; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, shiness);


	gluQuadricDrawStyle(p, GLU_FILL);
	gluSphere(p, 0.125, 6, 6);
	glPopMatrix();

	//Hidung
	glPushMatrix();
	ambient[0] = 1.0; ambient[1] = 0.5; ambient[2] = 0.0;
	diffuse[0] = 1.0; diffuse[1] = 0.5; diffuse[2] = 0.0;
	specular[0] = 0.5; specular[1] = 0.5; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, shiness);
	glTranslatef(0.0, -HEAD_RADIUS, NOSE_LENGTH);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluQuadricDrawStyle(p, GLU_FILL);
	gluCylinder(p, 0.125, 0, NOSE_LENGTH, 8, 6);
	glPopMatrix();

	glPopMatrix();
}

//TANGAN KIRI ATAS
void upper_rarm(void) {
	glPushMatrix();
	//Warna 
	ambient[0] = 0.698; ambient[1] = 0.133; ambient[2] = 0.133;
	diffuse[0] = 0.412; diffuse[1] = 0.412; diffuse[2] = 0.412;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, 0.5 * upper_ARM_HEIGHT, ARM_TRANSLATION);
	glScalef(upper_ARM_WIDTH, upper_ARM_HEIGHT, upper_ARM_WIDTH);
	glutSolidCube(1.0);
	glPopMatrix();
}

//TANGAN KANAN ATAS
void upper_larm(void) {
	glPushMatrix();
	//Warna 
	ambient[0] = 0.698; ambient[1] = 0.133; ambient[2] = 0.133;
	diffuse[0] = 0.412; diffuse[1] = 0.412; diffuse[2] = 0.412;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	////glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	////glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, 0.5 * upper_ARM_HEIGHT, -ARM_TRANSLATION);
	glScalef(upper_ARM_WIDTH, upper_ARM_HEIGHT, upper_ARM_WIDTH);
	glutSolidCube(1.0);
	glPopMatrix();
}

//KAKI KANAN ATAS
void upper_rleg(void) {
	glPushMatrix();
	//Warna 
	ambient[0] = 0; ambient[1] = 0; ambient[2] = 0.502;
	diffuse[0] = 0.412; diffuse[1] = 0.412; diffuse[2] = 0.412;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, 0.5 * upper_LEG_HEIGHT, LEG_TRANSLATION);
	glScalef(upper_LEG_WIDTH, upper_LEG_HEIGHT, upper_LEG_WIDTH);
	glutSolidCube(1.0);
	glPopMatrix();
}

//KAKI KIRI ATAS
void upper_lleg(void) {
	glPushMatrix();
	//Warna 
	ambient[0] = 0; ambient[1] = 0; ambient[2] = 0.502;
	diffuse[0] = 0.412; diffuse[1] = 0.412; diffuse[2] = 0.412;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, 0.5 * upper_LEG_HEIGHT, -LEG_TRANSLATION);
	glScalef(upper_LEG_WIDTH, upper_LEG_HEIGHT, upper_LEG_WIDTH);
	glutSolidCube(1.0);
	glPopMatrix();
}

//TANGAN KANAN BAWAH
void lower_rarm(void) {
	glPushMatrix();
	//Warna
	ambient[0] = 1.000; ambient[1] = 0.627; ambient[2] = 0.478;
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, 0.5 * lower_ARM_HEIGHT, ARM_TRANSLATION);
	glScalef(lower_ARM_WIDTH, lower_ARM_HEIGHT, lower_ARM_WIDTH);
	glutSolidCube(1.0);
	glPopMatrix();
}

//TANGAN KIRI BAWAH
void lower_larm(void) {
	glPushMatrix();
	//Warna
	ambient[0] = 1.000; ambient[1] = 0.627; ambient[2] = 0.478;
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, 0.5 * lower_ARM_HEIGHT, -ARM_TRANSLATION);
	glScalef(lower_ARM_WIDTH, lower_ARM_HEIGHT, lower_ARM_WIDTH);
	glutSolidCube(1.0);
	glPopMatrix();
}

//KAKI KIRI BAWAH
void lower_lleg(void) {
	glPushMatrix();
	//Warna
	ambient[0] = 1.000; ambient[1] = 0.627; ambient[2] = 0.478;
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, 0.5 * lower_LEG_HEIGHT, -LEG_TRANSLATION);
	glScalef(lower_LEG_WIDTH, lower_LEG_HEIGHT, lower_LEG_WIDTH);
	glutSolidCube(1.0);
	glPopMatrix();
}

//KAKI KANAN BAWAH
void lower_rleg(void) {
	glPushMatrix();
	//Warna
	ambient[0] = 1.000; ambient[1] = 0.627; ambient[2] = 0.478;
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, 0.5 * lower_LEG_HEIGHT, LEG_TRANSLATION);
	glScalef(lower_LEG_WIDTH, lower_LEG_HEIGHT, lower_LEG_WIDTH);
	glutSolidCube(1.0);
	glPopMatrix();
}

//deklarasi lighting, specular, ambient, dll
void init1(void) {
	GLfloat mat_specular[] = { 0.3, .3, .3, .3 };
	GLfloat mat_shininess[] = { 0.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat white_light[] = { .1, .1, .1, .1 };
	GLfloat lmodel_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

//Menampilkan bagian bagian yang sudah dibuat
void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.3, 5.3, 12.0, 0.0, 1.25, 0.0, 0.0, 1.0, 0.0);

	//BASE 
	glTranslatef(xpos, ypos, zpos);
	glRotatef(theta[0], 0.0, 1.0, 0.0);
	base();

	//HEAD
	glPushMatrix();
	glTranslatef(0.0, BASE_HEIGHT + HEAD_HEIGHT / 2, 0.0);
	glRotatef(theta[2], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	head();
	glPopMatrix();

	//RIGHT ARM
	glPushMatrix();
	glTranslatef(BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
	glRotatef(180.0, 0.0, 0.0, 1.0);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glRotatef(theta[4], 0.0, 0.0, 1.0);
	upper_rarm();
	glTranslatef(0.0, upper_ARM_HEIGHT, 0.0);
	glRotatef(0.0, 0.0, 0.0, 180.0);
	glRotatef(theta[6], 0.0, 0.0, 1.0);
	lower_rarm();
	glPopMatrix();

	//LEFT ARM
	glPushMatrix();
	glTranslatef(-BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
	glRotatef(180.0, 0.0, 0.0, 1.0);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glRotatef(theta[3], 0.0, 0.0, 1.0);
	upper_larm();
	glTranslatef(0.0, upper_ARM_HEIGHT, 0.0);
	glRotatef(0.0, 0.0, 0.0, 180.0);
	glRotatef(theta[5], 0.0, 0.0, 1.0);
	lower_larm();
	glPopMatrix();

	//LEFT LEG
	glPushMatrix();
	glTranslatef(BASE_RADIUS * 2 , BASE_HEIGHT / 4 - .5, 0.0);
	glRotatef(180.0, 0.0, 0.0, 1.0);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glRotatef(theta[7], 0.0, 0.0, 1.0);
	upper_lleg();
	glTranslatef(0.0, upper_LEG_HEIGHT, 0.0);
	glRotatef(0.0, 0.0, 0.0, 180.0);
	glRotatef(theta[9], 0.0, 0.0, 1.0);
	lower_lleg();
	glPopMatrix();

	//RIGHT LEG
	glPushMatrix();
	glTranslatef(-BASE_RADIUS * 2, BASE_HEIGHT / 4 - .5, 0.0);
	glRotatef(180.0, 0.0, 0.0, 1.0);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glRotatef(theta[10], 0.0, 0.0, 1.0);
	upper_rleg();
	glTranslatef(0.0, upper_LEG_HEIGHT, 0.0);
	glRotatef(0.0, 0.0, 0.0, 180.0);
	glRotatef(thets[10], 0.0, 0.0, 1.0);
	lower_rleg();
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

//Control
void keyboard(unsigned char key, int x, int y) {
	switch (key) {

		//Kepala tengok Kiri
	case 'a': theta[1] += 5.0;
		if (theta[1] > 90.0)
			theta[1] = 90.0;
		break;
		//Kepala tengok Kanan
	case 'z': theta[1] -= 5.0;
		if (theta[1] < -90.0)
			theta[1] = -90.0;
		break;
		//Kepala tengok atas
	case 'o': theta[2] += 5.0;
		if (theta[2] > 45.0)
			theta[2] = 45.0;
		break;
		//Kepala tengok bawah
	case 'p': theta[2] -= 5.0;
		if (theta[2] < -45.0)
			theta[2] = -45.0;
		break;
	
	case 'k': theta[3] -= 5.0; break;//Tangan kanan kedepan
	case 'l': theta[3] += 5.0; break;//Tangan kanan kebelakang

	case 'h': theta[4] -= 5.0; break;//Tangan kiri kedepan
	case 'j': theta[4] += 5.0; break;//Tangan kiri kebelakang

	case 'n': theta[5] -= 5.0; break;//Tangan kanan bawah kedepan
	case 'm': theta[5] += 5.0; break;//Tangan kanan bawah kebelakang

	case 'v': theta[6] -= 5.0; break;//Tangan kiri bawah kedepan
	case 'b': theta[6] += 5.0; break;//Tangan kiri bawah kebelakang


	case '1': theta[7] -= 5.0; break;//Kaki kiri kedepan
	case '2': theta[7] += 5.0; break;//Kaki kiri kebelakang

	case '3': theta[9] -= 5.0; break;//Kaki kiri bawah kedepan
	case '4': theta[9] += 5.0; break;//Kaki kiri bawah kebelakang

	case '5': theta[10] -= 5.0; break;//Kaki kanan kedepan
	case '6': theta[10] += 5.0; break;//Kaki kanan kebelakang

	case '7': thets[10] -= 5.0; break;//Kaki kanan bawah kedepan
	case '8': thets[10] += 5.0; break;//Kaki kanan bawah kebelakang

	//reset ke bentuk & posisi awal
	case 'e': theta[0] = theta[1] = theta[2] = theta[3] = theta[4] = theta[5] = theta[6] = theta[7] = theta[9] = theta[10] = thets[10] = xpos = ypos = zpos = 0.0;
		break;
	//reset ke bentuk awal
	case 'r': theta[0] = theta[1] = theta[2] = theta[3] = theta[4] = theta[5] = theta[6] = theta[7] = theta[9] = theta[10] = thets[10] = 0.0;
		break;
	//keluar
	case 'q': exit(0); break;
	}
	glutPostRedisplay();
}

//Control 2
void processSpecialKeys(int key, int x, int y) {
	switch (key) {
		//Maju hingga maksimal mv_range
	case GLUT_KEY_UP:
		xpos -= cos(90 * pi / 180 + theta[0] * pi / 180);
		zpos += sin(90 * pi / 180 + theta[0] * pi / 180);
		if (xpos > mv_range)
			xpos = mv_range;
		if (zpos > mv_range)
			zpos = mv_range;
		if (xpos < -mv_range)
			xpos = -mv_range;
		if (zpos < -mv_range)
			zpos = -mv_range;
		break;
		//Mundur hingga maksimal mv_range
	case GLUT_KEY_DOWN:
		xpos += cos(90 * pi / 180 + theta[0] * pi / 180);
		zpos -= sin(90 * pi / 180 + theta[0] * pi / 180);

		if (xpos > mv_range)
			xpos = mv_range;
		if (zpos > mv_range)
			zpos = mv_range;
		if (xpos < -mv_range)
			xpos = -mv_range;
		if (zpos < -mv_range)
			zpos = -mv_range;
		break;
		//Berputar Menghadap kanan
	case GLUT_KEY_RIGHT: theta[0] -= turn_range; break;
		//Berputar Menghadap kanan
	case GLUT_KEY_LEFT: theta[0] += turn_range; break;
		//Naik
	case GLUT_KEY_PAGE_UP: ypos += 1.0; break;
		//Turun
	case GLUT_KEY_PAGE_DOWN: ypos -= 1.0; break;

		//Posisi 1
	case GLUT_KEY_F1: pos1(); break;
	}
	glutPostRedisplay();
}

//Posisi 1
void pos1(void) {
	theta[10] = -75; 
	thets[10] = 75;
	theta[0] = 130;
	theta[2] = -80;
	theta[1] = -45;
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0, (GLfloat)w / (GLfloat)h, 0.5, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//deklarasi cahaya
void init(void) {
	GLfloat lightIntensity[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat light_position[] = { 2.0f, 6.0f, 3.0f, 0.0f };

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	p = gluNewQuadric();

}

//Tutorial
void tutor(void) {
	printf("====================CONTROL====================\n");
	printf("\nKepala Tengok Kanan\t\t : z");
	printf("\nKepala Tengok Kiri\t\t : a");
	printf("\nKepala Tengok Atas\t\t : o");
	printf("\nKepala Tengok Bawah\t\t : p");
	printf("\nTangan Kanan Kedepan\t\t : k");
	printf("\nTangan Kanan Kebelakang\t\t : l");
	printf("\nTangan Kiri Kedepan\t\t : h");
	printf("\nTangan Kiri Kebelakang\t\t : j");
	printf("\nTangan Kanan Bawah Kedepan\t : n ");
	printf("\nTangan Kanan Bawah Kebelakang\t : m");
	printf("\nTangan Kiri Bawah Kedepan\t : v");
	printf("\nTangan Kiri Bawah Kebelakang\t : b");
	printf("\nKaki Kanan Kedepan\t\t : 5");
	printf("\nKaki Kanan Kebelakang\t\t : 6");
	printf("\nKaki Kiri Kedepan\t\t : 1");
	printf("\nKaki Kiri Kebelakang\t\t : 2");
	printf("\nKaki Kanan Bawah Kedepan\t : 7");
	printf("\nKaki Kanan Bawah Kebelakang\t : 8");
	printf("\nKaki Kiri Bawah Kedepan\t\t : 3");
	printf("\nKaki Kiri Bawah Kebelakang\t : 3");
	printf("\nMaju\t\t\t\t : Arah Atas");
	printf("\nMundur\t\t\t\t : Arah Bawah");
	printf("\nHadap Kanan\t\t\t : Arah Kanan");
	printf("\nHadap Kiri\t\t\t : Arah Kiri\n");
	printf("\n----------------------------------------------------");
	printf("\nReset Bentuk awal\t\t : r");
	printf("\nReset Posisi & Bentuk awal\t : e");
	printf("\nKeluar\t\t\t\t : q");
	printf("\n====================================================");
}

//Driver
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("UAS Grafika Komputer");

	printf("UAS GRAFIKA KOMPUTER\n");
	printf("\n");
	printf("Anggota Kelompok : \n");
	printf("Abdul Wahid\n");
	printf("Akram Rahardi R\n");
	printf("Bella Syafira H\n\n");

	tutor();
	init();
	init1();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(processSpecialKeys);
	glutMainLoop();
	return 0;
}