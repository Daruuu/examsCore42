/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:12:00 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/14 13:28:31 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
Assignment name  : rot_13
		Expected files   : rot_13.c
		Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
		letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
		$>./rot_13 "My horse is Amazing." | cat -e
		Zl ubefr vf Nznmvat.$
		$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
		NxwuM mYXVWm , 23l $
		$>./rot_13 | cat -e
		$
$>
$>./rot_13 "" | cat -e
		$
$>
*/
void	rot_13(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = (str[i] - 'A' + 13) % 26 + 'A';
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = (str[i] - 'a' + 13) % 26 + 'a';
		write(1, &str[i], 1);
		i ++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		rot_13(av[1]);
	}
	return (0);
}
