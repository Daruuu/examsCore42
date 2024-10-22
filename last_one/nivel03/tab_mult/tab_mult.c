/*
Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult | cat -e
$
$>*/
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i = 0;
	int	sign = 1;
	int	result = 0;
	while (str[i] == ' ' || (str[i] >= 0 && str[i] <= 9))
		i ++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i ++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i ++;
	}
	return (sign * result);
}

void	putnbr(int num)
{
	char digit;
	if (num > 9)
		putnbr(num / 10);
	digit = (num % 10) + '0';
	write(1, &digit, 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 1;
		int num = ft_atoi(av[1]);
		while (i <= 9)
		{
			putnbr(i);
			write(1, " x ", 3);
			putnbr(num);
			write(1, " = ", 3);
			putnbr(num * i);
			write(1, "\n", 1);
			i ++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
