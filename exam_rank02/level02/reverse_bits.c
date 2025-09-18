/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 15:19:50 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	char	result = 0;
	unsigned int	i;
	i = 8;
	while (i --)
	{
		result = (result << 1) | (octet & 1);
		octet >>= 1;
	}
	return (result);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%d\n", reverse_bits(atoi(av[1])));
	return (0);
}
