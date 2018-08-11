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
    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef(angle, 1, 0, 0);
    glRotatef(angle, 0, 1, 0);
    glRotatef(angle, 0, 0, 1);
    glutWireCube(2.0);
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
    glutCreateWindow ("ex6a: smooth cube");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(spin);
    glutMainLoop();
    return 0;
}