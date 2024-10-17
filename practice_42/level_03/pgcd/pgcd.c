/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$
*/
#include <stdlib.h>
#include <stdio.h>

int	find_pgcd(int a, int b)
{
	int	tmp;

	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return (a);
}

int	main(int ac, char **av)
{
	int	a, b, pgcd;

	if (ac != 3)
	{
		printf("\n");
		return (0);
	}
	a = atoi(av[1]);
	b = atoi(av[2]);
	pgcd = find_pgcd(a, b);
	printf("%d\n", pgcd);
	return (0);
}
