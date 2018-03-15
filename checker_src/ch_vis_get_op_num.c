/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_vis_get_op_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 12:55:26 by prippa            #+#    #+#             */
/*   Updated: 2018/03/07 12:55:28 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ch_vis_get_swap_num(t_push_swap *ps)
{
	if ((ps->vis.op == SA || ps->vis.op == SS) && ps->flag_is_op_a)
	{
		ps->vis.flag_op_a = 1;
		ps->vis.num_op_a = ps->a->next->n;
	}
	if ((ps->vis.op == SB || ps->vis.op == SS) && ps->flag_is_op_b)
	{
		ps->vis.flag_op_b = 1;
		ps->vis.num_op_b = ps->b->next->n;
	}
}

static void	ch_vis_get_push_or_revrotate_num(t_push_swap *ps)
{
	if ((ps->vis.op == PA || ps->vis.op == RRA || ps->vis.op == RRR)
		&& ps->flag_is_op_a)
	{
		ps->vis.flag_op_a = 1;
		ps->vis.num_op_a = ps->a->n;
	}
	if ((ps->vis.op == PB || ps->vis.op == RRB || ps->vis.op == RRR)
		&& ps->flag_is_op_b)
	{
		ps->vis.flag_op_b = 1;
		ps->vis.num_op_b = ps->b->n;
	}
}

static void	ch_vis_get_rotate_num(t_push_swap *ps)
{
	if ((ps->vis.op == RA || ps->vis.op == RR) && ps->flag_is_op_a)
	{
		ps->vis.flag_op_a = 1;
		ps->vis.num_op_a = ps->a_end->n;
	}
	if ((ps->vis.op == RB || ps->vis.op == RR) && ps->flag_is_op_b)
	{
		ps->vis.flag_op_b = 1;
		ps->vis.num_op_b = ps->b_end->n;
	}
}

void		ch_vis_get_op_num(t_push_swap *ps)
{
	if (ps->vis.op == SA || ps->vis.op == SB || ps->vis.op == SS)
		ch_vis_get_swap_num(ps);
	else if (ps->vis.op == PA || ps->vis.op == PB)
		ch_vis_get_push_or_revrotate_num(ps);
	else if (ps->vis.op == RA || ps->vis.op == RB || ps->vis.op == RR)
		ch_vis_get_rotate_num(ps);
	else if (ps->vis.op == RRA || ps->vis.op == RRB || ps->vis.op == RRR)
		ch_vis_get_push_or_revrotate_num(ps);
}
