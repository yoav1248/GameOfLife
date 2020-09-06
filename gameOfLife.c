#include "gameOfLife.h"

void updateGame(int gameArray[SIZEX][SIZEY]){
  int i, j;
  int neighborCount;
  int tempArray[SIZEX][SIZEY]; // will hold the wanted values

  for (i = 0; i < SIZEX; i++) {
    for (j = 0; j < SIZEY; j++) {
      neighborCount = countAliveNeighbors(gameArray, i, j);
      tempArray[i][j] = nextState(gameArray[i][j], neighborCount);
    }
  }

  // put values in gameArray
  for (i = 0; i < SIZEX; i++) {
    for (j = 0; j < SIZEY; j++) {
      gameArray[i][j] = tempArray[i][j];
    }
  }
}



int nextState(int state, int neighborCount) {
  if (neighborCount == 3) {
    return 1;
  } else if (neighborCount < 2 || neighborCount > 3) {
    return 0;
  } else {
    return state;
  }
}

int countAliveNeighbors(int array[SIZEX][SIZEY], int x, int y) {
  int i, j;
  int count = 0;
  for (i = -1; i <= 1; i++) {
    for (j = -1; j <= 1; j++) {
      if (!(i == 0 && j == 0) && *getCell(array, x + i, y + j) != 0) {
        count++;
      }
    }
  }
  return count;
}

int *getCell(int array[SIZEX][SIZEY], int x, int y) {
  return array[mod(x, SIZEX)] + mod(y, SIZEY);
}

int mod(int a, int b) {
  int r = a % b;
  return r < 0 ? r + b : r;
}
