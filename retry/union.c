
#include <unistd.h>

void    unionn(char *s1, char *s2)
{
    int i = 0;
    char    ascii_table[256] ={0};
    while (s1[i] != '\0')
    {
        if (!ascii_table[(unsigned char)s1[i]])
        {
            write(1, &s1[i], 1);
            ascii_table[(unsigned char)s1[i]] = 1;
        }
        i ++;
    }
    
    i = 0;
    while (s2[i] != '\0')
    {
        if (!ascii_table[(unsigned char)s2[i]])
        {
            write(1, &s2[i], 1);
            ascii_table[(unsigned char)s2[i]] = 1;
        }
        i ++;
    }
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        unionn(av[1], av[2]);
    }
    else
        write(1, "\n", 1);
    return (0);
}