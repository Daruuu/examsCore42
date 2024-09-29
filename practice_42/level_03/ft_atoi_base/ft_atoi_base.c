// Created by daruuu on 9/26/24.
/*
Assignment name  : ft_atoi_base
		Expected files   : ft_atoi_base.c
		Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
		example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
		string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);*/
#include <stdlib.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int i;
	int value;
	int sign;
	int result;

	sign = 0;
	if (str_base < 2 || str_base > 16)
		return (NULL);
	i = 0;
	while (str[i] == ' ' && (str[i] >= 9 && str[i] <= 13))
		i ++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+')
		i ++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			value = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'z')
			value = str[i] - 'a' + 10 ;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			value = str[i] - 'A' + 10;
		else
			break ;
		if (value >= str_base)
			break ;
		result = result * str_base + value;
		i ++;
	}
	return (result * sign);
}
