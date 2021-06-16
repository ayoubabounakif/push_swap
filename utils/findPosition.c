/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPosition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:25:36 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/16 12:25:51 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

int		findPosition(t_list *lst, void *value)
{
	int		i;

	i = 1;
	while (lst != NULL)
	{
		if (*(int *)lst->content == *(int *)value)
			return (i);
		i++;
		lst = lst->next;
	}
	return (EXIT_SUCCESS);
}
