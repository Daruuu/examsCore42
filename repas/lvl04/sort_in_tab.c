//
// Created by daruuu on 10/25/24.
//
#include <stdlib.h>
#include <stdio.h>

//{1  3 5 -1 0}
void sort_int_tab(int *tab, unsigned int size)
{
	int tmp;
	unsigned int i = 0;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int main(void)
{
	int tabb[6] = { 0, - 22 ,43, 543, 7, 28};
	sort_int_tab(tabb,6);
	int i = 0;
	while (i < 6)
	{
		printf("%d\n", tabb[i]);
		i++;
	}
}