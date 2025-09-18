/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	expand_str(char *str)
{
	int i;
	i = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] != ' ' && str[i] != '\t'))
		{
			write(1, &str[i], 1);
			i ++;
		}
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] != '\0')
			write(1, "   ", 3);
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		expand_str(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
