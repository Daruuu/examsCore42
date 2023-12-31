/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:45:24 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/23 14:00:08 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
void	ft_putstr(char *str)
{
	int	i;
	i = 0;

	while(str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
*/

void	ft_putstr(char *str)
{
	while(*str)
		write(1, &(*str++), 1);
	
	write(1, "\n", 1);
}
