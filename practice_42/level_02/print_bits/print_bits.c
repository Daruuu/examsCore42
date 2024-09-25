#include <unistd.h>

void	print_bits(unsigned char octect)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i --)
	{
		bit = (octect >> i & 1) + '0';
		write(1, &bit, 1);
	}
}
