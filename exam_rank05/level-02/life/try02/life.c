#include "life.h"

//	count_lives
int count_lives(t_game* game, int row, int cols)
{
	int	 count = 0;
	for (int step_row = -1; step_row <= 1; step_row++)
	{
		for (int step_col = -1; step_col <= 1; step_col++)
		{
			if (step_row == 0 && step_col == 0)
				continue;
			int new_row = step_row + row;
			int new_col = step_col + cols;

			if (new_row	>= 0 && new_row < game->height &&
					new_col >= 0 && new_col < game->witdh)
			{
				if (game->board[new_row][new_col] == '0')
					count++;
			}
		}
	}
	return count;
}

//play	



//	main
int	main(int ac, char **av)
{
	if (ac != 4)
	{
		return 1;
	}

	t_game game;
	game.witdh = atoi(av[1]);
	game.height = atoi(av[2]);
	game.n = atoi(av[3]);
	game.row = 0;
	game.col = 0;
	game.drawing = 0;

	//	 FILL MAP WITH SPACES
	
	for(int	row = 0; row < game.height; row++)
	{
		for (int col = 0; col < game.witdh; col++)
		{
			game.board[row][col] = '0';
		}
	}

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

		int caserow = game.row >= 0 && game.row < game.height;
		int casecol = game.col >= 0 && game.col < game.witdh;

		if (game.drawing && caserow && casecol && (cmd == 'w' || cmd == 's' || cmd == 'a' || cmd == 'd' || cmd == 'x'))
		{
			game.board[game.row][game.col] = '0';
		}
	}

	for(int i = 0; i < game.n; i++)
	{
		play(&game);
	}

	for (int row = 0; row < game.height; row++)
	{
		for (int col = 0; col < game.witdh; col++)
		{
			putchar(game.board[row][col]);
		}
		putchar('\n');
	}

	return 0;
}
