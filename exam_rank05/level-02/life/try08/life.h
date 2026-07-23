#ifndef LIFE_H
#define LIFE_H

#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>

#define MAX_T	1000

typedef struct s_game
{
	int width;
	int height;
	int n;
	int rows;
	int cols;
	int	drawing;
	char	board[MAX_T][MAX_T];
}	t_game;

#endif
