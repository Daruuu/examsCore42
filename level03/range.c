/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:55:58 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/31 18:44:58 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	leng;
	int	*ptr;
	int	i;
	
	leng = (end - start) + 1;
	ptr = (int *) malloc(leng * sizeof(int));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < leng)
	{
		if (start < end)
		{
			ptr[i] = start;
			i++;
			start++;
		}
		else
		{
			ptr[i] = start;
			start--;
			i++;
		}
	}
	return(ptr);
}

int	main()
{
	int	start;
	int	end;
	int	i;

	start = 2;
	end = 7;

	int	*res = ft_range(start, end);
	i = 0;
	while (res[i] != '\0')
	{
		printf("%i\n", res[i]);
		i++;
	}
	return (0);
}
