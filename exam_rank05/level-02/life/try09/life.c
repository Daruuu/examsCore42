#include "life.h"



int	count_lives(t_game* game, int row, int col)
{
	int counter = 0;
	for (int step_row = -1; step_row <= 1; step_row++)
	{
		for (int step_col = -1; step_col <= 1; step_col++)
		{
			if (step_row == 0 && step_col == 0)
				continue;

			int new_row = step_row + row;
			int new_col = step_col + col;
			
			if (new_row >= 0 && new_row < game->height &&
					new_col >= 0 && new_col < game->width)
			{
				if (game->board[new_row][new_col] == 'O')
					counter++;
			}
		}
	}
	return counter;
}

void play(t_game *game)
{
	char	new_board[MAX_T][MAX_T];

	for(int row = 0; row < game->height; row++ )
	{
		for(int col = 0; col < game->width; col++ )
		{
			int count_vecinos = count_lives(game, row, col);
			if (game->board[row][col] == 'O')
			{
				new_board[row][col] = (count_vecinos == 2 || count_vecinos == 3) ? 'O' : ' ';
			}
			else
			{
				new_board[row][col] = (count_vecinos == 3) ? 'O' : ' ';
			}
		}
	}
	for (int row = 0; row < game->height; row++)
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
	game.height = atoi(av[2]);
	game.n = atoi(av[3]);
	game.rows = 0;
	game.cols = 0;

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
			game.rows--;
		else if (cmd == 's')
			game.rows++;
		else if (cmd == 'a')
			game.cols--;
		else if (cmd == 'd')
			game.cols++;
		else if (cmd == 'x')
			game.drawing = !game.drawing;
		if (game.drawing && 
				game.rows >= 0 && game.rows < game.height &&
				game.cols >= 0 && game.cols < game.width && 
				(cmd == 'w' || cmd == 's' || cmd == 'a' || cmd == 'd' || cmd == 'x'))
		{
			game.board[game.rows][game.cols] = 'O';
		}
	}
	for (int i = 0 ; i < game.n; i++)
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
