/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:44:11 by prippa            #+#    #+#             */
/*   Updated: 2018/02/28 19:44:13 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef	struct		s_stack
{
	int				n;
	struct s_stack	*next;
}					t_stack;

typedef	struct		s_push_swap
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*op;
	char			*buf;
	char			**arr;
}					t_push_swap;

void				ps_make_operation(t_push_swap *ps, int op);

void				ps_op_swap(t_stack **stk);
void				ps_op_swap_duo(t_stack **a, t_stack **b);
void				ps_op_push(t_stack **take, t_stack **put);
void				ps_op_rotate(t_stack **stk);
void				ps_op_rotate_duo(t_stack **a, t_stack **b);
void				ps_op_reverse_rotate(t_stack **stk);
void				ps_op_reverse_rotate_duo(t_stack **a, t_stack **b);

void				ch_parser(t_push_swap *ps);

void				ps_print_operation(int op);

void				ps_init(t_push_swap *ps);

void				ps_parser(t_push_swap *ps, char **argv);

void				ps_free(t_push_swap *ps);

void				ps_stack_push(t_stack **stk, int n);
void				ps_stack_pop(t_stack **stk);
void				ps_stack_revers(t_stack **stk);
int 				ps_stack_is_sorted(t_stack *stk);

void				ps_free_error_exit(t_push_swap *ps);

#endif
