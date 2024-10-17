#include <unistd.h>

void	rstr_capi(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		// upppercase to lowecase
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		//	lowercase a uppercase incluyenfdo: espcio - tab - null
		else if ((str[i] >= 'a' && str[i] <= 'z') \
			&& (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i] == '\0'))
			str[i] = str[i] - 32;
		write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 1)
		write(1, "\n", 1);
	else
	{
		int i = 1;
		while (i < ac)
		{
			rstr_capi(av[i]);
			write(1, "\n", 1);
			i ++;
		}
	}
	return (0);
}
