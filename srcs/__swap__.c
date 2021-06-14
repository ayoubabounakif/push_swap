/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __swap__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:18:37 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/14 12:19:14 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

static void	_swapList(t_list **lst)
{
	printf("executing swap\n");
	fflush(stdout);

	t_list	*tmpA;
	void	*temporaryVar;

	tmpA = *lst;
	if (tmpA == NULL && tmpA->next == NULL)
		return ;
	if (tmpA != NULL && tmpA->next != NULL)
	{
		temporaryVar = tmpA->content;
		tmpA->content = tmpA->next->content;
		tmpA->next->content = temporaryVar;
	}

	printf("list got swapped\n");
	fflush(stdout);
}

void	__swap__(t_stack *stack, char *key)
{
	t_list	*tempA;
	t_list	*tempB;

	tempA = stack->a;
	tempB = stack->b;
	if (key[1] == 'a')
		_swapList(&tempA);
	else if (key[1] == 'b')
		_swapList(&tempB);
	else if (key[1] == 's')
	{
		_swapList(&tempA);
		_swapList(&tempB);
	}
}
