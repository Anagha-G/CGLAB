// translate a point, line and triangle without inbuilt functions

#include<GL/glut.h>
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-300, 300, -300, 300);
	glMatrixMode(GL_MODELVIEW);
}
void translate(int x, int y,int tx,int ty) {
	glVertex2i(x + tx, y + ty);
}

void disp() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glPointSize(5);
	glBegin(GL_POINTS);
		translate(0, 0, -80, -80);			// point
	glEnd();
	glBegin(GL_LINES);
		translate(0, 0, 50, 10);			// line
		translate(0, 20, 50, 10);
	glEnd();
	glBegin(GL_TRIANGLES);
		translate(0, 0, -50, 10);			//triangle
		translate(20, 0, -50, 10);
	translate(10, 20, -50, 10);
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 300);

	glutCreateWindow("Translation");
	init();
	glutDisplayFunc(disp);
	glutMainLoop();
	return 0;
}
