#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (str[i] != '\0')
		i++;
	res = malloc(sizeof(char *) * i + 1);
	if (!res)
		return (NULL);
	j = 0;
	while (i >= 0)
	{
		res[j] = str[i - 1];
		i--;
		j++;
	}
	return (res);
}

int	main(void)
{
	printf("%s\n", ft_strrev("abcd"));
	return (0);
}
