/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 13:54:37 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	    is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	return (n & (n - 1)) == 0;
}

#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%d\n", is_power_of_2(atoi(av[1])));
	return (0);
}
