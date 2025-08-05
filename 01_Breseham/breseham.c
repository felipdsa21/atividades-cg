#include <stdio.h>
#include <stdlib.h>

void imprimir_ponto(int x, int y) {
  printf("(%d, %d)\n", x, y);
}

void algoritmo_breseham(int x1, int y1, int x2, int y2) {
  int dx, dy, incE, incNE, d, x, y;

  dx = x2 - x1;
  dy = y2 - x1;
  d = 2 * dy - dx; // Valor inicial de d

  incE = 2 * dy; // Incremento de E
  incNE = 2 * (dy - dx); // Incremento de NE

  x = x1;
  y = y1;
  imprimir_ponto(x, y);

  while (x < x2) {
    if (d <= 0) {
      // Escolhe E
      d = d + incE;
      x = x + 1;
    } else {
      // Escolhe NE
      d = d + incNE;
      x = x + 1;
      y = y + 1;
    }

    imprimir_ponto(x, y);
  }
}

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

  printf("Pontos calculados:\n");
  algoritmo_breseham(1, 1, 8, 5);

  return EXIT_SUCCESS;
}
