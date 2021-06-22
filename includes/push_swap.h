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
# define EVERYTHING_SORTED 1002
# define NOT_SORTED 1003

# define TRUE 1
# define FALSE 0

# define EQUAL 0

# define EVEN 0
# define ODD 1

# define PUSH_SWAP 1004
# define CHECKER 1005

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}				t_stack;

/*
**	stack constructor
*/
t_stack	*StackConstructor(void);

/*
**	stack setter
**/
int		StackSetter(int ac, char *av[], t_stack *stack);

/*
**	methods (actions)
*/
void	__swap__(t_stack *stack, char *key, int program);
void	__rotation__(t_stack *stack, char *key, int program);
void	__push__(t_stack *stack, char *key, int program);

/*
**	main functions
*/
void	__sort3__(t_stack *stack);
void	__sort4__(t_stack *stack);
void	__sort5__(t_stack *stack);
void	__sortAll__(t_stack *stack);

/*
**	utils
*/
int		syntaxChecker(int ac, char **arg);
int		checkForDups(t_list *head);
int		isSorted(t_list *head);
int		isEvenOrOdd(int n);

void	*findSmallestNode(t_list *lst);
void	*findLargestNode(t_list *lst);
int		findPosition(t_list *lst, void *value);
void	pushMinToB(t_stack *stack, void *value);
void	pushMaxToA(t_stack *stack, void *value);

void	execActions(t_stack *stack, char *key, int program);

/*
**	stack destructor
*/
void	StackDestructor(t_stack *stack, void (*del)(void *));

#endif
