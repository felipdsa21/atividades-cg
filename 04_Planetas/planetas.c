#include <GL/glut.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  GLfloat x, y, z;
} Vec3;

static int year = 0, day = 0;

static void init(void) {
  glClearColor(0, 0, 0, 0);
}

static void drawStar(void) {
  glPushMatrix();

  glRotatef((GLfloat)day, 0, 1, 0);
  glRotatef(90, 1, 0, 0);

  glutWireSphere(1, 20, 16);
  glPopMatrix();
}

static void drawPlanet(Vec3 pos, bool retrograde) {
  glPushMatrix();

  glRotatef((GLfloat)(retrograde ? -year : year), 0, 1, 0);
  glTranslatef(pos.x, pos.y, pos.z);
  glRotatef((GLfloat)day, 0, 1, 0);
  glRotatef(90, 1, 0, 0);

  glutWireSphere(0.25, 10, 8);
  glPopMatrix();
}

static void drawMoon(Vec3 primaryPos, bool primaryRetrograde, Vec3 pos, Vec3 tlAxis) {
  glPushMatrix();

  glRotatef((GLfloat)(primaryRetrograde ? -year : year), 0, 1, 0);
  glTranslatef(primaryPos.x, primaryPos.y, primaryPos.z);
  glRotatef((GLfloat)(primaryRetrograde ? -year : year), tlAxis.x, tlAxis.y, tlAxis.z);
  glTranslatef(pos.x, pos.y, pos.z);
  glRotatef((GLfloat)day, 0, 1, 0);
  glRotatef(90, 1, 0, 0);

  glutWireSphere(0.08, 10, 8);
  glPopMatrix();
}

static void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1, 1, 0);
  drawStar();

  Vec3 planet1Pos = {.x = 1.8f, .y = -0.4f, .z = 0};
  glColor3f(0.549f, 0.694f, 0.871f);
  drawPlanet(planet1Pos, false);

  Vec3 planet2Pos = {.x = -1.8f, .y = 0.4f, .z = 0.5f};
  glColor3f(0.757f, 0.267f, 0.055f);
  drawPlanet(planet2Pos, true);

  Vec3 moon1Pos = {.x = 0.4f, .y = 0.15f, .z = 0};
  Vec3 moon1TlAxis = {.x = 0, .y = 1, .z = 0};
  glColor3f(0.58f, 0.565f, 0.553f);
  drawMoon(planet2Pos, true, moon1Pos, moon1TlAxis);

  Vec3 moon2Pos = {.x = 0.4f, .y = -0.1f, .z = 0.5f};
  Vec3 moon2TlAxis = {.x = 0, .y = 0, .z = 1};
  glColor3f(0.494f, 0.353f, 0.235f);
  drawMoon(planet2Pos, true, moon2Pos, moon2TlAxis);

  glutSwapBuffers();
}

static void handleReshape(int w, int h) {
  glViewport(0, 0, w, h);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluPerspective(60, (GLfloat)w / (GLfloat)h, 1, 20);
  gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}

static void changeDay(bool negative) {
  day = (day + (negative ? -10 : 10)) % 360;
}

static void changeYear(bool negative) {
  year = (year + (negative ? -5 : 5)) % 360;
}

static void handleKeyboard(unsigned char key, int x, int y) {
  (void)x;
  (void)y;

  switch (key) {
  case 'B':
  case 'b':
    changeDay(isupper(key));
    changeYear(isupper(key));
    break;
  case 'D':
  case 'd':
    changeDay(isupper(key));
    break;
  case 'Y':
  case 'y':
    changeYear(isupper(key));
    break;
  default:
    return;
  }

  glutPostRedisplay();
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Rotacao de planetas");

  init();
  glutDisplayFunc(display);
  glutReshapeFunc(handleReshape);
  glutKeyboardFunc(handleKeyboard);
  glutMainLoop();

  return EXIT_SUCCESS;
}
