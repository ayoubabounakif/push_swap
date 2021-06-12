/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:06:33 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/12 16:08:07 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

void	ft_lstprint_int(t_list *lst)
{
	t_list	*node;

	node = lst;
	while (node != NULL)
	{
		printf("%d\n", *(int *)node->content);
		node = node->next;
	}
}
