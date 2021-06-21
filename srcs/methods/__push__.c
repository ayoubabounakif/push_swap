/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __push__.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:19:42 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/14 16:20:16 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

static void	addNode(t_list **list, void *val)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (list && node)
	{
		node->content = val;
		node->next = *list;
		*list = node;
	}
}

static void	pushOtherStack(t_list **src, t_list **dst)
{
	t_list	*temp;

	if (*src == NULL)
		return ;
	temp = *src;
	addNode(dst, temp->content);
	deleteHead(src);
}

void	__push__(t_stack *stack, char *key, int program)
{
	if (key[1] == 'a')
	{
		if (program == PUSH_SWAP)
			ft_putstr_fd("pa\n", STDOUT_FILENO);
		pushOtherStack(&stack->b, &stack->a);
	}
	if (key[1] == 'b')
	{
		if (program == PUSH_SWAP)
			ft_putstr_fd("pb\n", STDOUT_FILENO);
		pushOtherStack(&stack->a, &stack->b);
	}
}
