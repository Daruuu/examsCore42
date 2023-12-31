/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:06:38 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/25 12:22:00 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main (int ac, char **av)
{
	if (ac == 4)
	{
		if (av[2][0] == '+')
			printf("%d", (atoi(av[1]) + atoi(av[3])));
		if (av[2][0] == '-')
			printf("%d", (atoi(av[1]) - atoi(av[3])));
		if (av[2][0] == '*')
			printf("%d", (atoi(av[1]) * atoi(av[3])));
		if (av[2][0] == '/')
			printf("%d", (atoi(av[1]) / atoi(av[3])));
		if (av[2][0] == '%')
			printf("%d", (atoi(av[1]) % atoi(av[3])));
	}
	printf("\n");
	return (0);
}
