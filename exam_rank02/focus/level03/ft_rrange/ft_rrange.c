#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
	int i;
	int *range;
	int len;

	if (start < end)
		len = (end - start) + 1;
	else
		len = (start - end) + 1;
	range = malloc(sizeof(int) * len);
	if (!range)
		return (NULL);
	i = 0;
	while (i < len)
	{
		range[i] = end;
		if (end > start)
			end --;
		else
			end ++;
		i ++;
	}
	return (range);
}

int main(void)
{
	int *result = ft_rrange(1, 3);
	int i = 0;
	while (result[i])
	{
		printf("%d\n", result[i]);
		i ++;
	}
	return (0);
}
