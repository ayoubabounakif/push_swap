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

// Duplicate and MAX_INT +-

int		syntax_checker(char *arg)
{
	int		tmp;
	int		index;

	tmp = ft_atoi(arg);
	if (tmp == -1953752846 || tmp == 1953752846)
		return (FUNCTION_ERROR);
	index = 0;
	if (tmp < 0)
		index = 1;
	while (arg[index] != '\0')
	{
		if (!ft_isdigit(arg[index]))
			return (FUNCTION_ERROR);
		index++;
	}
	return (FUNCTION_SUCCESS);
}

void	printf_stack_a(t_stack *stack)
{
	while (stack->a)
	{
		printf("%d\n", *(int *)stack->a->content);
		stack->a = stack->a->next;
	}
}

int		main(int ac, char *av[])
{	
	int			i;
	t_stack		stack;
	
	if (ac == 1)
		return (EXIT_FAILURE);
	else
	{
		i = 0;
		while (++i < ac)
		{
			if (!syntax_checker(av[i]))
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				return (EXIT_FAILURE);
			}
		}
		if (!init_stack(ac, av, &stack))
			return (EXIT_FAILURE);
	}

	// nOTHING gets printed ;  Check with pizzzzahboiii!
	printf_stack_a(&stack);
	return (EXIT_SUCCESS);
}
