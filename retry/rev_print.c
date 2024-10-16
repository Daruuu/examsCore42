/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:04:14 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/14 16:08:18 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	revvvv(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i ++;
	i --;
	while (i >= 0 && str[i])
	{
		write(1, &str[i], 1);
		i --;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		revvvv(av[1]);
	write(1, "\n", 1);
	return (0);
}