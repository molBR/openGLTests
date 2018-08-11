#include <GL/glut.h>
using namespace std;
void desenhaGrade()
{
	glColor3f(1.0f,1.0f,1.0f);
	glLineWidth(1.0f);
	glBegin(GL_LINES);
	float x = -10;
	for(;x<=10;x++)
	{
		glVertex2f(-10,x);
		glVertex2f(10,x);
		glVertex2f(x, -10);
		glVertex2f(x, 10);
	}
	glEnd();
	glColor3f(0.0f,0.0f,0.0f);
	glLineWidth(3.0f);
	glBegin(GL_LINES);
	glVertex2f(-10,0);
	glVertex2f(10,0);
	glVertex2f(0,-10);
	glVertex2f(0,10);
	glEnd();
}

void Init(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(desenhaGrade);
	glutSwapBuffers();
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10,10,-10,10);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(100,100);
	glutCreateWindow("TESTE");
	Init();
	
	glutMainLoop();

	return 0;
}