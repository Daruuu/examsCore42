#ifndef LIFE_H
#define LIFE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 1000

typedef struct s_game
{
	int width, height, n;
	int row, col; // Posición del bolígrafo (fila, columna)
	int drawing; // Estado del bolígrafo (0 = levantado, 1 = bajado)
	char board[MAX_SIZE][MAX_SIZE];
} t_game;

int count_alive(t_game* game, int row, int col);
void play(t_game* game);

#endif
