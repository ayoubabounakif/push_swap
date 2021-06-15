/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:52:45 by aabounak          #+#    #+#             */
/*   Updated: 2020/12/15 12:56:53 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int	count;

	count = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
