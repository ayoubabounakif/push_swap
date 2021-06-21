/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushMinToB.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:27:24 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/16 12:27:40 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pushMinToB(t_stack *stack, void *value)
{
	t_list	*tmp_a;
	int		position;
	int		size;

	tmp_a = stack->a;
	size = ft_lstsize(tmp_a);
	position = findPosition(tmp_a, value);
	if (position <= 2)
	{
		if (position > 1)
			execActions(stack, "sa", PUSH_SWAP);
		execActions(stack, "pb", PUSH_SWAP);
	}
	else
	{
		if ((isEvenOrOdd(size) == ODD && position <= (size / 2) + 1)
			|| (isEvenOrOdd(size) == EVEN && position <= size / 2))
		{
			while (position > 1)
			{
				execActions(stack, "ra", PUSH_SWAP);
				position--;
			}
		}
		else if ((isEvenOrOdd(size) == ODD && position > (size / 2))
			|| (isEvenOrOdd(size) == EVEN && position > (size / 2)))
		{
			while (position <= size)
			{
				execActions(stack, "rra", PUSH_SWAP);
				position++;
			}
		}
		execActions(stack, "pb", PUSH_SWAP);
	}
}
