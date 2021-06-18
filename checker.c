/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 20:18:29 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/18 20:18:38 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/push_swap.h"
# include "get_next_line/get_next_line.h"

void    checker(t_stack *stack)
{

    // TO-DO : Get Lwalida

    if (isSorted(stack->a) == EVERYTHING_SORTED && stack->b == NULL)
        ft_putstr_fd("OK\n", STDOUT_FILENO);
    else
        ft_putstr_fd("KO\n", STDOUT_FILENO);
    return ;
}

int     main(int ac, char *av[])
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

        checker(stack);
		
		// Stack destructor
		StackDestructor(stack, free);
	}
	return (EXIT_SUCCESS);
}
