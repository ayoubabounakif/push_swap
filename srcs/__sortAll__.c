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

# include "../includes/push_swap.h"

void	__sortAll__(t_stack *stack)
{
	t_list	*lstA;
	t_list	*lstB;
	void	*minValue;
	void	*maxValue;
	int		range;

	minValue = findSmallestNode(stack->a);
	range = *(int *)minValue;
	while (stack->a != NULL)
	{
		lstA = stack->a;
		while (lstA != NULL)
		{
			// TO-DO: Fix infinite loop.
			if (*(int *)lstA->content <= range)
				printf("Infinite loop!\n");
				// pushMinToB(stack, lstA->content);
			lstA = lstA->next;
		}
		range += 30;
	}

			/* 	This piece of code will loop through stack B
				and search for the largest node and push it to stack A */
/* 	lstB = stack->b;
	while (lstB != NULL)
	{
		// maxValue = findLargestNode(stack->b);
		exit(0);
		// pushMaxToA(stack, maxValue);
		lstB = lstB->next;
	} */
	ft_lstprint_int(stack->b);
}
