/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:48:41 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/30 11:42:08 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octect)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = (octect >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

int	main()
{
	unsigned char	value;

	value = 5;	//00000101 num en binario
	printf("input value: %u:\n", value);
	print_bits(value);
	printf("\n");
}
