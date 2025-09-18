/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 13:13:43 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *ft_strrev(char *str)
{
	int	i;
	int	len;
	char tmp;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len ++;
	while (i < (len / 2))
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i ++;
	}
	return (str);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%s\n", ft_strrev(av[1]));
	return (0);
}
