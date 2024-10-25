//
// Created by daruuu on 10/25/24.
//
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	fprime(int num)
{
	int	divisor = 2;
	if (num == 1)
	{
		printf("1\n");
		return;
	}
	while (num > 1)
	{
		if (num % divisor == 0)
		{
			printf("%d", divisor);
			num = num / divisor;
			if (num > 1)
				printf("*");
		}
		else
			divisor++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int n = atoi(av[1]);
		if (n > 0)
			fprime(n);
	}
	printf("\n");
	return 0;
}