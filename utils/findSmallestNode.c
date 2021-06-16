/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findSmallestNode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:24:28 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/16 12:24:51 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void	*findSmallestNode(t_list *lst)
{
	void	*min;

	min = lst->content;
	while (lst != NULL)
	{
		if (*(int *)min > *(int *)lst->content)
			min = lst->content;
		lst = lst->next;
	}
	return (min);
}
