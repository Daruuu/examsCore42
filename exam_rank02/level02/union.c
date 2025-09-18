/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 15:38:18 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	union_func(char *s1, char *s2)
{
	char	ascii_table[256] = {0};
	int i = 0;
	while (s1[i])
	{
		if (!ascii_table[(unsigned char)s1[i]])
		{
			write(1, &s1[i], 1);
			ascii_table[(unsigned char)s1[i]] = 1;
		}
		i++;
	}
	int j = 0;
	while (s2[j])
	{
		if (!ascii_table[(unsigned char)s2[j]])
		{
			write(1, &s2[j], 1);
			ascii_table[(unsigned char)s2[j]] = 1;
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		union_func(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
