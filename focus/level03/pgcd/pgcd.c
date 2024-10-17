#include <stdlib.h>
#include <stdio.h>

int gcd(int a, int b)
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

int main(int ac, char **av)
{
	int a, b;
	if (ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);
		if (a > 0 || b > 0)
			printf("%d\n", gcd(a, b));
	}
	else
		printf("\n");
	return (0);
}
