/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>
*/

#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	**current;
	t_list	*tmp;

	current = begin_list;
	while (*current)
	{
		if (cmp((*current)->data, data_ref) == 0)
		{
			tmp = *current;
			*current = (*current)->next;
			free(tmp->data);
			free(tmp);
		}
		else
		{
			current = &(*current)->next;
		}
	}
}
