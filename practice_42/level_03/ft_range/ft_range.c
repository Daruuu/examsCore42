#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	len;
	int	i;
	int	*array;

	//saber la longitud del array
	if (start <= end) 
		len = (end - start) + 1;
	else	// start > end
		len = (start - end) + 1;
	array = malloc(sizeof(int) * len);
	if (!array)
		return (NULL);
	i = 0;
	if (start <= end)
	{
		while (start <= end)
		{
			array[i] = start;
			start++;
			i++;
		}
	}
	else
	{
		while (start => end)
		{
			array[i] = start;
			start--;
			i++;
		}
	}
	return (array);
}
