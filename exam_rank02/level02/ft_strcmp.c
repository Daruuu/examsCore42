/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 11:31:00 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    ft_strcmp(char *s1, char *s2)
{
	int	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i ++;
	return (s1[i] - s2[i]);
}

#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 3)
		printf("%d\n", ft_strcmp(av[1], av[2]));
	return (0);
}
