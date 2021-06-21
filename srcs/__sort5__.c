/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __sort5__.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:07:13 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/16 12:07:37 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	__sort5__(t_stack *stack)
{
	void	*minValue;

	minValue = findSmallestNode(stack->a);
	pushMinToB(stack, minValue);
	minValue = findSmallestNode(stack->a);
	pushMinToB(stack, minValue);
	__sort3__(stack);
	if (*(int *)stack->b->content < *(int *)stack->b->next->content)
		execActions(stack, "sb", PUSH_SWAP);
	execActions(stack, "pa", PUSH_SWAP);
	execActions(stack, "pa", PUSH_SWAP);
}
