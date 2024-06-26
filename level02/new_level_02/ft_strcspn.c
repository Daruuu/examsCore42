#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			//hello
			//l
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int	main(void)
{
	printf("%zu\n", ft_strcspn("hello", "l"));
	printf("%zu\n", strcspn("hello", "l"));
}
