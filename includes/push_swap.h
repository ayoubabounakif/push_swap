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

# include <string.h>

# define FUNCTION_ERROR 0
# define FUNCTION_SUCCESS 1
# define DUPLICATE_FOUND 1001

typedef struct	s_stack
{
    t_list	*a;
    t_list	*b;
}				t_stack;

/*
**  stack constructor
*/
t_stack	*empty_stack_create(void);
int     store_data(int ac, char *av[], t_stack *stack);

/*
**  utils
*/
int		syntax_checker(char *arg);
int		check_for_dups(t_list *head);

/*
** list methods
*/
void	insertAtFront(t_list **list, void *data);

/*
**  stack destructor
*/
void    stack_destructor(t_stack *stack, void (*del)(void *));

#endif
