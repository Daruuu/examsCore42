/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 13:32:48 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;
	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				break ;
			j ++;
		}
		if (accept[j] == '\0')
			return (i);
		i ++;
	}
	return (i);
}

int	main(int ac, char **av)
{
	if (ac == 3)
		printf("%zu\n", ft_strspn(av[1], av[2]));
	return (0);
}
