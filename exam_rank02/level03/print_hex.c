/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int ft_atoi(char *str)
{
	unsigned int result;
	int i;
	i = 0;
	result = 0;
	while (str[i]>= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i ++;
	}
	return (result);
}

void	print_hex(unsigned int num)
{
	char	*str= "0123456789abcdef";
	char	buffer[9];
	int		i = 0;

	if (num == 0)
	{
		write(1, "0", 1);
		return;
	}
	while (num > 0)
	{
		buffer[i] = str[num % 16];
		num = num / 16;
		i ++;
	}
	while (i--)
		write(1, &buffer[i], 1);
}

int main(int ac, char **av)
{
	unsigned int	num;
	if (ac == 2)
	{
		num = ft_atoi(av[1]);
		print_hex(num);
	}
	write(1, "\n", 1);
	return (0);
}
