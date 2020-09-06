output: main.c gameOfLife.c inputHandler.c gameOfLife.h
	gcc -o output main.c gameOfLife.c inputHandler.c -Wall -Werror
