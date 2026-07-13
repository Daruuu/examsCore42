#include "life01.h"

#include <stdio.h>
#include <stdlib.h>

//	CUENTA LOS VECINOS VIVOS ALREDEDOR DE LA CELDA(row, col)
int count_alive(t_game* game, int row, int col)
{
	int count = 0;

	for (int step_row = -1; step_row <= 1; step_row++)
	{
		for (int step_col = -1; step_col <= 1; step_col++)
		{
			if (step_row == 0 && step_col == 0)
				continue;
			int new_row = row + step_row;
			int new_col = col + step_col;

			if (new_row >= 0 &&
				new_row < game->height &&
				new_col >= 0 &&
				new_col < game->width
			)
			{
				if (game->board[new_row][new_col] == '0')
					count++;
			}
		}
	}
	return count;
}

void play(t_game* game)
{
	char next_board[MAX_SIZE][MAX_SIZE];

	for (int row = 0; row < game->height; row++)
	{
		for ( int col = 0; col < game->width; col++)
		{
			int neighbors = count_alive(game, row, col);
			if (game->board[row][col] == '0')
			{
				// next_board[row][col] = (neighbors == 2 || neighbors == 3) ? '0' : ' ';
				if (neighbors == 2 || neighbors == 3)
					next_board[row][col] = '0';
				else
					next_board[row][col] = ' ';
			}
			else
			{
				next_board[row][col] = (neighbors == 3) ? '0' : ' ';
			}
		}
	}
	//	COPIAMOS EL TABLERO TEMPORAL AL TABLERO ORIGINAL
	for (int row = 0; row < game->height; row++)
	{
		for (int col = 0; col < game->width; col++)
		{
			game->board[row][col] = next_board[row][col];
		}
	}
}

//	./life width height iterations
int main(int ac, char** argv)
{
	if (ac != 4)
	{
		return 1;
	}
	//	======= INICIAMOS LA ESTRUCTURA ============
	t_game game;
	game.width = atoi(argv[1]);
	game.height = atoi(argv[2]);
	game.n = atoi(argv[3]);
	game.row = 0;
	game.col = 0;
	game.drawing = 0;

	// =======	RELLENAMOS EL TABLERO CON ESPACIOS =========
	for (int row = 0; row < game.height; row++)
	{
		for (int col = 0; col < game.width; col++)
		{
			game.board[row][col] = ' ';
		}
	}
	//	======= LEEMOS DE STDIN CON read ==================
	char cmd;

	while (read(STDIN_FILENO, &cmd, 1) == 1)
	{
		if (cmd == 'w')
			game.row--;
		else if (cmd == 's')
			game.row++;
		else if (cmd == 'a')
			game.col--;
		else if (cmd == 'd')
			game.col++;
		else if (cmd == 'x')
			game.drawing = !game.drawing;

		//SI EL DRAWING ES IGUAL A: 1 (es decir el boli esta activo)
		// PINTAMOS
		int caserow = game.row >= 0 && game.row < game.height;
		int casecol = game.col >= 0 && game.col < game.width;

		if (game.drawing && caserow && casecol &&
			(cmd == 'w' || cmd == 's' || cmd == 'a' || cmd == 'd' || cmd == 'x')
		)
		{
			game.board[game.row][game.col] = '0';
		}
	}

	//	SIMULAMOS LAS ITERACIONES
	for (int i = 0; i < game.n; i++)
	{
		play(&game);
	}

	// *****IMPRIMIMOS EL TABLERO FINAL************************
	for (int row = 0; row < game.height; row++)
	{
		for (int col = 0; col < game.width; col++)
		{
			putchar(game.board[row][col]);
		}
		putchar('\n');
	}
	return 0;
}
