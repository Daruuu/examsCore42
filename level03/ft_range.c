#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	len;
	int	*res;
	int	i;

	len = (end - start) + 1;
	res = malloc(sizeof(int *) * len);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if ()
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
