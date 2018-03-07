/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_visualize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:47:49 by prippa            #+#    #+#             */
/*   Updated: 2018/03/06 15:47:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ch_vis_get_width(t_stack *stk)
{
	int width;
	int tmp;

	if (!stk)
		return (1);
	width = ft_nbrlen(stk->n);
	stk = stk->next;
	while (stk)
	{
		tmp = ft_nbrlen(stk->n);
		if (width < tmp)
			width = tmp;
		stk = stk->next;
	}
	return (width);
}

static void	ch_identify_color(t_visualizer *vis)
{
	if (vis->op == SA || vis->op == SB || vis->op == SS)
		vis->color = F_CYAN;
	else if (vis->op == PA || vis->op == PB)
		vis->color = F_BLUE;
	else if (vis->op == RA || vis->op == RB || vis->op == RR)
		vis->color = F_RED;
	else if (vis->op == RRA || vis->op == RRB || vis->op == RRR)
		vis->color = F_YELLOW;
}

void		ch_visualize(t_push_swap *ps)
{
	ft_clear();
	ch_identify_color(&ps->vis);
	ft_putstr("Operation -> ");
	ps_print_operation(ps->vis.op, 1);
	ps->vis.width_a = ch_vis_get_width(ps->a);
	ps->vis.width_b = ch_vis_get_width(ps->b);
	ft_printf("\n%*a  |  b\n", ps->vis.width_a + 1);
	ch_vis_print_stack(ps, ps->a, ps->b);
	read(1, 0, 1);
}
