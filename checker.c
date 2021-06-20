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

int	validActions(char *buf)
{
	if (buf[0] == 's')
	{
		if (((strcmp(buf, "sa") != EQUAL) && (strcmp(buf, "sb") != EQUAL)
			&& (strcmp(buf, "ss") != EQUAL)))
			return (EXIT_FAILURE);
	}
	if (buf[0] == 'r')
	{
		if (((strcmp(buf, "ra") != EQUAL) && (strcmp(buf, "rb") != EQUAL)
			&& (strcmp(buf, "rr") != EQUAL)))
			return (EXIT_FAILURE);
	}
	if (buf[0] == 'p')
	{
		if ((strcmp(buf, "pa") != EQUAL) && (strcmp(buf, "pb") != EQUAL))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	validActions_2(char *buf)
{
	if (buf[0] == 'r' && buf[1] == 'r')
	{
		if (buf[2] != 'r' && buf[2] != 'a' && buf[2] != 'b') 
			return (EXIT_FAILURE);
		else
			return (EXIT_SUCCESS);
	}
	else
		return (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	syntaxActionsChecker(char *buffer)
{
	int		whichAction;

	whichAction = ft_strlen(buffer);
	if ((whichAction == 2 && validActions(buffer) == EXIT_FAILURE)
		|| (whichAction == 3 && validActions_2(buffer) == EXIT_FAILURE))
		return (EXIT_FAILURE);
	if (whichAction < 2 || whichAction > 3
		|| (buffer[0] != 's' && buffer[0] != 'r' && buffer[0] != 'p'))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	checker(t_stack *stack)
{
	char	*buffer;

	while (get_next_line(STDIN_FILENO, &buffer) > 0)
	{
		if (syntaxActionsChecker(buffer) == EXIT_FAILURE)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		execActions(stack, buffer);
		free(buffer);
		buffer = NULL;
	}
    if (isSorted(stack->a) == EVERYTHING_SORTED && stack->b == NULL)
        ft_putstr_fd("OK\n", STDOUT_FILENO);
    else
        ft_putstr_fd("KO\n", STDOUT_FILENO);
    return (EXIT_SUCCESS);
}

int	main(int ac, char *av[])
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

        if (checker(stack) == EXIT_FAILURE)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		
		// Stack destructor
		StackDestructor(stack, free);
	}
	return (EXIT_SUCCESS);
}
