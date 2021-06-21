/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __rotation__.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:25:02 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/14 12:25:36 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotateList(t_list **head_ref, int k)
{
	int		count;
	t_list	*current;
	t_list	*kthNode;

	if (k == 0)
		return ;
	current = *head_ref;
	count = 1;
	while (count < k && current != NULL)
	{
		current = current->next;
		count++;
	}
	if (current == NULL)
		return ;
	kthNode = current;
	while (current->next != NULL)
		current = current->next;
	current->next = *head_ref;
	*head_ref = kthNode->next;
	kthNode->next = NULL;
}

static int	countList(t_list *head)
{
	t_list	*content;
	int		i;

	content = head;
	i = 0;
	while (content != NULL)
	{
		i++;
		content = content->next;
	}
	return (i);
}

static void	reverseRotation(t_stack *stack, char *key, int program)
{
	if (key[2] == 'a')
	{
		if (program == PUSH_SWAP)
			ft_putstr_fd("rra\n", STDOUT_FILENO);
		rotateList(&stack->a, countList(stack->a) - 1);
	}
	else if (key[2] == 'b')
	{
		if (program == PUSH_SWAP)
			ft_putstr_fd("rrb\n", STDOUT_FILENO);
		rotateList(&stack->b, countList(stack->b) - 1);
	}
	else if (key[2] == 'r')
	{
		if (program == PUSH_SWAP)
			ft_putstr_fd("rrr\n", STDOUT_FILENO);
		rotateList(&stack->a, countList(stack->a) - 1);
		rotateList(&stack->b, countList(stack->b) - 1);
	}
}

static void	basicRotation(t_stack *stack, char *key, int program)
{
	if (key[1] == 'a')
	{
		if (program == PUSH_SWAP)
			ft_putstr_fd("ra\n", STDOUT_FILENO);
		rotateList(&stack->a, 1);
	}
	else if (key[1] == 'b')
	{
		if (program == PUSH_SWAP)
			ft_putstr_fd("rb\n", STDOUT_FILENO);
		rotateList(&stack->b, 1);
	}
	else if (key[1] == 'r')
	{
		if (program == PUSH_SWAP)
			ft_putstr_fd("rr\n", STDOUT_FILENO);
		rotateList(&stack->a, 1);
		rotateList(&stack->b, 1);
	}
}

void	__rotation__(t_stack *stack, char *key, int program)
{
	if (ft_strlen(key) == 2)
		basicRotation(stack, key, program);
	if (ft_strlen(key) == 3)
		reverseRotation(stack, key, program);
	return ;
}
