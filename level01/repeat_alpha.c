/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:55:47 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/24 11:55:06 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_repeat_alpha(char *str)
{
	int	i;
	int	repeat;

	i = 0;
	repeat = 1;
	while (str[i])
	{

		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >='A' && str[i] <= 'Z'))
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				repeat = str[i] - 'A' + 1;
			else
				repeat = str[i] - 'a' + 1;

			while (repeat--)
				ft_putchar(str[i]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
	ft_putchar('\n');
}

/*
int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		ft_repeat_alpha(av[1]);
	}
	write(1, "\n", 1);
}
*/
