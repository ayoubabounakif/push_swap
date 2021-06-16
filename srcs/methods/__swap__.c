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

# include "../../includes/push_swap.h"

static void	swapList(t_list **lst)
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
	{
		ft_putstr_fd("sa\n", STDOUT_FILENO);
		swapList(&tempA);
	}
	else if (key[1] == 'b')
	{
		ft_putstr_fd("sb\n", STDOUT_FILENO);
		swapList(&tempB);
	}
	else if (key[1] == 's')
	{
		ft_putstr_fd("ss\n", STDOUT_FILENO);
		swapList(&tempA);
		swapList(&tempB);
	}
}
