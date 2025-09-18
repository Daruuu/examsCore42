/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int gcd(unsigned int a, unsigned int b)
{
	unsigned int	tmp;
	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return (a);
}

unsigned int lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	return (a / gcd(a, b)) * b;
}

#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	if (ac == 3)
		printf("%u\n", lcm(atoi(av[1]), atoi(av[2])));
	return (0);
}
