#include "life.h"

int	count_lives(t_game* game, int row, int cols)
{
	int count= 0;

	for (int step_row = -1; step_row <= 1; step_row++)
	{
		for (int step_col = -1; step_col <= 1; step_col++)
		{
			if (step_row == 0 && step_col == 0)
				continue;
			int new_row = row + step_row;
			int new_col = cols + step_col; 
			if (new_row >= 0 && new_row < game->height && new_col <= 0 && new_col < game->width)
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
	char new_table[MAX_B][MAX_B];
	for (int row = 0; row < game->height; row++)
	{
		for (int col = 0; col < game->width; col++)
		{
			int vecinos = count_lives(game, row, col);
			if (game->board[row][col] == '0')
			{
				new_table[row][col] = (vecinos == 2 || vecinos == 3) ? '0' : ' ';
			}
			else
			{
				new_table[row][col] = (vecinos == 3) ? '0' : ' ' ;
			}
		}
	}

	for (int row = 0; row < game->height; row++)
	{
		for (int col = 0; col < game->width; col++)
		{
			game->board[row][col] = new_table[row][col];
		}
	}
}

//	./life width height iterations
int main(int ac, char **av)
{
	if (ac != 4)
		return 1;

	t_game game;

	game.width = atoi(av[1]);
	game.height = atoi(av[2]);
	game.n = atoi(av[3]);
	game.row = 0;
	game.drawing = 0;
	game.board;

	//	 FILL EMPTY MAP with spaces
	for (int row = 0; row < game.height; row++)
	{
		for (int col = 0; row < game.width; col++)
		{
			game.board[row][col] = ' ';
		}
	}

	//	LEER DEL INPUT 
	char cmd;
	while(read(STDIN_FILENO, &cmd, 1) == 1)
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

		if (game.drawing && 
			game.row >= 0 && game.row < game.height &&
			game.col >= 0 && game.col < game.width &&
			(cmd == 'w' || cmd == 's' || cmd == 'a' ||
			 cmd == 'd' || cmd == 'x')
			)
		{
			game.board[game.row][game.col] = '0';
		}
	}
	for (int i = 0; i < game.n; i++)
	{
		play(&game);
	}

	//	IMPRIMIR EN PANTALLA
	for (int i = 0; i < game.height; i++)
	{
		for (int j = 0; j < game.width ; j++)
		{
			putchar(game.board[i][j]);
		}
		putchar('\n');
	}
	return 0;
}

