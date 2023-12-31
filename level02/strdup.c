/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:06:18 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/28 17:16:52 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>


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
