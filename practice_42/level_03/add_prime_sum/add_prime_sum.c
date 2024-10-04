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
$>
*/
#include <unistd.h>
#include <stdio.h>
// ft_atoi

//	"      -123"
int	ft_atoi(char *str)
{
	int		sign;
	int		i;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i ++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i ++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i ++;
	}
	return (sign * result);
}

// is_prime
int	is_prime(int num)
{
	int	i;

	if (num < 2)
		return (0);
	i = 2;
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i ++;
	}
	return (1);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	nbr;
	int	sum;

	if (ac == 2)
	{
		nbr = ft_atoi(av[1]);
		sum = 0;
		while (nbr > 0)
		{
			if (is_prime(nbr))
				sum = sum + nbr;
			nbr --;
		}
		ft_putnbr(sum);
	}
	if (ac != 2)
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}
