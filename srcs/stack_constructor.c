/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:34:55 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/11 19:35:13 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

t_stack	*empty_stack_create(void)
{
	t_stack *st;

	if (!(st = (t_stack *)malloc(sizeof(t_stack))))
		return (FUNCTION_ERROR);
	st->a = NULL;
	st->b = NULL;
	return (st);
}