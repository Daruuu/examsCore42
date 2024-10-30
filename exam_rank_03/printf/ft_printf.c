#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str, int *count)
{
	int	i = 0;
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		(*count)++;
		i++;
	}
}

static void	putnbr(int nbr, int *count)
{
	char	digit;
	if (nbr > 9)
		putnbr (nbr / 10, count);
	digit = (nbr % 10) + '0';
	write (1, &digit, 1);
}

void	print_hex(int n, int *count)
{
	char	*hex = "0123456789abcdef";

	if (n >= 16)
		print_hex(nbr / 16, count);
	write(1, &hex[n % 16]);

}

int	ft_printf(const char *format, ...)
{
	int	count;

}
