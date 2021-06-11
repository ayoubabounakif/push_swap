/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:34:55 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/11 19:35:13 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"
# include <string.h>

void	insertAtFront(t_list **list, int data)
{
	t_list	*newNode;

	/* Create a new Linked List node */
	newNode = (t_list *)malloc(sizeof(t_list));
	newNode->content = &data;
	/* Next pointer of new node will point to head node of linked list  */
	newNode->next = *list;
	/* make new node as new head of linked list */
	*list = newNode;
}

t_stack		*init_stack(int ac, char *av[], t_stack *stack)
{
	int		i;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a = NULL;
	stack->b = NULL;
	i = 0;
	while (++i < ac)
		insertAtFront(&stack->a, ft_atoi(av[i]));
	return (stack);
}