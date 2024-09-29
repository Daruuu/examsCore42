#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	do_op(char *n1, char sign, char *n2)
{
	if (sign == '+')
		printf("%d", atoi(n1) + atoi(n2));
	if (sign == '-')
		printf("%d", atoi(n1) - atoi(n2));
	if (sign == '*')
		printf("%d", atoi(n1) * atoi(n2));
	if (sign == '/')
		printf("%d", atoi(n1) / atoi(n2));
	if (sign == '%')
		printf("%d", atoi(n1) % atoi(n2));
	printf("\n");
}

int main(int ac, char **av)
{
	if (ac == 4)
	{
		do_op(av[1], av[2][0], av[3]);
	}
	return (0);
}

