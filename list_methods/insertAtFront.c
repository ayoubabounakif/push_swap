/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertAtFront.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:14:13 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/12 13:14:32 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void	insertAtFront(t_list **list, void *data)
{
	t_list	*newNode;

	/* Create a new Linked List node */
	if (!(newNode = (t_list *)malloc(sizeof(t_list))))
		return ;
	newNode->content = data;
	/* Next pointer of new node will point to head node of linked list  */
	newNode->next = *list;
	/* make new node as new head of linked list */
	*list = newNode;
}
