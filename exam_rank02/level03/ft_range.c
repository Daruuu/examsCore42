/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end) {
	int i;
	int len;
	int *range;

	if (start < end)
		len = (end - start) + 1;
	else
		len = (start - end) + 1;

	range = malloc(sizeof(int) * len);
	if (!range)
		return (NULL);
	i = 0;
	while (i < len)
	{
		range[i] = start;
		if (start < end)
			start++;
		else
			start--;
		i++;
	}
	return (range);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int *result = ft_range(atoi(av[1]), atoi(av[2]));
		int i = 0;
		int len = (atoi(av[2]) - atoi(av[1])) + 1;
		if (atoi(av[1]) > atoi(av[2]))
			len = (atoi(av[1]) - atoi(av[2])) + 1;
		while (i < len)
		{
			printf("%d\n", result[i]);
			i ++;
		}
	}
	return (0);
}
