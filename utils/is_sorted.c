/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:05:35 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/12 16:05:54 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

int	isSorted(t_list *head)
{
	t_list	*list;

	if (head == NULL)
		return (1);
	list = head;
	while (list->next != NULL)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}

// int		isSorted(t_list *head)
// {
// 	/*	Base case
// 	** This is the base condition of the recursive code.
// 	** If the head becomes NULL or the next element to the head points to NULL,
// 	** we return EVERYTHING_SORTED (TRUE) which means the linked list is sorted
// 	** and the condition to check for sorted element has not returned false yet.
// 	*/
// 	if (head == NULL || head->next == NULL)
// 		return (EVERYTHING_SORTED);

// 	/* Check first two nodes and recursively call for next node.
// 	** we check if the data of current element is less than the data of next node,
// 	** if it's true then next condition will execute and we'll call the function for the next node.
// 	** If the condition is false,
// 	** the function will return false because the condition of being sorted is false.
// 	*/
// 	return ((*(int *)head->content > *(int *)head->next->content)
// 		&& isSorted(head->next));
// }
