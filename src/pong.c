#include <math.h>
#include <stdio.h>

void draw(int, int, int, int, int, int);
void winner(int);

int main() {
  int sc1 = 0, sc2 = 0, x_r1 = 5, x_r2 = 20, x_b = 12, y_b = 40, x_move = -1,
      y_move = -1, old_sc1 = sc1, old_sc2 = sc2;
  char sy;
  draw(sc1, sc2, x_r1, x_r2, x_b, y_b);
  while (sc1 != 21 && sc2 != 21) {

    // если коснулся борта
    if (x_b == 1 || x_b == 23) {
      x_move *= -1;
    }
    //если коснулся ракетки
    else if ((y_b == 10 && (x_b == x_r1 || x_b == x_r1 - 1)) ||
             (y_b == 70 && (x_b == x_r2 || x_b == x_r2 - 1))) {
      y_move *= -1;
    }
    //если забили гол влево
    else if (y_b == 9) {
      old_sc2 = sc2;
      sc2++;
    }
    //если забили гол вправо
    else if (y_b == 71) {
      old_sc1 = sc1;
      sc1++;
    }

    //обработка клавиш упавления
    int flag = 1;
    while (flag) {
      sy = getc(stdin);
      while (getchar() != '\n') {
      }
      if (sy == 'a' || sy == 'A') {
        flag = 0;
        x_r1 = (x_r1 - 1 != 1) ? (x_r1 - 1) : x_r1;
      } else if (sy == 'z' || sy == 'Z') {
        flag = 0;
        x_r1 = (x_r1 + 1 != 23) ? x_r1 + 1 : x_r1;
      } else if (sy == 'k' || sy == 'K') {
        flag = 0;
        x_r2 = (x_r2 - 1 != 1) ? x_r2 - 1 : x_r2;
      } else if (sy == 'm' || sy == 'M') {
        flag = 0;
        x_r2 = (x_r2 + 1 != 23) ? x_r2 + 1 : x_r2;
      } else if (sy == ' ') {
        flag = 0;
      } else {
        flag = 1;
        printf("Введите другую клавишу!\n");
      }
    }
    if (y_b != 9 && y_b != 71) {
      y_b += y_move;
      x_b += x_move;
    }
    //если кто-то забил гол
    if (old_sc1 != sc1 || old_sc2 != sc2) {
      old_sc1 = sc1;
      old_sc2 = sc2;
      x_b = 12;
      y_b = 40;
      x_move *= -1;
      y_move *= -1;
    }
    draw(sc1, sc2, x_r1, x_r2, x_b, y_b);
  }
  winner(sc2);
  return 0;
}

void draw(int sc1, int sc2, int x_r1, int x_r2, int x_b, int y_b) {
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 80; j++) {
      if (i == 0 || i == 24) {
        printf("-");
      } else if (j == 0 ||j == 40 && !(i == x_b && j == y_b))) {
        printf("|");
      } else if (((i == x_r1 || i == x_r1 - 1) && j == 9) ||
                 ((i == x_r2 || i == x_r2 - 1) && j == 71)) {
        printf("#");
      } else if (i == x_b && j == y_b) {
        printf("O");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  printf("                                      %d   %d                        "
         "              \n",
         sc1, sc2);
}

void winner(int sc2) {
  if (sc2 == 21) {
    printf("Congratilations to Player 2! You won!");
  } else {
    printf("Congratulations to Player 1! You won!");
  }
}
