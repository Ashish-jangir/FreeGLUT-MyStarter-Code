// OpenGL c++ Documentation https://docs.microsoft.com/en-us/windows/win32/opengl/opengl
//GLUT Documentation https://www.opengl.org/resources/libraries/glut/spec3/spec3.html
//FreeGLUT Documentation http://freeglut.sourceforge.net/docs/api.php#Initialization
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

void init(void) {
	glClearColor(1, 1, 1, 0);						// white background color( first three argument are red, green and blue. glClear uses color that specified in it
	//forth is alpha value that is used fro blending parameter
	
}
void lineSegment(void) {
	glClear(GL_COLOR_BUFFER_BIT);					// to get the assigned window color displayed
	//the constant specifying that it is the bit values in the color buffer (refresh buffer) that are to be
	//set to the values indicated in the glClearColor function.
	glLoadIdentity();								// only works in GL_MODELVIEW // makes everything default
	glColor3f(0, 0.4, 0.2);
	glBegin(GL_LINES);
	glVertex2i(180, 15);							//Cartesian endpoint coordinates
	glVertex2i(10, 145);
	glEnd();
	glFlush();										// Process all OpenGL routines as quickly as possible. It actullay draw stuff on screen
}
void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-350, 350, -350, 350);						// value of x range from 0 to 200 and y from 0 to 150 and orthogonal projection is used 
	glMatrixMode(GL_MODELVIEW);
}
void main(int argc, char ** argv) {
	glutInit(&argc, argv);							//Initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	// modes of window single frame buffer to use and rgb mode for coloring
	glutInitWindowPosition(50, 0);				// position of window
	glutInitWindowSize(768, 768);					// size of window
	glutCreateWindow("OpenGL Lab Assignment 2");		// title of the window
	init();
	glutDisplayFunc(lineSegment);
	glutReshapeFunc(reshape);
	glutMainLoop();
}
