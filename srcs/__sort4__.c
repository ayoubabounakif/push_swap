/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __sort4__.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 21:12:55 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/17 21:12:55 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void	__sort4__(t_stack *stack)
{
	void	*minValue;

	minValue = findSmallestNode(stack->a);
	pushMinToB(stack, minValue);
	__sort3__(stack);
	execActions(stack, "pa", PUSH_SWAP);
}

