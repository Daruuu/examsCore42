/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                      :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int i;
	int result;
	int value;
	int sign;

	if (str_base < 2 || str_base > 16)
		return (0);
	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i ++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i ++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			value = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			value = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			value = str[i] - 'A' + 10;
		else
			return (result * sign);
		if (value >= str_base)
			return (result * sign);
		result = result * str_base + value;
		i ++;
	}
	return (result);
}

#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 3)
		printf("%d\n", ft_atoi_base(av[1], atoi(av[2])));
	return (0);
}
