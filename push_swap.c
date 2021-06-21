/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:22:11 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/11 19:22:46 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sortStack(t_stack *stack, int ac)
{
	if (ac == 4)
		__sort3__(stack);
	else if (ac == 5)
		__sort4__(stack);
	else if (ac == 6)
		__sort5__(stack);
	else if (ac > 6)
		__sortAll__(stack);
	return ;
}

static int	__main__(int ac, char *av[], t_stack *stack)
{
	stack = StackConstructor();
	if (!StackSetter(ac, av, stack))
		return (EXIT_FAILURE);
	if (checkForDups(stack->a) == DUPLICATE_FOUND)
		return (EXIT_FAILURE);
	if (isSorted(stack->a) == EVERYTHING_SORTED)
	{
		StackDestructor(stack, free);
		return (EXIT_SUCCESS);
	}
	sortStack(stack, ac);
	StackDestructor(stack, free);
	return (EXIT_SUCCESS);
}

int	main(int ac, char *av[])
{	
	t_stack		*stack;

	stack = NULL;
	if (ac == 1)
		return (EXIT_FAILURE);
	else
	{
		if (!syntaxChecker(ac, av))
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		if (__main__(ac, av, stack) == EXIT_FAILURE)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
