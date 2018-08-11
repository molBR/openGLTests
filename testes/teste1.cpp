#include <GL/glut.h>

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

void init (void)
{
	glClearColor(0.0f,0.0f,0.0f,1.0f);
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(320,240);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Primeiro programa em OpenGL!!!");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}