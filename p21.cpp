// Different line styles using line stipple

#include<GL/glut.h>
void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300, 300, -300, 300);
    glMatrixMode(GL_MODELVIEW);
}

void disp() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0xf0f0);       //dashed
    glBegin(GL_LINES);
        glVertex2i(-100, 0);
        glVertex2i(+100, 0);
    glEnd();

    glLineStipple(1, 0x8080);
    glBegin(GL_LINES);
        glVertex2i(-100, 10);
        glVertex2i(+100, 10);
    glEnd();

    glLineStipple(1, 0x1010);   //dotted
    glBegin(GL_LINES);
        glVertex2i(-100, 20);
        glVertex2i(+100, 20);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 300);

    glutCreateWindow("Line styles");
    init();
    glutDisplayFunc(disp);
    glutMainLoop();
    return 0;
}
