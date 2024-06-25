/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:26:55 by dasalaza          #+#    #+#             */
/*   Updated: 2024/06/26 00:10:09 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ascii to integer
*/
int	ft_atoi(int *str)
{
	int	i;
	int	signal;
	int	result;

	i = 0;
	signal = 1;
	while (str[i] == ' ' && str[i] == '\t')
		i++;
	if (str[i] == '-')
		signal = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] + '0';
		i++;
	}
	return (signal * result);
}
