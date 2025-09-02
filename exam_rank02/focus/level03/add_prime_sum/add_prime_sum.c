#include <unistd.h>

int ft_atoi(char *str)
{
	int result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return (result);
}

void	put_nbr(int n)
{
	char digit;
	if (n > 9)
		put_nbr(n / 10);
	digit = n % 10 + '0';
	write(1, &digit, 1);
}

int	is_prime(int num)
{
	int i = 2;
	// si es negativo ---> return 0
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
	if (ac != 2)
	{
		write(1, "0\n", 2);
		return (0);
	}
	int num;
	num = ft_atoi(av[1]);
	if (num <= 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	int sum = 0;
	int i = 2;
	while (i <= num)
	{
		if (is_prime(i))
			sum = sum + i;
		i ++;
	}
	put_nbr(sum);
	write(1, "\n", 1);
	return (0);
}






