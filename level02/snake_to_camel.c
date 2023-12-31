/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:52:47 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/30 12:45:35 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
/*
void	snake_to_camel(char *s)
{
	int	i;
	int	leng;
	int	count;
	char	*new;

	leng = 0;
	while (s[leng] != '\0')
		leng++;
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '_')
			count++;
		i++;
	}
	leng = leng - count;
	new = malloc (leng + 1 * sizeof(char *));
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '_')
	}
}
*/

int	main(int ac, char **av)
{
	int	i = 0;
	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] == '_')
			{
				i++;
				av[1][i] -= 32; 
			}
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
