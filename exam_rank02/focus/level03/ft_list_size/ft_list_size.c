typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list) {
	int i = 0;
	t_list *current = begin_list;
	while (current) {
		i++;
		current = current->next;
	}
	return (i);
}