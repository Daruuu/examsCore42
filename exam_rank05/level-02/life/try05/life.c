#include  "life.h"

int count(t_game *game, int row, int col)
{
	int total_count = 0;
	for (int prev_row = -1; prev_row <= 1; ++prev_row)
	{
		for (int prev_col = -1; prev_col <= 1; ++prev_col)
		{
			if (prev_row == 0 && prev_col == 0)
				continue;
			int new_row = prev_row + row;
			int new_col = prev_col + col;
			if (new_row >= 0 && new_row < game->height &&
				new_col >= 0 && new_col < game->width)
			{
				if (game->board[new_row][new_col] == 'O')
					total_count++;
			}
		}
	}
	return total_count;
}

void play(t_game *game)
{
	char new_table[MAX_T][MAX_T];

	for (int row = 0; row < game->height; row++)
	{
		for (int col = 0; col < game->width; col++)
		{
			int vecinos = count(game, row, col);
			if (game->board[row][col] == 'O')
			{
				new_table[row][col] = (vecinos == 2 || vecinos == 3) ? 'O' : ' ';
			}
			else
				new_table[row][col] = (vecinos == 3) ? 'O' : ' ';
		}
	}
	for (int row = 0; row < game->height; ++row)
	{
		for (int col = 0; col < game->width; ++col)
		{
			game->board[row][col] = new_table[row][col];
		}
	}
}

int main(int ac, char **av)
{
	if (ac != 4)
		return 1;
	//	RELLENAR STRUCUTRA
	t_game game;
	game.width = atoi(av[1]);
	game.height = atoi(av[2]);
	game.n = atoi(av[3]);
	game.row = 0;
	game.col = 0;
	game.drawing = 0;

	//	RELLENAR TABLERO CON ESPACIOS
	for (int row = 0; row < game.height; ++row)
	{
		for (int col = 0; col < game.width; ++col)
		{
			game.board[row][col] = ' ';
		}
	}
	//	LEER COMANDO DE ENTRADA

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
		if (game.drawing &&
			game.row >= 0 && game.row < game.height &&
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

	for (int row = 0; row < game.height; ++row)
	{
		for (int col = 0; col < game.width; ++col)
		{
			putchar(game.board[row][col]);
		}
		putchar('\n');
	}

	return 0;
}