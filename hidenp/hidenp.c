/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:41:51 by dasalaza          #+#    #+#             */
/*   Updated: 2024/06/06 18:20:08 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int	len_av1;
	int	i;
	int	j;
	int	count;

	count = 0;
	if (ac == 3)
	{
		i = 0;
		len_av1 = ft_strlen(av[1]);
		while (av[1][i] && i < len_av1)
		{
			j = 0;
			while (av[2][j] != '\0')
			{
				if (av[2][j] == av[1][i])
					count++;
				j++;
			}
			i++;
		}
		if (count == len_av1)
			write(1, "1\n", 2);
		else
			write(1, "0\n", 2);
	}
	return (0);
}
