#ifndef LIFE01_H
#define LIFE01_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct s_game
{
	int width;
	int height;
	int n;
	int row;
	int col;
	int drawing;
	char board[MAX_SIZE][MAX_SIZE];
}	t_game;

#endif

