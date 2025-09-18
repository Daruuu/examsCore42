/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 14:06:01 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	last_word(char *str)
{
	int	i;
	int	len;
	int	start;
	int	end;

	i = 0;
	len = 0;
	while (str[len])
		len ++;
	len --;
	i = len;
	while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
		i --;
	end = i;
	while (i >= 0 && str[i] != ' ' && str[i] != '\t')
		i--;
	start = i + 1;
	while (start <= end)
	{
		write(1, &str[start], 1);
		start ++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		last_word(av[1]);
	write(1, "\n", 1);
	return (0);
}
