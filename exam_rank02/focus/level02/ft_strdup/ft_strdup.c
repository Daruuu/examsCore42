/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 12:30:51 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int i;
	int len  = 0;
	char	*result;

	while (src[len] != '\0')
		len ++;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (src[i] != '\0')
	{
		result[i] = src[i];
		i ++;
	}
	result[i] = '\0';
	return result;
}
