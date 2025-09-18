/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *current = lst;
	t_list *next;
	void *temp;

	while (current)
	{
		next = current->next;
		while (next)
		{
			if (cmp(*(int *)current->data, *(int *)next->data) > 0)
			{
				temp = current->data;
				current->data = next->data;
				next->data = temp;
			}
			next = next->next;
		}
		current = current->next;
	}
	return (lst);
}
