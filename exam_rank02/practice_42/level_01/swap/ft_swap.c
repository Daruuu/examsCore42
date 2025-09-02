/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:55:47 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/13 22:08:49 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(void)
{
	int	a = 123;
	int	*aa = &a;

	int	b = 987;
	int	*bb = &b;
	printf("data before a: %d\n", *aa);
	printf("data before b: %d\n", *bb);

	printf("data after a: %d\n", *aa);
	printf("data after b: %d\n", *bb);

	return (0);
}
