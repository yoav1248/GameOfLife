#define SIZEX 50
#define SIZEY 100
#define SCALE 20

#define UPDATE_TIME 0.1 // in seconds

#define ALIVE_CHAR 'x'
#define DEAD_CHAR '.'

#ifdef _WIN32
#define clear() system("cls")
#else
#define clear() system("clear")
#endif

// GLIDER GUN
#define PATTERN "24bo$22bobo$12b2o6b2o12b2o$11bo3bo4b2o12b2o$\
2o8bo5bo3b2o$2o8bo3bob2o4bobo$\
10bo5bo7bo$11bo3bo$12b2o!"

 // heavweight spaceship
/*#define PATTERN "3b2o2b$bo4bo$o6b$o5bo$6o!"*/

//#define PATTERN "bo7b$obo6b$bo7b8$8bo$6bobo$5b2obo2$4b3o!"

void updateGame(int gameArray[SIZEX][SIZEY]);
int *getCell(int array[SIZEX][SIZEY], int x, int y);

int nextState(int state, int neighborCount);
int countAliveNeighbors(int array[SIZEX][SIZEY], int i, int j);
int mod(int a, int b);

void putPattern(char *input, int arr[SIZEX][SIZEY], int x, int y);
