/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isSorted.c                                         :+:      :+:    :+:   */
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
		return (EVERYTHING_SORTED);
	list = head;
	while (list->next != NULL)
	{
		if (*(int *)list->content > *(int *)list->next->content)
			return (NOT_SORTED);
		list = list->next;
	}
	return (EVERYTHING_SORTED);
}
