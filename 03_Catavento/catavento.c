#include <GL/glut.h>
#include <stdbool.h>
#include <stdlib.h>

static const bool useTimer = false;
static int currentAngle = 0;

static void init(void) {
  glClearColor(0, 0, 0, 0);
  gluOrtho2D(0, 500, 0, 500);
}

static void drawStick(void) {
  glColor3f(246 / 255.0f, 221 / 255.0f, 185 / 255.0f);
  glRecti(248, 100, 252, 250);
}

static void drawBlade(int rotationAngle) {
  glPushMatrix();
  glTranslatef(250, 250, 0);
  glRotatef((GLfloat)rotationAngle, 0, 0, 1);
  glTranslatef(-250, -250, 0);

  glBegin(GL_TRIANGLES);
  glVertex2i(250, 250);
  glVertex2i(250, 200);
  glVertex2i(300, 200);
  glEnd();

  glPopMatrix();
}

static void drawBlades(void) {
  glColor3f(0, 1, 0);
  drawBlade(currentAngle);

  glColor3f(0, 0, 1);
  drawBlade(currentAngle + 90);

  glColor3f(1, 1, 0);
  drawBlade(currentAngle + 180);

  glColor3f(1, 0, 0);
  drawBlade(currentAngle + 270);
}

static void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  drawStick();
  drawBlades();
  glFlush();
}

static void rotate(void) {
  currentAngle = (currentAngle + 4) % 360;
  glutPostRedisplay();
}

static void timer(int value) {
  if (value) {
    rotate();
  }

  glutTimerFunc(1000 / 60, timer, 1);
}

static void handleKeyboard(unsigned char key, int x, int y) {
  (void)x;
  (void)y;

  if (key == 'p') {
    rotate();
  }
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(200, 200);
  glutCreateWindow("Catavento");

  init();
  glutDisplayFunc(display);

  if (useTimer) {
    timer(0);
  } else {
    glutKeyboardFunc(handleKeyboard);
  }

  glutMainLoop();

  return EXIT_SUCCESS;
}
