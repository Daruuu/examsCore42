/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 15:09:05 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i = 8;
	char digit;

	while (i--)
	{
		digit = (octet >> i & 1) + '0' ;
		write(1, &digit, 1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		print_bits(atoi(av[1]));
	write(1, "\n", 1);
	return (0);
}
