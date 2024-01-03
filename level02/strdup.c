/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:06:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/01/03 20:21:45 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup_exam(char *src)
{
	int		i;
	int		length;
	char	*strcpy;

	i = 0;
	length = 0;
	while (src[length] != '\0')
		length++;
	strcpy = malloc((length + 1) * sizeof(char *));
	if (strcpy != NULL)
	{
		while (src[i])
		{
			strcpy[i] = src[i];
			i++;
		}
		strcpy[i] = '\0';
	}
	return (strcpy);
}
/*
char	*ft_strdup(char *src)
{
	int		i;
	int		length;
	char	*strcpy;

	i = 0;
	length = 0;
	while (src[length] != '\0')
		length++;
	strcpy = malloc(sizeof(char *) * (length + 1));
	if (strcpy != NULL)
	{
		while (src[i])
		{
			strcpy[i] = src[i];
			i++;
		}
		strcpy[i] = '\0';
	}
	return (strcpy);
}
*/
