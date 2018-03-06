/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_make_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:45:35 by prippa            #+#    #+#             */
/*   Updated: 2018/03/06 15:45:38 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_make_operation(t_push_swap *ps, int op)
{
	if (op == SA)
		ps->flag_is_op_a = ps_op_swap(&ps->a);
	else if (op == SB)
		ps->flag_is_op_b = ps_op_swap(&ps->b);
	else if (op == SS)
		ps_op_swap_duo(ps);
	else if (op == PA)
		ps->flag_is_op_a = ps_op_push(&ps->b, &ps->a);
	else if (op == PB)
		ps->flag_is_op_b = ps_op_push(&ps->a, &ps->b);
	else if (op == RA)
		ps->flag_is_op_a = ps_op_rotate(&ps->a);
	else if (op == RB)
		ps->flag_is_op_b = ps_op_rotate(&ps->b);
	else if (op == RR)
		ps_op_rotate_duo(ps);
	else if (op == RRA)
		ps->flag_is_op_a = ps_op_reverse_rotate(&ps->a);
	else if (op == RRB)
		ps->flag_is_op_b = ps_op_reverse_rotate(&ps->b);
	else if (op == RRR)
		ps_op_reverse_rotate_duo(ps);
}
