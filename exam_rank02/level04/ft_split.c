/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	count_words(char *str, char c)
{
	int count = 0;
	int i = 0;
	int in_word = 0;

	while (str[i])
	{
		if (str[i] != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (str[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

int	word_len(char *str, char c, int start)
{
	int len = 0;
	while (str[start + len] && str[start + len] != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_count;
	int		i = 0;
	int		j = 0;
	int		k;

	if (!s)
		return (NULL);
	word_count = count_words((char *)s, c);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	while (i < word_count)
	{
		while (s[j] == c)
			j++;
		k = word_len((char *)s, c, j);
		result[i] = malloc(sizeof(char) * (k + 1));
		if (!result[i])
			return (NULL);
		k = 0;
		while (s[j] && s[j] != c)
		{
			result[i][k] = s[j];
			j++;
			k++;
		}
		result[i][k] = '\0';
		i++;
	}
	result[i] = NULL;
	return (result);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		char **result = ft_split(av[1], av[2][0]);
		int i = 0;
		while (result[i])
		{
			printf("%s\n", result[i]);
			i++;
		}
	}
	return (0);
}
