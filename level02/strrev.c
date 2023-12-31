/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:50:02 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/28 19:13:02 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int	i;
	int	leng;
	char	temp;

	leng = 0;
	i = 0;
	while (str[leng])
		leng++;
	while (leng >= i)
	{
		temp = str[i];
		str[i] = str[leng - 1 - i];
		str[leng - 1 - i] = temp;
		i++;
	}
	return (str);
}
