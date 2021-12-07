#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

GLfloat bxx=750;

GLfloat yss=700,ds=700;
GLsizei winWidth = 800, winHeight = 800;
GLfloat xwcMin = 0.0, xwcMax = 799.0;
GLfloat ywcMin = 0.0, ywcMax = 799.0;

static int window;
static int menu_id=2;
static int submenu_id=1;
static int value = 0;
int a[40],b[40],c[40],d[40],e[40],f[40],g[40],h[40];



void *font;
void *currentfont;

void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);
 
	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,1.0,1.0);
		glutBitmapCharacter(currentfont,*c);
	}
}


typedef struct wcPt3D
{
GLfloat x, y, z;
};


void bino(GLint n, GLint *C)
{
GLint k, j;
for (k = 0; k <= n; k++)
{
C[k] = 1;
for (j = n; j >= k + 1; j--)
C[k] *= j;
for (j = n - k; j >= 2; j--)
C[k] /= j;
}
}
void computebzPt(GLfloat u, wcPt3D *bzPt, GLint nCtrlPts, wcPt3D *ctrlPts, GLint *C)
{
GLint k, n = nCtrlPts - 1;
GLfloat bzBdFcn;
bzPt->x = bzPt->y = bzPt->z = 0.0;
for (k = 0; k< nCtrlPts; k++)
{
bzBdFcn = C[k] * pow(u, k) * pow(1 - u, n - k);
bzPt->x += ctrlPts[k].x * bzBdFcn;
bzPt->y += ctrlPts[k].y * bzBdFcn;
bzPt->z += ctrlPts[k].z * bzBdFcn;
}
}
void bezier(wcPt3D *ctrlPts, GLint nCtrlPts, GLint nbzCPts)
{
wcPt3D bzCPt;
GLfloat u;
GLint *C, k;
C = new GLint[nCtrlPts];
bino(nCtrlPts - 1, C);
glBegin(GL_LINE_STRIP);
for (k = 0; k <= nbzCPts; k++)
{
u = GLfloat(k) / GLfloat(nbzCPts);
computebzPt(u, &bzCPt, nCtrlPts, ctrlPts, C);
glVertex2f(bzCPt.x, bzCPt.y);
}
glEnd();
delete[]C;
}
void winReshapeFun(GLint newWidth, GLint newHeight)
{
glViewport(0, 0, newWidth, newHeight);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(xwcMin, xwcMax, ywcMin, ywcMax);
glClear(GL_COLOR_BUFFER_BIT);
}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);

glColor3f(0,0,0);
drawstring(230,750,0," ");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);

glColor3f(0,0,0);
drawstring(200,730,0,"ACHARYA INSTITUTE OF TECHNOLOGY");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);

glColor3f(0,0,0);
drawstring(80,700,0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);

glColor3f(0,0.5,0);
drawstring(330,600,0,"A mini project on");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);

glColor3f(0,0.5,0);
drawstring(330,570,0,"Ozone Depletion");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);

glColor3f(0,0.5,0);
drawstring(335,540,0,"Using openGL");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);

glColor3f(0,0.5,0);
drawstring(10,400,0,"Harshit Karn");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);

glColor3f(0,0.5,0);
drawstring(10,350,0,"1AY18CS041");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);


glColor3f(0,0.5,0);
drawstring(610,400,0,"Kotha Srinadh");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);

glColor3f(0,0.5,0);
drawstring(610,350,0,"1AY18CS053");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);

glColor3f(0,0.5,0);
drawstring(300,300,0,"Under the Guidance of");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);

glColor3f(0,0.5,0);
drawstring(300,250,0,"VARALAKSHMI B D");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(0,0.5,0);
drawstring(290,200,0,"Proessor,Dept. of CSE");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);

glColor3f(0,0,1);
drawstring(260,100,0,"Press Right Click to continue");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);


if (value == 1)
{
glDisable(GL_LIGHT0);
return; //glutPostRedisplay();
}
else if (value == 2)
{
glPushMatrix();
glColor3d(1.0, 0.0, 0.0);
//glutDisplayFunc(displayFunc);
GLint nCtrlPts = 4, nbzCPts = 20;



glColor3f(0,0,0);


glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 1.0, 1.0);
glPointSize(5);
glPushMatrix();
glLineWidth(5);
glColor3f(0,1,0.8); 






