/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rostring(char *str)
{
	int i = 0;
	int start = 0;
	int end = 0;
	int first_word = 1;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	start = i;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	end = i - 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			if (!first_word)
				write(1, " ", 1);
			while (str[i] && str[i] != ' ' && str[i] != '\t')
			{
				write(1, &str[i], 1);
				i++;
			}
			first_word = 0;
		}
		else
			i++;
	}
	if (!first_word)
		write(1, " ", 1);
	while (start <= end)
	{
		write(1, &str[start], 1);
		start++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}
