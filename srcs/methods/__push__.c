/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __pushBack__.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:19:42 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/14 16:20:16 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/push_swap.h"

static void	deleteHead(t_list **head_ref)
{
	t_list	*temp;

	if (head_ref == NULL || *head_ref == NULL)
		return ;
	temp = *head_ref;
	*head_ref = temp->next;
	free(temp);
	return ;
}

static void	pushFrontOtherStack(t_list **src, t_list **dst)
{
	t_list	*temp;

	if (*src == NULL)
		return ;
	temp = *src;

	ft_lstadd_front(dst, ft_lstnew(temp->content));
}

void		__pushFront__(t_stack *stack, char *key)
{
	if (key[1] == 'a')
	{
		printf("executing a push from a to b\n");
		ft_putstr_fd("pa\n", STDOUT_FILENO);
		pushFrontOtherStack(&stack->a, &stack->b);
		deleteHead(&stack->a);

		printf("deleting head from stack->a\n");
		fflush(stdout);

	}
	if (key[1] == 'b')
	{
		printf("executing a push from b to a\n");
		ft_putstr_fd("pb\n", STDOUT_FILENO);
		pushFrontOtherStack(&stack->b, &stack->a);
		deleteHead(&stack->b);

		printf("deleting head from stack->b\n");
		fflush(stdout);
		
	}

	printf("push complete!\n");
	fflush(stdout);
}

static void	pushBackOtherStack(t_list **src, t_list **dst)
{
	t_list	*temp;

	if (*src == NULL)
		return ;
	temp = *src;

	ft_lstadd_back(dst, ft_lstnew(temp->content));
}

void		__pushBack__(t_stack *stack, char *key)
{
	if (key[1] == 'a')
	{
		printf("executing a push from b to a\n");
		ft_putstr_fd("pa\n", STDOUT_FILENO);
		pushBackOtherStack(&stack->b, &stack->a);
		deleteHead(&stack->b);

		printf("deleting head from stack->b\n");
		fflush(stdout);

	}
	if (key[1] == 'b')
	{
		printf("executing a push from a to b\n");
		ft_putstr_fd("pb\n", STDOUT_FILENO);
		pushBackOtherStack(&stack->a, &stack->b);
		deleteHead(&stack->a);

		printf("deleting head from stack->a\n");
		fflush(stdout);
		
	}

	printf("push complete!\n");
	fflush(stdout);
}
