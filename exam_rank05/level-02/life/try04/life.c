#include "life.h"

int count_lives(t_game* game, int row, int col)
{
	int	 countvecinos = 0;
	
	for (int step_row = 0; step_row < game->height; step_row++)
	{
		for (int step_col = 0; step_col < game->width; step_col++)
		{
			if (step_row == 0 || step_col == 0)
				continue;
			int new_row = step_row + row ;
			int	new_col = step_col + col;

			if (new_row >= 0 && new_row < game->height && 
				new_col >= 0 && new_col < game->width)
			{
				if (game->board[new_row][new_col] == '0')
					countvecinos++;
			}
		}
	}
	return countvecinos;
}

void play(t_game *game)
{
	char newtable[MAX_SI][MAX_SI];	
	for (int row = 0; row < game->height; row++)
	{
		for (int col = 0; col < game->width; col++)
		{
			int vecinos = count_lives(game, row, col);
			if (game->board[row][col] == '0')
			{
				game->board[row][col] = (vecinos == 2 || vecinos == 3) ? '0' : ' ';
			}
			else
				game->board[row][col] = (vecinos == 3) ? '0' : ' ';
		}
	}

	for (int row = 0; row < game->height; row++)
	{
		for (int col = 0; col < game->width; col++)
		{
			game->board[row][col] = newtable[row][col];
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return 1;
	t_game game;

	game.width = atoi(av[1]);
	game.height = atoi(av[2]);
	game.n = atoi(av[3]);
	game.row = 0;
	game.col = 0;
	game.drawing = 0;
	game.board[MAX_SI][MAX_SI];

	for (int row = 0; row < game.height; row++)
	{
		for (int col = 0; col < game.width; col++)
		{
			game.board[row][col] = '0';
		}
	}

	for (int i = 0; i < game.n; i++)
	{
		play(&game);
	}

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
