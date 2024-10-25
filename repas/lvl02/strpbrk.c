#include <unistd.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;
	int j = 0;
	while (s1[i])
	{
		while (s2[j])
		{
			if (s1[i] == s2[j])
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
