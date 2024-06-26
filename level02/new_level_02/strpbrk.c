#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
				return (char *)(&s1[i]);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	printf("%s\n", ft_strpbrk("hello", "werd"));
	printf("%s\n", strpbrk("hello", "werd"));

	return (0);
}
