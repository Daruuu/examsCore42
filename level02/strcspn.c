/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcspn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 13:51:31 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/25 14:08:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

// busca en *s el 1er caracter que coincide con cualquier caracter del string
// *reject y devuelve la longitud del *s que no contiene ninguno de los
// caracteres de *reject
// s: Puntero a la cadena de la cual se calculará la longitud del segmento inicial.
// reject: Puntero a la cadena que contiene los caracteres que se deben evitar en el segmento.

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i = 0;
	int	j;

	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if (s[i] == reject[j])
				return(i);
			j++;
		}
		i++;
	}
	return (i);
}
