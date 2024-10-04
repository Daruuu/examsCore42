/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/
#include <unistd.h>

void	union_a(char *s1, char *s2)
{
	int	i;
	int	j;
	unsigned char	ascii_table[256] = {0};

	i = 0;
	while (s1[i] != '\0')
	{
		if (!ascii_table[(unsigned char)s1[i]])
		{
			write(1, &s1[i], 1);
			ascii_table[(unsigned char)s1[i]] = 1;
		}
		i ++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		if (!ascii_table[(unsigned char)s2[j]])
		{
			write(1, &s2[j], 1);
			ascii_table[(unsigned char)s2[j]] = 1;
		}
		j ++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		union_a (av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
