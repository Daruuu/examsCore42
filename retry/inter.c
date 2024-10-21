#include <unistd.h>

void    inter(char *str1, char *str2)
{
    int i = 0;
    int j;
    char    ascii_table[256] = {0};

    while (str1[i] != '\0')
    {
        j = 0;
        while (str2[j] != '\0')
        {
            if (str1[i] == str2[j])
            {
                if (!ascii_table[(unsigned char)str1[i]])
                {
                    write(1, &str1[i], 1);
                    ascii_table[(unsigned char)str1[i]] = 1;
                }
                break;
            }
            j++;
        }
        i ++;
    }
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        inter(av[1], av[2]);
    }
    write(1, "\n", 1);
    return (0);
}