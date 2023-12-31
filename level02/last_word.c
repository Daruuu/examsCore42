/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:11:12 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/29 19:32:05 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int ac, char **av)
{
	int	leng;

	leng = 0;
	if (ac == 2)
	{
		while (av[1][leng] != '\0')
			leng++;

		while (leng > 0 && is_space(av[1][leng - 1]))
			leng--;

		while (leng > 0 && !is_space(av[1][leng - 1]))
			leng--;

		while (leng < av[1][leng] + leng && !is_space(av[1][leng]))
		{
			write(1, &av[1][leng], 1);
			leng++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
