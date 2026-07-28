#include "life.h"

int	count_neighbords(t_game *game, int row, int col)
{
	int	count_total = 0;

	for (int step_row = -1; step_row <= 1; step_row++)
	{
		for (int step_col = -1; step_col <= 1; step_col++)
		{
			if (step_row == 0 && step_col == 0)
				continue;

			int	new_row = step_row + row;
			int	new_col = step_col + col;

			if (new_row >= 0 && new_row < game->heigh &&
				new_col >= 0 && new_col < game->width)
			{
				if(game->board[new_row][new_col] == 'O')
					count_total++;
			}
		}
	}
	return count_total;
}

void	play(t_game *game)
{
	char	new_board[MAX_T][MAX_T];

	for(int row = 0; row < game->heigh; row++)
	{
		for (int col = 0; col < game->width; col++)
		{
			int vecinos = count_neighbords(game, row, col);
			if (game->board[row][col] == 'O')
			{
				new_board[row][col] = (vecinos == 2 || vecinos == 3) ? 'O' : ' ';
			}
			else
			{
				new_board[row][col] = (vecinos == 3) ? 'O' : ' ';
			}
		}
	}
	for (int row = 0; row < game->heigh; row++)
	{
		for (int col = 0; col < game->width; col++)
		{
			game->board[row][col] = new_board[row][col];
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return 1;
	t_game game;
	
	game.width = atoi(av[1]);
	game.heigh = atoi(av[2]);
	game.n = atoi(av[3]);
	game.row = 0;
	game.col = 0;
	game.drawing = 0;

	for (int row = 0; row < MAX_T; row++)
	{
		for (int col = 0; col < MAX_T; col++)
		{
			game.board[row][col] = ' ';
		}
	}

	char	cmd;

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
		if (game.drawing && 
				game.row >= 0 && game.row < game.heigh &&
				game.col >= 0 && game.col < game.width && 
				(cmd == 'w' || cmd == 's' || cmd == 'a' || cmd == 'd' || cmd == 'x'))
		{
			game.board[game.row][game.col] = 'O';
		}
	}
	for (int i = 0; i < game.n; i++)
	{
		play(&game);
	}

	for (int row = 0; row < game.heigh; row++)
	{
		for (int col = 0; col < game.width; col++)
		{
			putchar(game.board[row][col]);
		}
		putchar('\n');
	}

	return 0;
}
