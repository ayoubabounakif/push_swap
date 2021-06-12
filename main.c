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

		// Printing my list
		ft_lstprint_int(stack->a);

		// MAIN PROGRAM :
		// TO-DO : Check if what's given is already sorted.
		if (isSorted(stack->a) == EVERYTHING_SORTED)
		{
			printf("Supposedly Everything's sorted\n");
			fflush(stdout);
			stack_destructor(stack, free);
			return (EXIT_SUCCESS);
		}

		// TO-DO : Make methods of push_swap
	
		
		// Stack destructor
		stack_destructor(stack, free);
	}
	while (stack->a)
	{
		printf("%d\n", *(int *)stack->a->content);
		stack->a = stack->a->next;
	}
	return (EXIT_SUCCESS);
}