for(int a=100;a<=750;a=a+25){
if(a<=350||a>=550){
for(int it=0;it<30;it++){
wcPt3D ctrlPts1[4] = {
{ a, bxx, 0 },
{ a-20, bxx-50, 0 },
{ a+20, bxx-100, 0 },
{ a, bxx-150, 0 }
};

	bxx+=0.001;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	bezier(ctrlPts1, nCtrlPts, nbzCPts);
}
}}



glPopMatrix();
glLineWidth(1);


if(bxx<=950){
glColor3f(0,0.7,0.5);
glBegin(GL_POLYGON);
glVertex2f(500,400);
glVertex2f(700,400);
glVertex2f(700,500);
glVertex2f(500,500);
glEnd();

glColor3f(0,0.7,0.6);
glBegin(GL_POLYGON);
glVertex2f(500,500);
glVertex2f(550,550);
glVertex2f(750,550);
glVertex2f(700,500);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(700,500);
glVertex2f(750,550);
glVertex2f(750,450);
glVertex2f(700,400);
glEnd();

glColor3f(0,0.7,0.5);
glBegin(GL_POLYGON);
glVertex2f(500,390);
glVertex2f(700,390);
glVertex2f(700,90);
glVertex2f(500,90);
glEnd();

glColor3f(0,0.7,0.6);
glBegin(GL_POLYGON);
glVertex2f(700,390);
glVertex2f(700,90);
glVertex2f(750,140);
glVertex2f(750,440);
glEnd();

glColor3f(0,0.7,0.5);
glBegin(GL_POLYGON);
glVertex2f(500,400);
glVertex2f(500,500);
glVertex2f(400,450);
glVertex2f(400,350);
glEnd();

glColor3f(0,0.7,0.6);
glBegin(GL_POLYGON);
glVertex2f(500,500);
glVertex2f(400,450);
glVertex2f(395,455);
glVertex2f(495,505);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(400,450);
glVertex2f(395,455);
glVertex2f(395,355);
glVertex2f(400,350);
glEnd();

glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(660,320);
glVertex2f(670,320);
glVertex2f(670,270);
glVertex2f(660,270);
glEnd();


glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(505,405);
glVertex2f(695,405);
glVertex2f(695,495);
glVertex2f(505,495);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(495,405);
glVertex2f(495,495);
glVertex2f(405,445);
glVertex2f(405,355);
glEnd();

glColor3f(0,1,0.8);
glBegin(GL_POLYGON);
glVertex2f(505,425);
glVertex2f(555,475);
glVertex2f(695,475);
glVertex2f(695,425);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(100,200);
glVertex2f(100,400);
glVertex2f(350,400);
glVertex2f(350,200);
glEnd();

glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(105,250);
glVertex2f(105,395);
glVertex2f(345,395);
glVertex2f(345,250);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES);
for(int i=290;i<393;i=i+5){
glVertex2f(107,i);
glVertex2f(343,i);}
glEnd();

glColor3f(0,0.3,0.3);
glBegin(GL_POLYGON);
glVertex2f(107,258);
glVertex2f(107,282);
glVertex2f(293,282);
glVertex2f(293,258);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(298,258);
glVertex2f(298,282);
glVertex2f(340,282);
glVertex2f(340,258);
glEnd();



glPointSize(10);
glBegin(GL_POINTS);
glColor3f(0,1,0);
glVertex2f(312,270);
glColor3f(1,0,0);
glVertex2f(326,270);
glEnd();

glColor3f(0,0,1);
drawstring(120,50,0,"Air Conditioner");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);

glColor3f(0,0,1);
drawstring(550,50,0,"Refrigerator");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);

glColor3f(0,0,1);
drawstring(450,675,0,"CFC");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);

}

