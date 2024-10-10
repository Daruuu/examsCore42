/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>*/

#include <unistd.h>

int ft_atoi(char *str)
{
	int i;
	int result;
	int sign;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i ++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i ++;
	}
	return (result * sign);
}

int is_prime(int num)
{
	int i = 2;
	if (num < 2)
		return (0);
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i ++;
	}
	return (1);
}

void	put_nbr(int num)
{
	char	digit;
	if (num > 9)
		put_nbr(num / 10);
	digit = num % 10 + '0';
	write(1, &digit, 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int nbr = ft_atoi(av[1]);
		if (nbr > 0)
		{
			int sum = 0;
			while (nbr > 0)
			{
				if (is_prime(nbr))
					sum = sum + nbr;
				nbr --;
			}
			put_nbr(nbr);
		}
		else
			put_nbr(0);
	}
	else
		put_nbr(0);
	write(1, "\n", 1);
	return (0);
}