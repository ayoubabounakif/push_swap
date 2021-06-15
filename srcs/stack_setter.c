/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:22:16 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/15 14:22:26 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

int		store_data(int ac, char *av[], t_stack *stack)
{
	int		i;

	i = 0;
	while (++i < ac)
		ft_lstadd_back(&stack->a, ft_lstnew((void *)ft_intdup(ft_atoi(av[i]))));
	return (FUNCTION_SUCCESS);
}