else if(bxx<=3100){

glClearColor(0.0, 0.0, 0.0, 0.0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0, 0.0, 1.0);
glPointSize(5);
glPushMatrix();
glLineWidth(10);
glColor3f(0,0,1);

wcPt3D ctrlPts2[4] = {
{200, 400 , 0 },
{200,680, 0 },
{ 600,680, 0 },
{ 600,400, 0 }
};

wcPt3D ctrlPts3[4] = {
{200, 400 , 0 },
{200,120, 0 },
{ 600,120, 0 },
{ 600,400, 0 }
};

wcPt3D ctrlPts4[4] = {
{300, 550 , 0 },
{200,450, 0 },
{ 300,350, 0 },
{ 350,250, 0 }
};

wcPt3D ctrlPts5[4] = {
{350, 250 , 0 },
{350,230, 0 },
{ 370,260, 0 },
{ 375,270, 0 }
};

wcPt3D ctrlPts6[4] = {
{375, 270 , 0 },
{385,400, 0 },
{ 420,480, 0 },
{ 430,450, 0 }
};

wcPt3D ctrlPts7[4] = {
{300, 550 , 0 },
{300,480, 0 },
{400,550, 0 },
{ 430,450, 0 }
};

wcPt3D ctrlPts8[4] = {
{550, 550 , 0 },
{450,570, 0 },
{440,500, 0 },
{ 500,450, 0 }
};

wcPt3D ctrlPts9[4] = {
{500, 450 , 0 },
{500,420, 0 },
{530,300, 0 },
{ 570,300, 0 }
};

wcPt3D ctrlPts10[4] = {
{150, 400 , 0 },
{150,750, 0 },
{ 650,750, 0 },
{ 650,400, 0 }
};

wcPt3D ctrlPts11[4] = {
{150, 400 , 0 },
{150,50, 0 },
{ 650,50, 0 },
{ 650,400, 0 }
};

wcPt3D ctrlPts12[4] = {
{148, 480 , 0 },
{198,500, 0 },
{ 203,550, 0 },
{ 168,550, 0 }
};






	
	bezier(ctrlPts2, nCtrlPts, nbzCPts);
	bezier(ctrlPts3, nCtrlPts, nbzCPts);
	
	glColor3f(0,0.5,0);
	bezier(ctrlPts4, nCtrlPts, nbzCPts);
	bezier(ctrlPts5, nCtrlPts, nbzCPts);
	bezier(ctrlPts6, nCtrlPts, nbzCPts);
	bezier(ctrlPts7, nCtrlPts, nbzCPts);
	bezier(ctrlPts8, nCtrlPts, nbzCPts);
	bezier(ctrlPts9, nCtrlPts, nbzCPts);
	
	glColor3f(0.7,1,0.8);
	glLineWidth(40);
	bezier(ctrlPts10, nCtrlPts, nbzCPts);
	bezier(ctrlPts11, nCtrlPts, nbzCPts);
	
	glColor3f(0,0,0);
	glLineWidth(10);
	if(bxx>=2500){
	for(int iz=0;iz<38;iz++){
	glTranslatef(-0.8,0,0);
	bezier(ctrlPts12, nCtrlPts, nbzCPts);
	}}
	glPopMatrix();
	glPushMatrix();
	glPointSize(1);
	glLineWidth(1);
	
	glColor3f(1,0,1);
	drawstring(50,yss-30,0,"Cl");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(1,0,1);
	drawstring(80,yss-30,0,"Cl");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	
	glColor3f(1,0,1);
	drawstring(110,670,0,"Cl");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	
	glColor3f(1,0,1);
	drawstring(80,yss+40,0,"C");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	
	glColor3f(1,0,1);
	drawstring(10,yss+40,0,"CFC");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	
	glColor3f(1,0,1);
	drawstring(220,yss+40,0,"Ozone");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	
	glColor3f(1,0,1);
	drawstring(80,yss+80,0,"F");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	
	glColor3f(1,0,1);
	drawstring(150,710,0,"O");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	
	glColor3f(1,0,1);
	drawstring(175,yss+70,0,"O");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	
	glColor3f(1,0,1);
	drawstring(200,yss+10,0,"O");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	
	if(bxx>2800){
	glColor3f(1,0,1);
	drawstring(10,560,0,"Ozone Depletion");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	}
	
	if(bxx<=1200){
	glColor3f(1,0,1);
	drawstring(10,10,0,"CFC released from refrigeretor and AC reaches atmosphere");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	}
	
	if(bxx<=1700&&bxx>1200){
	glColor3f(1,0,1);
	drawstring(10,10,0,"One Cl atom breaks apart from CFC molecule");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	}
	
	if(bxx>1700&&bxx<2800){
	glColor3f(1,0,1);
	drawstring(10,10,0,"Cl atom steals one atom of oxygen and forms chlorine monoxide");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	}
	
	
	if(bxx>2800){
	glColor3f(1,0,1);
	drawstring(10,10,0,"This cycle repeats over and over again reducing ozone layer thickness");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	}
	
	glColor3f(1,0,1);
	drawstring(450,250,0,"Earth");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	
	glColor3f(1,0,1);
	drawstring(550,100,0,"Ozone Layer");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	
	
	if(bxx>=2000){
	for(int iii=0;iii<20;iii++)
	yss+=0.1;
}	
	glColor3f(1,0,1);
	glBegin(GL_LINES);
	glVertex2f(87,yss+40);
	glVertex2f(57,yss);
	glVertex2f(87,yss+40);
	glVertex2f(87,yss);
	if(bxx<=1200){
		glVertex2f(87,740);
		glVertex2f(117,700);
	}
	if(bxx<=1700){
		glVertex2f(160,730);
		glVertex2f(185,770);
	}
	glVertex2f(87,yss+60);
	glVertex2f(87,yss+80);
	
	glVertex2f(210,yss+30);
	glVertex2f(185,yss+70);
	if(bxx>=1700){
		glVertex2f(117,690);
		glVertex2f(160,710);
	}
	
	glEnd();
	
	glPointSize(5);
	glColor3f(1,1,1);
	glBegin(GL_POINTS);
	
	for(int ist=0;ist<40;ist++){
	glVertex2f(a[ist],b[ist]);
	glVertex2f(c[ist],d[ist]);
	glVertex2f(e[ist],f[ist]);
	glVertex2f(g[ist],h[ist]);
	}
	
	glEnd();
	

}

