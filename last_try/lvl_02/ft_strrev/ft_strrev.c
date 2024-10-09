/*
Assignment name  : ft_strrev
		Expected files   : ft_strrev.c
		Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/

char    *ft_strrev(char *str)
{
	int	i = 0;
	int	tmp;
	int	size = 0;

	while (str[size] != '\0')
		size ++;
	while (i < (size / 2))
	{
		tmp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = tmp;
		i ++;
	}
	return (str);
}