/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:04:14 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/21 20:49:00 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*rev_str(char *str)
{
	int	i; 

	i = 0;
	while (str[i])
		i ++;
	i --;
	while(i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
	write(1, "\n", 1);
	return (str);
}

// int main()
// {
// 	rev_str("Hello world");
// 	// write(1, "\n", 1);
// 	return (0);
// }