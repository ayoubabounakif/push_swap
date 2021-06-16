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

# include "../../includes/push_swap.h"

static void	rotateList(t_list **head_ref, int k)
{
    printf("starting rotation!\n");
    fflush(stdout);

    if (k == 0)
        return;
 
    // Let us understand the below code for example k = 4 and
    // list = 10->20->30->40->50->60.
    t_list *current = *head_ref;
 
    // current will either point to kth or NULL after this loop.
    // current will point to node 40 in the above example
    int count = 1;
    while (count < k && current != NULL) {
        current = current->next;
        count++;
    }
 
    // If current is NULL, k is greater than or equal to count
    // of nodes in linked list. Don't change the list in this case
    if (current == NULL)
        return;
 
    // current points to kth node. Store it in a variable.
    // kthNode points to node 40 in the above example
    t_list *kthNode = current;
 
    // current will point to last node after this loop
    // current will point to node 60 in the above example
    while (current->next != NULL)
        current = current->next;
 
    // Change next of last node to previous head
    // Next of 60 is now changed to node 10
    current->next = *head_ref;
 
    // Change head to (k+1)th node
    // head is now changed to node 50
    *head_ref = kthNode->next;
 
    // change next of kth node to NULL
    // next of 40 is now NULL
    kthNode->next = NULL;

    printf("finished rotation\n");
    fflush(stdout);
}

static int	_countList(t_list *head)
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

static void	reverseRotation(t_stack *stack, char *key)
{
	if (key[2] == 'a')
	{
		ft_putstr_fd("rra\n", STDOUT_FILENO);
		rotateList(&stack->a, _countList(stack->a) - 1);
	}
	else if (key[2] == 'b')
	{
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
		rotateList(&stack->b, _countList(stack->b) - 1);
	}
	else if (key[2] == 'r')
	{
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
		rotateList(&stack->a, _countList(stack->a) - 1);
		rotateList(&stack->b, _countList(stack->b) - 1);
	}
}

static void	basicRotation(t_stack *stack, char *key)
{
	if (key[1] == 'a')
	{
		ft_putstr_fd("ra\n", STDOUT_FILENO);
		rotateList(&stack->a, 1);
	}
	else if (key[1] == 'b')
	{
		ft_putstr_fd("rb\n", STDOUT_FILENO);
		rotateList(&stack->b, 1);
	}
	else if (key[1] == 'r')
	{
		ft_putstr_fd("rr\n", STDOUT_FILENO);
		rotateList(&stack->a, 1);
		rotateList(&stack->b, 1);
	}
}

void		__rotation__(t_stack *stack, char *key)
{
    if (ft_strlen(key) == 2)
		basicRotation(stack, key);
    if (ft_strlen(key) == 3)
		reverseRotation(stack, key);
	return ;
}
