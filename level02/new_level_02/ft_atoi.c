/*
 * 1. comprobar si hay espacios o tabulaciones
 * 2. comporbar si hay signo '+' o signo '-'
 * 3. 
*/
int	ft_atoi(char *str)
{
	int	i;
	int	signal;
	int	result;

	i = 0;
	signal = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		signal = -1;
	if (str[i] == '-' || str[i] = '+')
		str[i++];
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}
