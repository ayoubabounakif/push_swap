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

#include "../../includes/push_swap.h"

static void	swapList(t_list **lst)
{
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
}

void	__swap__(t_stack *stack, char *key, int program)
{
	t_list	*tempA;
	t_list	*tempB;

	tempA = stack->a;
	tempB = stack->b;
	if (key[1] == 'a')
	{
		if (program == PUSH_SWAP)
			ft_putstr_fd("sa\n", STDOUT_FILENO);
		swapList(&tempA);
	}
	else if (key[1] == 'b')
	{
		if (program == PUSH_SWAP)
			ft_putstr_fd("sb\n", STDOUT_FILENO);
		swapList(&tempB);
	}
	else if (key[1] == 's')
	{
		if (program == PUSH_SWAP)
			ft_putstr_fd("ss\n", STDOUT_FILENO);
		swapList(&tempA);
		swapList(&tempB);
	}
}
