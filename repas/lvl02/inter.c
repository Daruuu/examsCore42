//
// Created by daruuu on 10/25/24.
//
#include <unistd.h>

void	inter(char*s1, char *s2)
{
	char ascii_table[256] = {0};
	int i = 0;
	int j;

	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s2[j] == s1[i])
			{
				if (!ascii_table[(unsigned char)s1[i]])
				{
					write(1, &s1[i], 1);
					ascii_table[(unsigned char)s1[i]] = 1;
				}
				break;
			}
			j++;
		}
		i++;
	}
}