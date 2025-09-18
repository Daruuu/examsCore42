/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len = 0;
	int		temp = n;
	int		sign = 1;
	int		i;

	if (n < 0)
	{
		sign = -1;
		len++;
		temp = -temp;
	}
	if (n == 0)
		len = 1;
	else
	{
		while (temp > 0)
		{
			len++;
			temp /= 10;
		}
	}
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = len - 1;
	if (n == 0)
		result[0] = '0';
	else
	{
		temp = n;
		if (sign == -1)
			temp = -temp;
		while (temp > 0)
		{
			result[i--] = (temp % 10) + '0';
			temp /= 10;
		}
		if (sign == -1)
			result[0] = '-';
	}
	result[len] = '\0';
	return (result);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%s\n", ft_itoa(atoi(av[1])));
	return (0);
}
