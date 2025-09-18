/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rev_wstr(char *str)
{
	int i = 0;
	int start;
	int end;
	int len = 0;

	while (str[len])
		len++;
	len--;
	while (len >= 0)
	{
		while (len >= 0 && (str[len] == ' ' || str[len] == '\t'))
			len--;
		end = len;
		while (len >= 0 && str[len] != ' ' && str[len] != '\t')
			len--;
		start = len + 1;
		while (start <= end)
		{
			write(1, &str[start], 1);
			start++;
		}
		if (len >= 0)
			write(1, " ", 1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
