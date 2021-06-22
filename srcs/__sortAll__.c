/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __sortAll__.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:44:10 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/16 12:44:43 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	backToA(t_stack *stack, void *maxValue)
{
	t_list	*lstB;

	lstB = stack->b;
	while (lstB != NULL)
	{
		maxValue = findLargestNode(stack->b);
		pushMaxToA(stack, maxValue);
		lstB = stack->b;
	}
}

void	__sortAll__(t_stack *stack)
{
	t_list	*lstA;
	t_list	*betadine;
	void	*minValue;
	void	*maxValue;
	int		range;

	minValue = findSmallestNode(stack->a);
	maxValue = findLargestNode(stack->a);
	range = *(int *)minValue;
	while (stack->a != NULL)
	{
		lstA = stack->a;
		while (lstA != NULL)
		{
			betadine = lstA->next;
			if (*(int *)lstA->content <= range)
				pushMinToB(stack, lstA->content);
			lstA = betadine;
		}
		range += (*(int *)maxValue - *(int *)minValue) / 10;
	}
	backToA(stack, maxValue);
}
