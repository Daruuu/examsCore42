#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int	max;

	i = 0;
	if (len == 0)
		return (0);
	max = tab[i];
	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}

int	main(void)
{
	int	tab[10] = {-11, 12, 22, 44, 54, 76, 110};

	printf("%d\n", max(tab, 7));

	return (0);
}
