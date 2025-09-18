/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:14:54 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/13 18:24:59 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	search(char *str, char search, char replace)
{
	int	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == search)
			str[i] = replace;
		write (1, &str[i], 1);
		i ++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 4 && !av[2][1] && !av[3][1])
	{
		search(av[1], av[2][0], av[3][0]);
	}
	write(1, "\n", 1);
	return (0);
}
