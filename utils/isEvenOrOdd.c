/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isEvenOrOdd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:09:03 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/16 12:09:11 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

int		isEvenOrOdd(int n)
{
	if (n % 2 == 0)
		return (EVEN);
	else
		return (ODD);
	return (EXIT_SUCCESS);
}