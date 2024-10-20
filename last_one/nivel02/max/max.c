/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/
#include <stdlib.h>
#include <stdio.h>

int		max(int* tab, unsigned int len)
{
    unsigned int i = 0;
    int max;
    if (tab == NULL || len == 0)
        return (0);
    max = tab[0];
    while (i < len - 1)
    {
        if (tab[i] < tab[i + 1] )
            max = tab[i + 1];
        i ++;
    }
    return (max);
}

int main(void)
{
    int tab[10] = { 12, 43, 65, 87, 0, 111};
    int res = max(tab, 6);
    printf("%d\n",res);
    return (0);
}