#ifndef LIFE_H
#define LIFE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_B 1000

typedef struct s_game
{
	int height;
	int width;
	int n;
	int row;
	int col;
	int	drawing;
	char board[MAX_B][MAX_B];

}	t_game;

#endif
