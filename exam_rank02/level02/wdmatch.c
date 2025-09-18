/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	wdmatch(char *str, char *to_find)
{
	int i = 0;
	int j = 0;
	while (to_find[i])
	{
		if (str[j] == to_find[i])
		{
			j++;
		}
		if (str[j] == '\0')
		{
			j = 0;
			while (str[j] != '\0')
			{
				write(1, &str[j], 1);
				j ++;
			}
			return ;
		}
		i ++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		wdmatch(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
