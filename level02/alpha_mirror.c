/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:12:10 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/25 11:41:31 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;

	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				av[1][i] = 'Z' - av[1][i] + 'A';
			else if (av[1][i] >= 'a' && av[1][i] <= 'z')
				av[1][i] = 'z' - av[1][i] + 'a';

			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);

	return (0);
}
/*
input = abcdf

else if (av[1][i] >= 'a' && av[1][i] <= 'z')
	av[1][i] = 'z' - av[1][i] + 'a';

122 - 97 + 97
122 - 98 + 97
*/
