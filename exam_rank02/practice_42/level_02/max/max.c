/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:13:12 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 12:06:59 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/
#include <stdio.h>

/*
int		max(int	*tab, unsigned int len)
{
	unsigned int	i;
	int	max;

	i = 0;
	max = tab[i];
	while (i < (len - 1))
	{
		if (max < tab[i + 1])
			max = tab[i + 1];
		i ++;
	}
	return (max);
}
*/

int		max(int	*tab, unsigned int len)
{
	unsigned int	i;
	int	max;

	i = 0;
	max = tab[0];
	while (i < (len))
	{
		if (max < tab[i])
			max = tab[i];
		i ++;
	}
	return (max);
}
int	main(void)
{
//	int	tab[10] = {423123, 543,  -2147483648, 5, 4455555, 0, 100};

	int	res = max(NULL, 7);
	printf("%u\n", res);
	return (0);
}
