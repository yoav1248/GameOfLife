#include "gameOfLife.h"

void putPattern(char *input, int arr[SIZEX][SIZEY], int x, int y) {
  int i = x, j = y;  // array positions
  int k;             // loop iterator
  int num;           // number of cells to modify
  int alive;         // the value to fill
  while(*input != '!') {
    // parse an integer from the string and skip to next char
    num = 0;
    while('0'<=*input && *input<='9'){
      num *= 10;
      num += *input - '0';
      input++;
    }

    if(num == 0) // if there are no numbers,
      num = 1;   // there should be one occurence of dead / alive cell;

    // if reached a '$', skip corresponding num of lines
    if(*input == '$') {
      j = y;
      i+=num;
      input++;
      continue;
    }

    alive = (*input == 'o');

    for(k = 0; k < num; k++) {
      *getCell(arr, i, j) = alive;
      j++;
    }
    input++;
  }

}
