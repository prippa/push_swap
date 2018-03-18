/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_visualize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:47:49 by prippa            #+#    #+#             */
/*   Updated: 2018/03/12 21:52:51 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ch_vis_print_total_op_done(t_push_swap *ps)
{
	ft_putchar('\n');
	ft_printf("Swap          :  %~s = (%d)  %~s = (%d)  %~s = (%d)\n",
	ch_identify_color(SA), "sa", ps->vis.o[SA - 1],
	ch_identify_color(SB), "sb", ps->vis.o[SB - 1],
	ch_identify_color(SS), "ss", ps->vis.o[SS - 1]);
	ft_printf("Push          :  %~s = (%d)  %~s = (%d)\n",
	ch_identify_color(PA), "pa", ps->vis.o[PA - 1],
	ch_identify_color(PB), "pb", ps->vis.o[PB - 1]);
	ft_printf("Rotate        :  %~s = (%d)  %~s = (%d)  %~s = (%d)\n",
	ch_identify_color(RA), "ra", ps->vis.o[RA - 1],
	ch_identify_color(RB), "rb", ps->vis.o[RB - 1],
	ch_identify_color(RR), "rr", ps->vis.o[RR - 1]);
	ft_printf("Revers Rotate : %~s = (%d) %~s = (%d) %~s = (%d)\n",
	ch_identify_color(RRA), "rra", ps->vis.o[RRA - 1],
	ch_identify_color(RRB), "rrb", ps->vis.o[RRB - 1],
	ch_identify_color(RRR), "rrr", ps->vis.o[RRR - 1]);
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
		ft_printf("{%~s}", ch_identify_color(h[i]), ps_get_operation(h[i]));
		if ((i - 1) >= 0)
			ft_putstr(" <- ");
	}
	ft_putstr(" <- last\n");
}

void		ch_visualize(t_push_swap *ps)
{
	ps->vis.color = ch_identify_color(ps->vis.op);
	if (ps->vis.op)
		ft_printf("\nOperation -> %~s\n",
		ch_identify_color(ps->vis.op), ps_get_operation(ps->vis.op));
	ps->vis.width_a = ch_vis_get_width(ps->a);
	ps->vis.width_b = ch_vis_get_width(ps->b);
	ft_printf("\n%*a  -  b\n", ps->vis.width_a + 1);
	ch_vis_print_stack(ps, ps->a, ps->b);
	if (ps->vis.f[F_SIZE])
		ft_printf("%*d  -  %d\n", ps->vis.width_a + 1, ps->size_a, ps->size_b);
	if (ps->vis.f[F_HISTORY])
		ch_vis_print_history(ps);
	if (ps->vis.f[F_OP])
		ch_vis_print_total_op_done(ps);
	if (ps->vis.f[F_TOTAL_OP])
		ft_printf("\ntotal operations: (%d)\n", ps->vis.count_op);
	if (!ps->vis.f[F_DEBUG])
		read(1, 0, 1);
}
