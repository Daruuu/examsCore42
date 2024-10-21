#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
    size_t i = 0;
    size_t j;
    while (s[i] != '\0')
    {
        j = 0;
        while (accept[j] != '\0')
        {
            if (s[i] == accept[j])
                break;
            j ++;
        }
        if (accept[j] == '\0')
            break;
        i ++;
    }
    return (i);
}
