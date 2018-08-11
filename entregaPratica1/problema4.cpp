#include <GL/glut.h>
 
GLfloat angle= 0.0;
 
void spin (void)
{
    angle+= 1.0;
    glutPostRedisplay();
}
 
void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity ();
    gluLookAt (20.0, 20.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef(angle, 1, 0, 0);
    glRotatef(angle, 0, 1, 0);
    glRotatef(angle, 0, 0, 1);
	//Vetor X
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
    glutSwapBuffers();  // added line pg35
    // glFlush(); remove line
}
 
void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective (60, (GLfloat) w / (GLfloat) h, 1.0, 100.0);
    glMatrixMode (GL_MODELVIEW);
}
 
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE); // added line pg35
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Problema 4 - Pedro Vallese 28882");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(spin);
    glutMainLoop();
    return 0;
}