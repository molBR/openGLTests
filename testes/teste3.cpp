#include <GL/glut.h>

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
	glVertex3f(0.0,0.0,10.0);
	glEnd();
}



void Display (void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    desenhaGrade();
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
 gluPerspective( 45.0, (GLdouble) w / h, 1.0, 100.0 );
 glMatrixMode( GL_MODELVIEW );
 glLoadIdentity();
 gluLookAt( 10.0, 10.0, 10.0,
 0.0, 0.0, 0.0,
 0.0, 1.0, 0.0 );
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Trabalho1");
    Init();
    resize(5,10);
    glutDisplayFunc(Display);
    glutMainLoop();
    
    return 0;
}