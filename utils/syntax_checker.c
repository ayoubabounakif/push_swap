/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:17:16 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/12 13:17:51 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

int		syntax_checker(char *arg)
{
	int		tmp;
	int		index;

	tmp = ft_atoi(arg);
	if (tmp == -1953752846 || tmp == 1953752846)
		return (FUNCTION_ERROR);
	index = 0;
	if (tmp < 0)
		index = 1;
	while (arg[index] != '\0')
	{
		if (!ft_isdigit(arg[index]))
			return (FUNCTION_ERROR);
		index++;
	}
	return (FUNCTION_SUCCESS);
}
