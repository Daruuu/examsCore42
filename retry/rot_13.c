/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:10:09 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/14 16:22:41 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rot_1333(char *str)
{
	int	i;

	i = 0;
	while (i >= 0 && str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = (str[i] - 'a' + 13) % 26 + 'a';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = (str[i] - 'a' + 13) % 26 + 'a';
		write(1, &str[i], 1);
		i ++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rot_1333(av[1]);
	write(1, "\n", 1);
	return (0);
}
