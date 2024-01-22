#include <stdio.h>

#define LEN 8

typedef struct move {
  int x;
  int y;
} move;

const move moves[] = {
  { .x = 1, .y = -2 },
  { .x = 2, .y = -1 },
  { .x = 2, .y = 1 },
  { .x = 1, .y = 2 },
  { .x = -1, .y = 2 },
  { .x = -2, .y = 1 },
  { .x = -2, .y = -1 },
  { .x = -1, .y = -2 },
};

int grid[LEN][LEN];

void resetGrid(void);
int navigate(int, int, int);
void printKey(void);
int isInBounds(int);
int isValidMove(int, int);

int main(void) {
  resetGrid();
  grid[0][0] = 0;
  if (navigate(0, 0, 1))
    printKey();
  return 0;
}

int navigate(int x, int y, int value) {
  int i, x1, y1;

  if (value == LEN * LEN)
    return 1;

  for (i = 0; i < LEN; ++i) {
    x1 = x + moves[i].x;
    y1 = y + moves[i].y;

    if (isValidMove(x1, y1)) {
      grid[x1][y1] = value;

      if (navigate(x1, y1, value + 1))
        return 1;
      else
        grid[x1][y1] = -1;
    }
  }

  return 0;
}

void resetGrid(void) {
  int i, j;
  for (i = 0; i < LEN; ++i)
    for (j = 0; j < LEN; ++j)
      grid[i][j] = -1;
}

void printKey(void) {
  int i, j;
  for (i = 0; i < LEN; ++i) {
    for (j = 0; j < LEN; ++j) {
      printf("%c%c", grid[i][j] / 10 + 48, grid[i][j] % 10 + 48);
    }
  }
  putchar(0xa);
}

int isInBounds(int n) {
  return n >= 0 && n < LEN;
}

int isValidMove(int x, int y) {
  return isInBounds(x) && isInBounds(y) && grid[x][y] == -1;
}

