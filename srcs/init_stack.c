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

int		store_data(int ac, char *av[], t_stack *stack)
{
	int		i;

	i = 0;
	while (++i < ac)
		ft_lstadd_back(&stack->a, ft_lstnew((void *)ft_intdup(ft_atoi(av[i]))));
	return (FUNCTION_SUCCESS);
}