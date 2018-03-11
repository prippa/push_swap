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

static int	ch_identify_color(int op)
{
	if (op == SA || op == SB || op == SS)
		return (F_BOLD_CYAN);
	else if (op == PA || op == PB)
		return (F_BOLD_BLUE);
	else if (op == RA || op == RB || op == RR)
		return (F_BOLD_RED);
	else if (op == RRA || op == RRB || op == RRR)
		return (F_BOLD_YELLOW);
	return (F_WHITE);
}

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

static void	ch_vis_pull_history(int h[HISTORY_SIZE], int op)
{
	int pull;
	int tmp;
	int i;

	i = 0;
	pull = op;
	while (i < HISTORY_SIZE)
	{
		tmp = h[i];
		h[i] = pull;
		pull = tmp;
		i++;
	}
}

static void	ch_vis_print_history(t_push_swap *ps)
{
	int	*h;
	int	i;

	if (ps->vis.op)
		ch_vis_pull_history(ps->vis.h, ps->vis.op);
	ft_printf("\nLast %d operation commands:\n", HISTORY_SIZE);
	h = ps->vis.h;
	i = HISTORY_SIZE;
	while (--i >= 0)
	{
		if (ps->vis.flag_col)
			ft_printf("{%~s}", ch_identify_color(h[i]), ps_get_operation(h[i]));
		else
			ft_printf("{%s}", ps_get_operation(h[i]));
		if ((i - 1) >= 0)
			ft_putstr(" <- ");
	}
	ft_putstr(" <- last\n");
}

void		ch_visualize(t_push_swap *ps)
{
	if (ps->vis.flag_col)
		ps->vis.color = ch_identify_color(ps->vis.op);
	if (ps->vis.op)
		ft_printf("\nOperation -> %s\n", ps_get_operation(ps->vis.op));
	ps->vis.width_a = ch_vis_get_width(ps->a);
	ps->vis.width_b = ch_vis_get_width(ps->b);
	ft_printf("\n%*a  -  b\n", ps->vis.width_a + 1);
	ch_vis_print_stack(ps, ps->a, ps->b);
	if (ps->vis.flag_size)
		ft_printf("%*d  -  %d\n", ps->vis.width_a + 1, ps->size_a, ps->size_b);
	if (ps->vis.flag_history)
		ch_vis_print_history(ps);
	if (!ps->vis.flag_debug)
		read(1, 0, 1);
}
