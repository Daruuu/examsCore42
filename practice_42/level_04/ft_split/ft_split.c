#include <stdio.h>
#include <stdlib.h>

char	*ft_strncpy(char *s1, char * s2, int size)
{
	int i;

	i = 0;
	while (i < size && s2[i])
	{
		s1[i] = s2[i];
		i ++;
	}
	s1[i] = '\0';
	return (s1);
}

// "	  hello world	in c"
char	**ft_split(char *str)
{
	int i;
	int j;
	int wc;
	int k;
	char **split;

	i = 0;
	wc = 0;
	while (str[i])
	{
		// iterar los espacion - tabulaciones - new line
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i ++;
		// is exist
		if (str[i])
			wc ++;
		// si son letras y no encuentra un ' ' ; es una palabra
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i ++;
	}

	split = (char **)malloc(sizeof (char *) * (wc + 1));
	if (!split)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i ++;
		start = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i ++;
		end = i;
		if (i > j)
		{
			split[k] = (char *) malloc(sizeof (char *) * (i - j) + 1);
			if (!split[k])
				return (NULL);
			ft_strncpy(split[k++], &str[start], end - start);
		}
	}
	split[k] = NULL;
	return (split);
}

int main(int ac, char **av)
{
	char	**result;
	int		i;

	i = 0;
	if (ac == 2)
	{
		result = ft_split(av[1]);
		while (result[i] != NULL)
		{
			printf("%s\n", result[i]);
			i ++;
		}
	}
	free(result);
	return (0);
}