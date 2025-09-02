/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 13:44:31 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	inter(char *s1, char *s2)
{
	int i = 0;
	int j;
	char	ascii_table[256] = {0};

	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] = s2[j])
			{
				if (!ascii_table[(unsigned char)s1[i]])
				{
					write(1, &s1[i], 1);
					ascii_table[(unsigned char)s1[i]] = 1;
				}
				break ;
			}
			j ++;
		}
		i ++;
	}
}
