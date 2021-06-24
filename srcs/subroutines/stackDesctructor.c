/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_desctructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:20:19 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/22 20:22:33 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	StackDestructor(t_stack *stack, void (*del)(void *))
{
	ft_lstclear(&stack->a, (*del));
	ft_lstclear(&stack->b, (*del));
	free(stack);
}
