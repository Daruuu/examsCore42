/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	str_capitalizer(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i ++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if ((i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t') && \
			(str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] - 32;
		write(1, &str[i], 1);
		i ++;
	}
}

int main(int ac, char **av)
{
	if (ac == 1)
		write(1, "\n", 1);
	else
	{
		int i = 1;
		while (i < ac)
		{
			str_capitalizer(av[i]);
			write(1, "\n", 1);
			i ++;
		}
	}
	return (0);
}
