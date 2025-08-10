#include <GL/glut.h>
#include <stdlib.h>

static void init(void) {
  glClearColor(0, 0, 0, 0);
  gluOrtho2D(0, 500, 0, 500);
}

static void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);

  // Suporte
  glColor3f(1, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2i(248, 100);
  glVertex2i(248, 250);
  glVertex2i(251, 250);
  glVertex2i(251, 100);
  glEnd();

  // Triângulos
  glColor3f(0, 1, 0);
  glBegin(GL_TRIANGLES);
  glVertex2i(250, 250);
  glVertex2i(230, 200);
  glVertex2i(270, 200);
  glEnd();

  glColor3f(1, 0, 0);
  glBegin(GL_TRIANGLES);
  glVertex2i(250, 250);
  glVertex2i(200, 270);
  glVertex2i(200, 230);
  glEnd();

  glColor3f(1, 1, 1);
  glBegin(GL_TRIANGLES);
  glVertex2i(250, 250);
  glVertex2i(270, 300);
  glVertex2i(230, 300);
  glEnd();

  glColor3f(0, 0, 1);
  glBegin(GL_TRIANGLES);
  glVertex2i(250, 250);
  glVertex2i(300, 230);
  glVertex2i(300, 270);
  glEnd();

  glFlush();
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(200, 200);
  glutCreateWindow("Flor de abril");

  init();
  glutDisplayFunc(display);
  glutMainLoop();

  return EXIT_SUCCESS;
}
