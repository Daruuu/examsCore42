/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/14 17:46:33 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int n1;
	int n2;
	int sign;
	if (ac == 4)
	{
		n1 = atoi(av[1]);
		n2 = atoi(av[3]);
		sign = av[2][0];
		if (sign == '+')
			printf("%d\n", n1 + n2);
		if (sign == '-')
			printf("%d\n", n1 - n2);
		if (sign == '*')
			printf("%d\n", n1 * n2);
		if (sign == '/')
			printf("%d\n", n1 / n2);
		if (sign == '%')
			printf("%d\n", n1 % n2);
	}
	return (0);
}
