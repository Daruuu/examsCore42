#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	len;
	int	*res;

	len = end - start; 
	res = malloc(sizeof(int *)* len + 1);
	if (!res)
		return (NULL);
	int	i;

	i = 0;
	while (i < len)
	{
		res[i] = start;
		start++;
	}
	res[i] = '\0';
	return (res);
}

int	main()
{
	int	*res = ft_range(1, 6);

	int	i;

	i = 0;
	while (i < 6)
	{
		printf("%d\n", res[i]);
		i++;
	}
	return (0);
}
