/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:22:14 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/29 18:08:56 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_char_present(char *s1, char c, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_inter(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		if (is_char_present(s1, s1[i], i) == 0)
		{
			j = 0;
			while (s2[j] != '\0')
			{
				if (s2[j] == s1[i])
				{
					ft_putchar(s1[i]);
					break;
				}
				j++;
			}
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_inter(av[1], av[2]);
	}
	ft_putchar('\n');

	return (0);
}
