/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hidenp(char *str, char *str2)
{
	int i;
	int j;
	i = 0;
	j = 0;
	while (str2[i] != '\0')
	{
		if (str2[i] == str[j])
		{
			j ++;
		}
		i ++;
	}
	if (str[j] == '\0')
		write(1, "1\n", 2);
	else
		write(1, "0\n", 2);
}

int main(int ac, char **av)
{
	if (ac == 3)
		hidenp(av[1], av[2]);
	else
		write(1, "\n", 1);
	return (0);
}
