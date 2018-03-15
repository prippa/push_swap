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
	ft_putstr("\t\tYou are in debug mode.\n\t\tTo leave write \"exit\"\n");
	ps->vis.op = op;
	ch_vis_get_op_num(ps);
	ch_visualize(ps);
	if (cm)
		ft_printf("\n%s%s%s command not found: %s\n",
		(ps->vis.flag_col ? BOLD_RED : COLOR_RESET), "Error:", COLOR_RESET, cm);
	ft_putstr("->");
	ps->vis.flag_op_b = 0;
	ps->vis.flag_op_a = 0;
}

void	ch_vis_dispatcher(t_push_swap *ps, int op)
{
	if (ps->vis.flag_vis || ps->vis.flag_col)
	{
		ft_clear();
		ps->vis.op = op;
		ch_vis_get_op_num(ps);
		ch_visualize(ps);
		ps->vis.flag_op_b = 0;
		ps->vis.flag_op_a = 0;
	}
}
