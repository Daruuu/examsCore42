#ifndef LIFE_H
#define LIFE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SI 1000

typedef struct s_game
{
	int height;
	int width;
	int	row;
	int	col;
	int	n;
	int	drawing;
	char	board[MAX_SI][MAX_SI];

}	t_game;

#endif
