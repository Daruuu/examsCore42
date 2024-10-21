
#include <unistd.h>

void    wdmatch(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    while (s2[i] != '\0')
    {
        if (s2[i] == s1[j])
        {
            j++;
        }
        i ++;
    }
    if (s1[j] == '\0')
    {
        j = 0;
        while (s1[j])
        {
            write(1, &s1[j], 1);
            j++;
        }
    }
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        wdmatch(av[1], av[2]);
    }
    write(1, "\n", 1);
    return (0);
}