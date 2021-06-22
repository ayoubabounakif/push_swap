/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushMaxToA.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:04:36 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/16 17:05:02 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	helper(t_stack *stack, int position, int size)
{
	if ((isEvenOrOdd(size) == ODD && position <= (size / 2) + 1)
		|| (isEvenOrOdd(size) == EVEN && position <= size / 2))
	{
		while (position > 1)
		{
			execActions(stack, "rb", PUSH_SWAP);
			position--;
		}
	}
	else if ((isEvenOrOdd(size) == ODD && position > (size / 2))
		|| (isEvenOrOdd(size) == EVEN && position > (size / 2)))
	{
		while (position <= size)
		{
			execActions(stack, "rrb", PUSH_SWAP);
			position++;
		}
	}
}

void	pushMaxToA(t_stack *stack, void *value)
{
	int		position;
	int		size;

	size = ft_lstsize(stack->b);
	position = findPosition(stack->b, value);
	if (position <= 2)
	{
		if (position > 1)
			execActions(stack, "sb", PUSH_SWAP);
		execActions(stack, "pa", PUSH_SWAP);
	}
	else
		helper(stack, position, size);
}