else{
glClearColor(1.0, 1.0, 1.0, 1.0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0, 0.0, 1.0);
glPointSize(5);
glPushMatrix();
glLineWidth(5);
glColor3f(0,0,1);
wcPt3D ctrlPts14[4] = {
{0,0, 0 },
{200,200, 0 },
{600,200, 0 },
{800,0, 0 }
};
for(int lo=200;lo<=600;lo=lo+200){
for(int uv=0;uv<30;uv++){
wcPt3D ctrlPts13[4] = {
{lo,ds, 0 },
{lo-20,ds-200, 0 },
{lo+30,ds+100, 0 },
{lo+20,ds-100, 0 }
};
if(ds>250&&bxx>3500)
ds=ds-0.01;////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bezier(ctrlPts13, nCtrlPts, nbzCPts);
}
glBegin(GL_LINES);
glVertex2f(lo+10,ds-70);
glVertex2f(lo+20,ds-100);
glVertex2f(lo+30,ds-70);
glVertex2f(lo+20,ds-100);
glEnd();
}
glColor3f(0,0,1);
	drawstring(360,730,0,"UV RAYS");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);

if(ds==700){	
glColor3f(1,0,1);
	drawstring(50,400,0,"Ozone depletion increases UV radiation that reaches the earth surfaces");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
}




if(ds<250){	
glColor3f(0,0,0);
	drawstring(50,400,0,"This increased radiation has various negative impact on our planet");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
}

if(ds<250){
GLfloat spec[]={1.0,1.0,0.0,1.0};
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glLightfv(GL_LIGHT0,GL_DIFFUSE,spec);

}


glColor3f(0,0.5,0);
for(int i=0;i<40;i++){
glTranslatef(0,-3.8,0);
bezier(ctrlPts14, nCtrlPts, nbzCPts);
}

glColor3f(0,0,0);
	drawstring(350,200,0,"Earth");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);

}



glColor3f(0,0,0);



glFlush();
glutPostRedisplay();
glutSwapBuffers();

glPopMatrix();
}
glFlush();
}
void menu(int num)
{
if (num == 0)
{
glutDestroyWindow(window);
exit(0);
}
else
{
value = num;
}
glutPostRedisplay();
}
void createMenu(void)
{
submenu_id = glutCreateMenu(menu);
glutAddMenuEntry("Start Animation", 2);
menu_id = glutCreateMenu(menu);
glutAddMenuEntry("Clear", 1);
glutAddSubMenu("Ozone Depletion", submenu_id);
glutAddMenuEntry("Quit", 0);
glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void myinit()
{
glViewport(0, 0, 800, 800);
glClearColor(1.0, 1.0, 1.0, 1.0);
glColor3f(1.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 799.0, 0.0, 799.0);
}
int main(int argc, char **argv)
{
for(int i=0;i<40;i++){
	a[i]=rand()%(200-40+1)+40;
	b[i]=rand()%(760-40+1)+40;
	c[i]=rand()%(760-200+1)+200;
	d[i]=rand()%(200-40+1)+40;
	e[i]=rand()%(760-600+1)+600;
	f[i]=rand()%(760-200+1)+200;
	g[i]=rand()%(600-200+1)+200;
	h[i]=rand()%(760-600+1)+600;
}

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
glutInitWindowSize(800, 800);
glutInitWindowPosition(100, 100);
window=glutCreateWindow("Ozone Depletion");
createMenu();
glClearColor(0.0, 0.0, 0.0, 0.0);
glutDisplayFunc(display);
glutReshapeFunc(winReshapeFun);
myinit();
glutMainLoop();
}
