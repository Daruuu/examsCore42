#include <unistd.h>
#include <stdlib.h>

void	putnbr(int n)
{
	char digit;

	if (n > 9)
		putbnr(n / 10);
	digit = n % 10 + '0';
	write(1, &digit, 1);
}

void	ft_tab_mult(int n)
{
	int i = 1;
	int result;

	while (i <= 9)
	{
		putnbr(i);
		write(1, " x ", 3);
		putnbr(n);
		write(1, " = ", 3);
		result = i * n;
		putnbr(result);
		write(1, "\n", 1);
		i++;
	}
}