#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 1000

typedef struct s_game
{
	int width, height, n;       // dimensiones del tablero e iteraciones del juego
	int row, col;               // posición del bolígrafo (fila, columna)
	int drawing;                // 0 = levantado, 1 = bajado
	char board[MAX_SIZE][MAX_SIZE]; // tablero: 'O' = viva, ' ' = muerta
} t_game;

// Cuenta cuántos vecinos vivos ('O') tiene la celda (row, col)
int count_alive(t_game* game, int row, int col)
{
	int count = 0;
	for (int step_r = -1; step_r <= 1; step_r++)
	{
		for (int step_c = -1; step_c <= 1; step_c++)
		{
			if (step_r == 0 && step_c == 0) // saltar la propia celda
				continue;
			int new_r = row + step_r;
			int new_c = col + step_c;
			if (new_r >= 0 && new_r < game->height && new_c >= 0 && new_c < game
				->width)
			{
				if (game->board[new_r][new_c] == 'O')
				{
					count++;
				}
			}
		}
	}
	return count;
}

// Avanza una generación del Game of Life (calcula en auxiliar, luego copia)
void play(t_game* game)
{
	static char new_board[MAX_SIZE][MAX_SIZE];
	for (int row = 0; row < game->height; row++)
	{
		for (int col = 0; col < game->width; col++)
		{
			int nb_alive = count_alive(game, row, col);
			if (game->board[row][col] == 'O')
			{
				// viva: sobrevive con 2 o 3 vecinos, si no muere
				new_board[row][col] = (nb_alive == 2 || nb_alive == 3)
										? 'O'
										: ' ';
			}
			else
			{
				// muerta: nace solo con exactamente 3 vecinos
				new_board[row][col] = (nb_alive == 3) ? 'O' : ' ';
			}
		}
	}
	// Copiar el nuevo estado al tablero principal
	for (int row = 0; row < game->height; row++)
	{
		for (int col = 0; col < game->width; col++)
		{
			game->board[row][col] = new_board[row][col];
		}
	}
}

// Lee args, dibuja con el bolígrafo, simula n iteraciones e imprime
int main(int argc, char** argv)
{
	if (argc != 4)
		return 1;

	t_game game;
	char cmd;
	game.width = atoi(argv[1]);
	game.height = atoi(argv[2]);
	game.n = atoi(argv[3]);
	game.row = 0;    // bolígrafo empieza arriba-izquierda
	game.col = 0;
	game.drawing = 0; // empieza levantado (no pinta)

	if (game.width > MAX_SIZE) game.width = MAX_SIZE;
	if (game.height > MAX_SIZE) game.height = MAX_SIZE;

	// Inicializar tablero vacío
	for (int row = 0; row < game.height; row++)
	{
		for (int col = 0; col < game.width; col++)
		{
			game.board[row][col] = ' ';
		}
	}

	// Leer comandos: w/a/s/d mueven, x alterna dibujar
	while (read(STDIN_FILENO, &cmd, 1) == 1)
	{
		if (cmd == 'w') game.row--;
		else if (cmd == 's') game.row++;
		else if (cmd == 'a') game.col--;
		else if (cmd == 'd') game.col++;
		else if (cmd == 'x') game.drawing = !game.drawing;

		// Pintar solo si está bajado, dentro del tablero y el cmd es válido
		if (game.drawing && game.row >= 0 && game.row < game.height && game.col
			>= 0 && game.col < game.width && (cmd == 'w' || cmd == 's' || cmd ==
				'a' || cmd == 'd' || cmd == 'x'))
			game.board[game.row][game.col] = 'O';
	}

	// Simular n generaciones del Game of Life
	for (int i = 0; i < game.n; i++)
	{
		play(&game);
	}

	// Imprimir tablero final
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
