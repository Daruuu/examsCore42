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

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i ++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i ++;
	}
	return  (result);
}

void	putnbr(int nbr)
{
	char digit;
	if (nbr > 9)
		putnbr(nbr / 10);
	digit = (nbr % 10) + '0';
	write(1, &digit, 1);
}

int is_prime(int num)
{
	int i = 2;
	if (num <= 1)
		return (0);
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i ++;
	}
	return (1);

}
int	main(int ac, char **av)
{
	int	nbr;
	int sum;
	if (ac == 2)
	{
		sum = 0;
		nbr = ft_atoi(av[1]);
		while (nbr > 0)
		{
			if (is_prime(nbr))
				sum = sum + nbr;
			nbr--;
		}
		putnbr(sum);
	}
	else
	{
		putnbr(0);
		write(1, "\n", 1);
	}
	return (0);
}

