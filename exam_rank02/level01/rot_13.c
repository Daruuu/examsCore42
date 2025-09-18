/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:14:54 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/13 18:24:59 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rot_13(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = (str[i] - 'a' + 13) % 26 + 'a';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = (str[i] - 'A' + 13) % 26 + 'A';
		write(1, &str[i], 1);
		i ++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rot_13(av[1]);
	write(1, "\n", 1);
	return (0);
}
