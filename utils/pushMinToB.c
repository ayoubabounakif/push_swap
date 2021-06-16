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

# include "../includes/push_swap.h"

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
			execActionsB(stack, "sa");
		execActionsB(stack, "pb");
	}
	else
	{
		if ((isEvenOrOdd(size) == ODD && position <= (size / 2) + 1)
			|| (isEvenOrOdd(size) == EVEN && position <= size / 2))
		{
			while (position > 1)
			{
				execActionsB(stack, "ra");
				position--;
			}
		}
		else if ((isEvenOrOdd(size) == ODD && position > (size / 2))
			|| (isEvenOrOdd(size) == EVEN && position > (size / 2)))
		{
			while (position <= size)
			{
				execActionsB(stack, "rra");
				position++;
			}
		}
		execActionsB(stack, "pb");
	}
}
