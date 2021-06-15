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

void	*_findSmallestNode(t_list *lst)
{
	t_list	*tmp;
	void	*min;

	tmp = lst;
	min = tmp->content;
	while (tmp != NULL)
	{
		if (*(int *)min > *(int *)tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

void	__sort5__(t_stack *stack)
{
	t_list	*lst;
	void	*minValue;

	minValue = _findSmallestNode(stack->a);
	printf("%d\n-----\n", *(int *)minValue);

	__push__(stack, "pa");
	printf("-----\n--- stack b ---\n");
	ft_lstprint_int(stack->b);
	printf("-----\n--- stack a ---\n");
	ft_lstprint_int(stack->a);
}
void	sortStack(t_stack *stack, int ac)
{
	if (ac == 4)
		__sort3__(stack);
	if (ac == 6)
		__sort5__(stack);
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

		// FIX THIS FUNCTION
		if (isSorted(stack->a) == EVERYTHING_SORTED)
		{
			printf("Supposedly Everything's sorted\n");
			fflush(stdout);
			stack_destructor(stack, free);
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
		stack_destructor(stack, free);
	}
	return (EXIT_SUCCESS);
}
