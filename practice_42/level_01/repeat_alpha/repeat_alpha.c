/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:09:45 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/13 22:22:12 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

#include <unistd.h>

void	print(char *str)
{
	int	i;
	int	count;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			count = str[i] - 'A' + 1;
		else if (str[i] >= 'a' && str[i] <= 'z')
			count = str[i] - 'a' + 1;
		else
			count = 1;
		while (count --)
			write(1, &str[i], 1);
		i ++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		print(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
