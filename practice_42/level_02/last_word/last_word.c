#include <unistd.h>

void	last_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i ++;
	while (str[i] == ' ' || str[i] == '\t')
		i --;
	while (str[i] != ' ' && str[i] != '\t')
		i --;
	i++;
	while (str[i] != ' ' && str[i] != '\t')
		write(1, &str[i], 1);
	i++;
}
