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

# include "includes/push_swap.h"

int		main(int ac, char *av[])
{	
	int			i;
	t_stack		*stack;

	if (ac == 1)
		return (EXIT_FAILURE);
	else
	{
		i = 0;
		while (++i < ac)
		{
			// Syntax handling
			if (!syntax_checker(av[i]))
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				return (EXIT_FAILURE);
			}
		}
		// Constructor
		if (!(stack = empty_stack_create()))
			return (EXIT_FAILURE);
		
		// Setter
		if (!store_data(ac, av, stack))
			return (EXIT_FAILURE);
		
		// Duplicates handling
		if (check_for_dups(stack->a) == DUPLICATE_FOUND)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (EXIT_FAILURE);
		}

		// WILL DO THE SORTING....
		
		stack_destructor(stack, free);
		// Stack destructor
		// TO-DO: Make a stack destructor method stack_destructor((*f)(void));
	}
	while (stack->a)
	{
		printf("%d\n", *(int *)stack->a->content);
		stack->a = stack->a->next;
	}
	return (EXIT_SUCCESS);
}
