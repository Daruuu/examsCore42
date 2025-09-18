/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	putnbr(int n)
{
	char digit;
	if (n > 9)
		putnbr(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

int	ft_atoi(char *str)
{
	int result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result);
}

int	is_prime(int n)
{
	int i = 2;
	if (n <= 1)
		return (0);
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	fprime(int n)
{
	int i = 2;
	int first = 1;
	
	if (n == 1)
	{
		write(1, "1", 1);
		return;
	}
	while (i <= n)
	{
		if (n % i == 0 && is_prime(i))
		{
			if (!first)
				write(1, "*", 1);
			putnbr(i);
			first = 0;
			n = n / i;
		}
		else
			i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		fprime(ft_atoi(av[1]));
	write(1, "\n", 1);
	return (0);
}
