/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:50:46 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/31 13:05:53 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(int c, char *str, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;

	if (ac == 3)
	{
		while (av[1][i] != '\0')
			i++;
		while (av[2][j] != '\0')
		{
			av[1][i] = av[2][j];
			i++;
			j++;
		}
		i--;
		while (k <= i)
		{
			if (check(av[1][k], av[1], k) == 1)
				write(1, &av[1][k], 1);
			k++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
/*
./union "rien" "cette phrase ne cache rien" | cat -e
	rienct phas$
*/
