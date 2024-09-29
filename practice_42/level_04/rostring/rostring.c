/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/
#include <unistd.h>

int	case_1_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i ++;
	while (str[i] && (str[i] != ' ' && str[i] != '\t'))
		i ++;
	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	rostring(char *str)
{
	int i;
	int start;
	int end;

	if (case_1_word(str) == 1)
	{
		i = 0;
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i ++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t'))
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	else
	{
		i = 0;
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i ++;
		start = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t'))
			i ++;
		end = i;
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i ++;
		while (str[i])
		{
			if (str[i] == ' ' || str[i] == '\t')
			{
				while (str[i] == ' ' || str[i] == '\t')
					i ++;
				if (str[i])
					write(1, " ", 1);
			}
			if (str[i])
				write(1, &str[i], 1);
			i ++;
		}
		if (start != end)
			write(1, " ", 1);
		while (start < end)
		{
			write(1, &str[start], 1);
			start ++;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
		write(1, "\n", 1);
	else if (ac >= 2)
	{
		rostring(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}