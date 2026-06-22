#include "life.h"


/**
 * Cuenta los vecinos vivos alrededor de la celda (row, col)
 * @param game - Puntero a la estructura t_game
 * @param row - Fila de la celda
 * @param col - Columna de la celda
 * @return El número de vecinos vivos
 */


int count_alive(t_game* game, int row, int col)
{
	int count = 0;
	for (int step_r = -1; step_r <= 1; step_r++) //step_r es el paso en la fila
	{
		for (int step_c = -1; step_c <= 1; step_c++)
		//step_c es el paso en la columna
		{
			if (step_r == 0 && step_c == 0)
				continue; // Si el paso es 0, 0, se salta el bucle
			int new_r = row + step_r; //new_r es la nueva fila
			int new_c = col + step_c; //new_c es la nueva columna
			if (new_r >= 0 && new_r < game->height && new_c >= 0 && new_c < game
				->width)
			// Si la nueva fila y columna son validas, se incrementa el contador
			{
				if (game->board[new_r][new_c] == 'O')
				// Si la celda es viva, se incrementa el contador
				{
					count++;
				}
			}
		}
	}
	return count;
}


/**
 * Ejecuta un turno del Juego de la Vida
 * @param game - Puntero a la estructura t_game
 */

void play(t_game* game)
{
	char next_board[MAX_SIZE][MAX_SIZE];

	for (int row = 0; row < game->height; row++)
	{
		for (int col = 0; col < game->width; col++)
		{
			int neighbors = count_alive(game, row, col);
			if (game->board[row][col] == 'O')
			{
				next_board[row][col] = (neighbors == 2 || neighbors == 3)
											? 'O'
											: ' ';
			}
			else
			{
				next_board[row][col] = (neighbors == 3) ? 'O' : ' ';
			}
		}
	}

	// Copiamos el nuevo tablero al original
	for (int row = 0; row < game->height; row++)
	{
		for (int col = 0; col < game->width; col++)
		{
			game->board[row][col] = next_board[row][col];
		}
	}
}


int main(int argc, char** argv)
{
	if (argc != 4)
		return 1;

	t_game game;

	game.width = atoi(argv[1]);
	game.height = atoi(argv[2]);
	game.n = atoi(argv[3]);
	game.row = 0; // Fila inicial
	game.col = 0; // Columna inicial
	game.drawing = 0;
	// El enunciado dice que empieza sin dibujar hasta pulsar 'x'

	// Limpiar el tablero inicializándolo con espacios
	for (int row = 0; row < game.height; row++)
	{
		for (int col = 0; col < game.width; col++)
		{
			game.board[row][col] = ' ';
		}
	}

	// Leer comandos desde la entrada estándar
	char cmd;
	while (read(STDIN_FILENO, &cmd, 1) == 1)
	{
		// MODIFICACIÓN 3: Quitamos los límites (game.row > 0, etc).
		// Dejamos que el bolígrafo viaje libremente fuera del papel si el test lo requiere.
		if (cmd == 'w') game.row--;
		else if (cmd == 's') game.row++;
		else if (cmd == 'a') game.col--;
		else if (cmd == 'd') game.col++;
		else if (cmd == 'x') game.drawing = !game.drawing;

		// Si el bolígrafo está activado y la posición coincide con el papel, pintamos.
		// Aquí es donde hacemos la verdadera comprobación de seguridad.
		if (game.drawing && game.row >= 0 && game.row < game.height && game.col
			>= 0 && game.col < game.width &&
			(cmd == 'w' || cmd == 's' || cmd == 'a' || cmd == 'd' || cmd ==
				'x'))
		{
			game.board[game.row][game.col] = 'O';
		}
	}

	// Simular las iteraciones
	for (int i = 0; i < game.n; i++)
	{
		play(&game);
	}

	// Imprimir el tablero final
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
