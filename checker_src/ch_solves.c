/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_solves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:45:31 by prippa            #+#    #+#             */
/*   Updated: 2018/03/15 14:45:33 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ch_calibrate_op(t_push_swap *ps, int op)
{
	if (op == SA)
		ps->vis.o[SA - 1]++;
	else if (op == SB)
		ps->vis.o[SB - 1]++;
	else if (op == SS)
		ps->vis.o[SS - 1]++;
	else if (op == PA)
		ps->vis.o[PA - 1]++;
	else if (op == PB)
		ps->vis.o[PB - 1]++;
	else if (op == RA)
		ps->vis.o[RA - 1]++;
	else if (op == RB)
		ps->vis.o[RB - 1]++;
	else if (op == RR)
		ps->vis.o[RR - 1]++;
	else if (op == RRA)
		ps->vis.o[RRA - 1]++;
	else if (op == RRB)
		ps->vis.o[RRB - 1]++;
	else if (op == RRR)
		ps->vis.o[RRR - 1]++;
}

void	ch_solve_list_op(t_push_swap *ps)
{
	t_op *tmp;

	tmp = ps->op;
	while (tmp)
	{
		ps->flag_is_op_a = 0;
		ps->flag_is_op_b = 0;
		ps_make_operation(ps, tmp->n);
		ps->vis.count_op++;
		ch_calibrate_op(ps, tmp->n);
		ch_vis_dispatcher(ps, tmp->n);
		tmp = tmp->next;
	}
}

void	ch_solve_one_op(t_push_swap *ps, int op)
{
	ps->flag_is_op_a = 0;
	ps->flag_is_op_b = 0;
	ps_make_operation(ps, op);
	ps->vis.count_op++;
	ch_calibrate_op(ps, op);
}
