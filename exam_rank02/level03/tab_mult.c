/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(int n)
{
	char digit;
	if (n > 9)
		putnbr(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

int ft_atoi(char *str)
{
	int i = 0;
	int result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i ++;
	}
	return (result);
}

int main(int ac, char **av)
{
	int n ;
	int i;
	int res;
	i = 1;
	if (ac == 2)
	{
		n = ft_atoi(av[1]);
		while (i <= 9)
		{
			putnbr(i);
			write(1, " x ", 3);
			putnbr(n);
			write(1, " = ", 3);
			res = i * ft_atoi(av[1]);
			putnbr(res);
			write(1, "\n", 1);
			i ++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
