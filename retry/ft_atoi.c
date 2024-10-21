#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
    int result;
    int i;
    int sign;

    i = 0;
    sign = 1;
    result = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i ++;
    if (str[i] == '-')
        sign = -1;
    if (str[i] == '-' || str[i] == '+')
        i ++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + str[i] - '0';
        i ++;
    }
    return (sign * result);    
}

int main(int ac, char **av)
{
    (void)ac;
    printf("%d\n", ft_atoi(av[1]));
    return 0;
}
