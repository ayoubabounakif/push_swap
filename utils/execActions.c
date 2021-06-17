/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execActions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:15:45 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/15 19:16:07 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void	execActions(t_stack *stack, char *key)
{
	if (key[0] == 's')
		__swap__(stack, key);
	else if (key[0] == 'r')
		__rotation__(stack, key);
	else if (key[0] == 'p')
		__push__(stack, key);
	return ;
}
