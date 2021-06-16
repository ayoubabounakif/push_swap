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

void	sortStack(t_stack *stack, int ac)
{
	if (ac == 4)
		__sort3__(stack);
	if (ac == 6)
		__sort5__(stack);
	else
		__sortAll__(stack);
	return ;
}

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
			if (!syntaxChecker(av[i]))
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				return (EXIT_FAILURE);
			}
		}
		// Constructor
		if (!(stack = StackConstructor()))
			return (EXIT_FAILURE);

		// Setter
		if (!StackSetter(ac, av, stack))
			return (EXIT_FAILURE);
		
		// Duplicates handling
		if (checkForDups(stack->a) == DUPLICATE_FOUND)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (EXIT_FAILURE);
		}

		// TO-DO : Check if what's given is already sorted.

		// FIX THIS FUNCTION
		if (isSorted(stack->a) == EVERYTHING_SORTED)
		{
			printf("Supposedly Everything's sorted\n");
			fflush(stdout);
			StackDestructor(stack, free);
			return (EXIT_SUCCESS);
		}

		// printf("list before sort\n");
		// fflush(stdout);
		// ft_lstprint_int(stack->a);
		// // MAIN PROGRAM : Sort the godamn stack
		// printf("\ngonna start execution actions zzzzzz\n\n");

		sortStack(stack, ac);

		// printf("\n");
		// printf("list after sort\n");
		// ft_lstprint_int(stack->a);
		
		// Stack destructor
		StackDestructor(stack, free);
	}
	return (EXIT_SUCCESS);
}
