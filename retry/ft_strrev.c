#include <stdio.h>
#include <unistd.h>

char    *ft_strrev(char *str)
{
    int i;
    int len;
    char    tmp;

    i = 0;
    len = 0;
    while (str[len] != '\0')
        len ++;
    while (i < (len / 2))
    {
        tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
        i ++;
    }
    return (str);
}

int main(void)
{
    char    str[20] = "hello world in c";
    char    *res = ft_strrev(str);
    int i = 0;
    while (res[i])
    {
        write(1, &res[i], 1);
        i ++;
    }
    write(1, "\n", 1);
}