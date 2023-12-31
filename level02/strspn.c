/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strspn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:16:21 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/28 19:44:33 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	ft_strchr(char *s, char c)
{
	int	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		s++;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_strchr((char *)accept[i], s[i]))
			break;
		i++;
	}
	return (i);
}
