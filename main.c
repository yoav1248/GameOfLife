#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "gameOfLife.h"

char *putArrayString(int arr[SIZEX][SIZEY], char *str) {
  int i, j;
  char c;
  char *tmp = str;
  for (i = 0; i < SIZEX; i++) {
    for (j = 0; j < SIZEY; j++) {
      c = *getCell(arr, i, j) ? ALIVE_CHAR : DEAD_CHAR;
      *(tmp++) = c;
    }
    *(tmp++) = '\n';
  }
  *tmp = '\0';
  return str;
}

void resetArr(int arr[SIZEX][SIZEY]){
  int i, j;
  for (i = 0; i < SIZEX; i++) {
    for (j = 0; j < SIZEY; j++) {
      arr[i][j] = 0;
    }
  }
}

int main(int argc, char *argv[]){
  int gameArray[SIZEX][SIZEY];
  resetArr(gameArray);

  // GLIDER
  /*gameArray[0][1] = 1;
  gameArray[1][2] = 1;
  gameArray[2][0] = 1;
  gameArray[2][1] = 1;
  gameArray[2][2] = 1;*/

  // R-PENT
  /*gameArray[0][1] = 1;
  gameArray[0][2] = 1;
  gameArray[1][0] = 1;
  gameArray[1][1] = 1;
  gameArray[2][1] = 1;*/


  putPattern(PATTERN, gameArray, 10, 10);

  int i = 1;
  char str[SIZEX*(SIZEY+1)+1];
  while(1) {
    putArrayString(gameArray, str);
    clear();
    printf("%s", str);

    printf("Generation %d\n", i);
    usleep(UPDATE_TIME*1000000);
    updateGame(gameArray);
    i++;
  }
  return 0;
}
