#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	char	*result;
	int		len;

	len = 0;
	while (src[len] != '\0')
		len++;
	result = malloc(sizeof(char *) * len + 1);
	if (!result)
		return (0);
	len = 0;
	while (src[len] != '\0')
	{
		result[len] = src[len];
		len ++;
	}
	result[len] = '\0';
	return (result);
}

int	main(void)
{
	char	*res;

	res = ft_strdup("hwllos");
	printf("%s\n", res);
	return (0);
}
