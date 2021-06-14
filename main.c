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

void	exec_actions(t_stack *stack, char *key)
{
	if (key[0] == 's')
		__swap__(stack, key);
	else if (key[0] == 'r')
		__rotation__(stack, key);
	else if (key[0] == 'p')
		__push__(stack, key);
	return ;
}

void	sortStack(t_stack *stack, int ac)
{
	if (ac == 4)
	/* 	exec_actions(stack, "sa");
		exec_actions(stack, "ra");
		exec_actions(stack, "pa"); */
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


		// TO-DO : Check if what's given is already sorted.
		if (isSorted(stack->a) == EVERYTHING_SORTED)
		{
			printf("Supposedly Everything's sorted\n");
			fflush(stdout);
			stack_destructor(stack, free);
			return (EXIT_SUCCESS);
		}


		// MAIN PROGRAM : Sort the godamn stack
		sortStack(stack, ac);
		
		// Stack destructor
		stack_destructor(stack, free);
	}
	return (EXIT_SUCCESS);
}
