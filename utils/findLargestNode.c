/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findLargestNode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:52:28 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/16 16:54:28 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void	*findLargestNode(t_list *lst)
{
	void	*max;

	max = lst->content;
	while (lst != NULL)
	{
		if (*(int *)max < *(int *)lst->content)
			max = lst->content;
		lst = lst->content;
	}
	return (max);
}
