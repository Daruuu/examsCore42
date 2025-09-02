/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:01:49 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/13 21:53:48 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i ++;
		str++;
	}
	return (i);
}

int	main(void)
{
	char	*a;

	a = "my name is";
	printf ("leng str: %d\n", ft_strlen(a));
	return (0);
}
