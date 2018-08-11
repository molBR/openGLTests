#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

GLdouble obsX=20, obsY=20, obsZ=20,upX=0 ,upY=0, upZ=1;
void desenhaGrade()
{
	//Definicao dos 3 vetores do espaço.
	glBegin(GL_LINES);
	//Vetor X
	glColor3f(1.0f,0.0f,0.0f);//Vermelho
	glLineWidth(1.0f);
	glVertex3f(0,0,0);
	glVertex3f(5,0,0);
	//Vetor Y
	glColor3f(0.0f,1.0f,0.0f); //Verde
	glLineWidth(1.0f);
	glVertex3f(0,0,0);
	glVertex3f(0,5,0);
	//Vetor X
	glColor3f(0.0f,0.0f,1.0f);  //Azul
	glLineWidth(1.0f);
	glVertex3f(0,0,0);
	glVertex3f(0.0,0.0,5.0);
	glEnd();
}


void desenhaQuadrado()
{
	//Definicao de quadrados
	glBegin(GL_QUADS);
	//Face6
	glColor3f(0.0f,1.0f,1.0f); //Azul claro
	glVertex3f(13.0f, 3.0f, 6.0f);
	glVertex3f(13.0f, 3.0f, 0.0f);
	glVertex3f(13.0f, 9.0f,  0.0f);
	glVertex3f(13.0f, 9.0f,  6.0f);
	//Face1
	glColor3f(1.0f,0.0f,0.0f);//Vermelho
	glVertex3f(7.0f, 9.0f, 6.0f);
	glVertex3f(7.0f, 3.0f, 6.0f);
	glVertex3f(13.0f, 3.0f,  6.0f);
	glVertex3f( 13.0f, 9.0f,  6.0f);
	//Face2
	glColor3f(0.0f,1.0f,0.0f); //Verde
	glVertex3f(7.0f, 9.0f, 0.0f);
	glVertex3f(7.0f, 3.0f, 0.0f);
	glVertex3f(13.0f, 3.0f,  0.0f);
	glVertex3f(13.0f, 9.0f,  0.0f);
	//Face3
	glColor3f(0.0f,0.0f,1.0f); //Azul Escuro
	glVertex3f(7.0f, 9.0f, 6.0f);
	glVertex3f(7.0f, 9.0f, 0.0f);
	glVertex3f(13.0f, 9.0f,  0.0f);
	glVertex3f(13.0f, 9.0f,  6.0f);
	//Face4
	glColor3f(1.0f,1.0f,0.0f); //Amarelo
	glVertex3f(7.0f, 3.0f, 6.0f);
	glVertex3f(7.0f, 3.0f, 0.0f);
	glVertex3f(13.0f, 3.0f,  0.0f);
	glVertex3f(13.0f, 3.0f,  6.0f);
	//Face5
	glColor3f(1.0f,0.0f,1.0f); //Rosa
	glVertex3f(7.0f, 3.0f, 6.0f);
	glVertex3f(7.0f, 3.0f, 0.0f);
	glVertex3f(7.0f, 9.0f,  0.0f);
	glVertex3f(7.0f, 9.0f,  6.0f);


	glEnd();
}



void Display (void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    desenhaGrade();
    desenhaQuadrado();
    glutSwapBuffers();
    

}
void Init(void)
{

	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void resize( int w, int h )
{
 glViewport( 0.0, 0.0, (GLsizei) w, (GLsizei) h );
 glMatrixMode( GL_PROJECTION );
 glLoadIdentity();
 gluPerspective( 65.0, (GLdouble) w / h, 1.0, 100.0 );
 glMatrixMode( GL_MODELVIEW );
 glLoadIdentity();
 gluLookAt( 10.0, 6.0, 40.0,
 10.0, 6.0, 3.0,
 0.0, 1.0, 0.0 );
}

void SpecialKeys(int key, int x, int y)
{
//(10,6,3)
	switch (key) {
		case GLUT_KEY_LEFT : 
						obsX =30;
						obsY =6;
						obsZ =3;
						upX=0;
						upY=0;
						upZ=1;
						break;
		case GLUT_KEY_RIGHT : 
						obsX =(-10);
						obsY =6;
						obsZ =3;
						upX=0;
						upY=0;
						upZ=1;
						break;
		case GLUT_KEY_UP : 
						obsX =10;
						obsY =26;
						obsZ =3;
						upX=0;
						upY=0;
						upZ=1;
						break;
		case GLUT_KEY_DOWN : 
						obsX =10;
						obsY =(-14);
						obsZ =3;
						upX=0;
						upY=0;
						upZ=1;
						break;

		case GLUT_KEY_HOME : 
						obsX =10;
						obsY =6;
						obsZ =23;
						upX=0;
						upY=1;
						upZ=0;
						break;
		case GLUT_KEY_END : 
						obsX =10;
						obsY =6;
						obsZ =(-17);
						upX=0;
						upY=1;
						upZ=0;
						break;
}
glLoadIdentity();
gluLookAt(obsX,obsY,obsZ, 10,6,3, upX,upY,upZ);
	glutPostRedisplay();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Problema 3 - Pedro Vallese 28882");
    Init();
    resize(5,10);
    glutDisplayFunc(Display);
    glutSpecialFunc(SpecialKeys);
    glutMainLoop();
    
    return 0;
}