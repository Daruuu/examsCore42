/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:28:16 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/31 15:55:13 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_size.c"
#include <stdio.h>

void	print_list(t_list *begin_list)
{
	while (begin_list != NULL)
	{
		printf("%p -> ", (void *)begin_list->data);
		begin_list = begin_list->next;
	}
}

//int	main(int ac, char **av)
int	main()
{
	// nodos creados 
	t_list node1;
	t_list node2;
	t_list node3;

	// datos de cada nodo
	int	data1;
	int	data2;
	int	data3;

	//inicializar datos
	data1 = 4;
	data2 = 5;
	data3 = 7;
	
	// dar a cada nodo un valor
	node1.data = &data1; 
	node2.data = &data2; 
	node3.data = &data3; 

	// enlazar nodos consecutivamente
	node1.next = &node2;
	node2.next = &node3;
	node3.next = NULL;


	// print list 
	printf("Link list: ");
	print_list(&node1);

	// print size of list
	int	size = ft_list_size(&node1);
	printf("size of the list: %d\n", size);

	return (0);
}
