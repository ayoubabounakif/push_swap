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
		ft_putstr_fd("pa\n", STDOUT_FILENO);
		pushFrontOtherStack(&stack->b, &stack->a);
		deleteHead(&stack->b);
	}
	if (key[1] == 'b')
	{
		ft_putstr_fd("pb\n", STDOUT_FILENO);
		pushFrontOtherStack(&stack->a, &stack->b);
		deleteHead(&stack->a);
	}
}

void	ft_add_node(t_list **list, void *val)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (*list && node)
	{
		node->content = val;
		node->next = *list;
		*list = node;
	}
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
		ft_putstr_fd("pa\n", STDOUT_FILENO);
		pushBackOtherStack(&stack->b, &stack->a);
		deleteHead(&stack->b);
	}
	if (key[1] == 'b')
	{
		ft_putstr_fd("pb\n", STDOUT_FILENO);
		pushBackOtherStack(&stack->a, &stack->b);
		deleteHead(&stack->a);	
	}
}


// int main(int ac, char *av[])
// {
// 	void	*minValue;
// 	t_stack *s = NULL;

// 	s = StackConstructor();
// 	StackSetter(ac, av, s);
// 	t_list *ls = s->a;
// 	t_list *b;
// 	minValue = findSmallestNode(s->a);
// 	while (s->a)
// 	{
// 		while (ls != NULL)
// 		{
// 			b = ls->next;
// 			pushMinToB(s, ls->content);
// 			printf("IM OUUUUT BRO\n");
// 			fflush(stdout);
// 			ls = b;
// 		}
// 		minValue += 10;
// 	}
// 	printf("%d\n", ft_lstsize(ls));
// 	return (EXIT_SUCCESS);
// }