/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_vis_dispatcher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:45:46 by prippa            #+#    #+#             */
/*   Updated: 2018/03/15 14:45:48 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ch_vis_debug_dispatcher(t_push_swap *ps, int op, char *cm)
{
	ft_clear();
	ft_putstr("\t\tYou are in debug mode.\n\t\t");
	ft_putstr("To leave write \"exit\" command\n");
	ps->vis.op = op;
	ch_vis_get_op_num(ps);
	ch_visualize(ps);
	if (cm)
		ft_printf("\n%s%s%s command not found: %s\n",
			BOLD_RED, "Error:", COLOR_RESET, cm);
	ft_printf("\n%~s", F_BOLD_WHITE, "->");
	ps->vis.flag_op_b = 0;
	ps->vis.flag_op_a = 0;
}

void	ch_vis_dispatcher(t_push_swap *ps, int op)
{
	if (ps->vis.f[F_VIS])
	{
		ft_clear();
		ft_putstr("\t\tYou are in visualize mode.\n\t\t");
		ft_putstr("To see next step press \"Enter\"\n");
		ps->vis.op = op;
		ch_vis_get_op_num(ps);
		ch_visualize(ps);
		ps->vis.flag_op_b = 0;
		ps->vis.flag_op_a = 0;
	}
}
