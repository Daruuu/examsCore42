#ifndef LIFE_H
#define LIFE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 1000

typedef struct s_game
{
	int height;
	int witdh;
	int row;
	int col;
	int n;
	int drawing;
	char board[MAX_SIZE][MAX_SIZE];
}	t_game;


#endif
