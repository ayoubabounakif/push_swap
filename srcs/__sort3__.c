/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __sort3__.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:13:12 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/15 19:14:57 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void	__sort3__(t_stack *stack)
{
	t_list	*lst;

	lst = stack->a;
	if (*(int *)lst->content > *(int *)lst->next->content)
	{
		if (*(int *)lst->next->content < *(int *)lst->next->next->content)
		{
			if (*(int *)lst->next->next->content > *(int *)lst->content)
				exec_actions(stack, "sa");
			else if (*(int *)lst->next->next->content < *(int *)lst->content)
				exec_actions(stack, "ra");
		}
		else
		{
			exec_actions(stack, "sa");
			exec_actions(stack, "rra");
		}
	}
	else
	{
		if (*(int *)lst->content < *(int *)lst->next->next->content)
		{
			exec_actions(stack, "sa");
			exec_actions(stack, "ra");
		}
		else
			exec_actions(stack, "rra");
	}
}
