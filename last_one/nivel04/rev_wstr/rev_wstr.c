/*
Assignment name  : rev_wstr
		Expected files   : rev_wstr.c
		Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
		ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
	$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/
#include <stdlib.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, int len)
{
	int	i = 0;
	while (i < len && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str)
{
	int i;
	int	k;
	int	wc;
	int	start;
	int	end;
	char	**split;

	i = 0;
	wc = 0;
	while (str[i] != '\0')
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] !=  '\t' && str[i] != '\n'))
			i++;
	}
	split = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!split)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		start = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		end = i;
		if (start < end)
		{
			split[k] = malloc(sizeof(char) * (end - start) + 1);
			if (!split[k])
				return (NULL);
			ft_strncpy(split[k], &str[start], end - start);
			k++;
		}
	}
	split[k] = NULL;
	return (split);
}

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		char **split = ft_split(av[1]);
		while (split[i] )
			i++;
		if (i > 0)
		{
			while(--i >= 0)
			{
				ft_putstr(split[i]);
				if (i > 0)
					write(1, " ", 1);
			}
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}