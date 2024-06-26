#include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

int	ft_list_size(t_list *begin_list)
{
	int	i = 0;
	t_list *current = begin_list;

	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int	main()
{
	t_list node3 = {NULL, "three"};
    t_list node2 = {&node3, "two"};
    t_list node1 = {&node2, "one"};
    
    printf("List size: %d\n", ft_list_size(&node1));
	// Debe imprimir "List size: 3"
    return 0;

}
