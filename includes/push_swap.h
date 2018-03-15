/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:44:11 by prippa            #+#    #+#             */
/*   Updated: 2018/03/12 21:52:50 by prippa           ###   ########.fr       */
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

# define HISTORY_SIZE 5

typedef	struct		s_stack
{
	int				n;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef	struct		s_op
{
	int				n;
	struct s_op		*next;
}					t_op;

typedef	struct		s_visualizer
{
	int				op;
	int				flag_op_a;
	int				flag_op_b;
	int				num_op_a;
	int				num_op_b;
	int				width_a;
	int				width_b;
	int				flag_vis;
	int				flag_col;
	int				flag_debug;
	int				flag_size;
	int				flag_history;
	int 			h[HISTORY_SIZE];
	int				color;
	int				count_op;
}					t_visualizer;

typedef	struct		s_push_swap
{
	t_op			*op;
	t_stack			*a;
	t_stack			*b;
	t_stack			*a_end;
	t_stack			*b_end;
	int				size_a;
	int				size_b;
	int				flag_is_op_a;
	int				flag_is_op_b;
	char			*buf;
	char			**arr;
	t_visualizer	vis;
}					t_push_swap;

void				ch_parser(t_push_swap *ps);
void				ch_parser_debug(t_push_swap *ps);
void				ch_solve_list_op(t_push_swap *ps);
void				ch_solve_one_op(t_push_swap *ps, int op);
void				ch_vis_dispatcher(t_push_swap *ps, int op);
void				ch_vis_debug_dispatcher(t_push_swap *ps, int op, char *cm);
void				ch_visualize(t_push_swap *ps);
void				ch_vis_print_stack(t_push_swap *ps, t_stack *a, t_stack *b);
void				ch_vis_get_op_num(t_push_swap *ps);

void				ps_algorithm(t_push_swap *ps);

void				ps_make_operation(t_push_swap *ps, int op);
int					ps_op_swap(t_stack **stk);
void				ps_op_swap_duo(t_push_swap *ps);
int					ps_op_push(t_stack **take_start, t_stack **take_end,
					t_stack **put_start, t_stack **put_end);
int					ps_op_rotate(t_stack **stk);
void				ps_op_rotate_duo(t_push_swap *ps);
int					ps_op_reverse_rotate(t_stack **stk);
void				ps_op_reverse_rotate_duo(t_push_swap *ps);

char				*ps_get_operation(int op);

void				ps_init(t_push_swap *ps);

void				ps_parser(t_push_swap *ps, char **argv);

void				ps_free(t_push_swap *ps);

void				ps_operation_push(t_op **op, int n);
void				ps_operation_pop(t_op **op);
void				ps_stack_push(t_stack **start, t_stack **end, int n);
void				ps_stack_pop(t_stack **start, t_stack **end);
void				ps_operation_revers(t_op **op);
void				ps_stack_revers(t_stack **start, t_stack **end);
int					ps_stack_is_sorted(t_stack *stk);

void				ps_free_error_exit(t_push_swap *ps);

#endif
