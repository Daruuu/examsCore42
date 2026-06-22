#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 1000

static char board[MAX][MAX];
static char next[MAX][MAX];

int count_neighbors(int row, int col, int w, int h)
{
	int dr = -1;
	int dc;
	int count = 0;

	while (dr <= 1)
	{
		dc = -1;
		while (dc <= 1)
		{
			if (dr != 0 || dc != 0)
			{
				int r = row + dr;
				int c = col + dc;
				if (r >= 0 && r < h && c >= 0 && c < w && board[r][c] == 'O')
					count++;
			}
			dc++;
		}
		dr++;
	}
	return count;
}

void play(int w, int h)
{
	int row = 0;
	int col;
	int n;

	while (row < h)
	{
		col = 0;
		while (col < w)
		{
			n = count_neighbors(row, col, w, h);
			if (board[row][col] == 'O')
				next[row][col] = (n == 2 || n == 3) ? 'O' : ' ';
			else
				next[row][col] = (n == 3) ? 'O' : ' ';
			col++;
		}
		row++;
	}
	row = 0;
	while (row < h)
	{
		col = 0;
		while (col < w)
		{
			board[row][col] = next[row][col];
			col++;
		}
		row++;
	}
}

int main(int argc, char **argv)
{
	int  w;
	int  h;
	int  iter;
	int  row;
	int  col;
	int  drawing;
	char cmd;

	if (argc != 4)
		return 1;

	w    = atoi(argv[1]);
	h    = atoi(argv[2]);
	iter = atoi(argv[3]);

	/* 1. Init tablero con espacios */
	row = 0;
	while (row < h)
	{
		col = 0;
		while (col < w)
			board[row][col++] = ' ';
		row++;
	}

	/* 2. Leer comandos del boligrafo */
	row = 0;
	col = 0;
	drawing = 0;
	while (read(0, &cmd, 1) == 1)
	{
		if      (cmd == 'w') row--;
		else if (cmd == 's') row++;
		else if (cmd == 'a') col--;
		else if (cmd == 'd') col++;
		else if (cmd == 'x') drawing = !drawing;

		if (drawing && row >= 0 && row < h && col >= 0 && col < w)
			board[row][col] = 'O';
	}

	/* 3. Simular N iteraciones */
	col = 0;
	while (col++ < iter)
		play(w, h);

	/* 4. Imprimir */
	row = 0;
	while (row < h)
	{
		col = 0;
		while (col < w)
			putchar(board[row][col++]);
		putchar('\n');
		row++;
	}
	return 0;
}
