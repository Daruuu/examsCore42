/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:34:16 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/29 20:33:12 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_max(int *tab, unsigned int len)
{
	unsigned int	i;
	unsigned int	result;

	if (!tab || len == 0)
		return (0);
	i = 0;

	result = tab[i];
	while (i < len)
	{
		if ((int)result < tab[i])
			result = tab[i];
		i++;
	}
	return (result);
}
