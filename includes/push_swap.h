/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:22:58 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/11 19:24:18 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

# define FUNCTION_ERROR 0
# define FUNCTION_SUCCESS 1

typedef struct	s_stack
{
    t_list	*a;
    t_list	*b;
}				t_stack;

/*
**  init_stack and store data
*/
t_stack		*init_stack(int ac, char *av[], t_stack *stack);

#endif
