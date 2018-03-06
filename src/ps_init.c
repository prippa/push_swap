/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:03:21 by prippa            #+#    #+#             */
/*   Updated: 2018/03/05 13:03:24 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_vis_init(t_visualizer *vis)
{
	vis->op = 0;
	vis->flag_op_a = 0;
	vis->flag_op_b = 0;
	vis->num_op_a = 0;
	vis->num_op_b = 0;
	vis->width_a = 0;
	vis->width_b = 0;
	vis->flag_color = 0;
	vis->flag_vis = 0;
}

void		ps_init(t_push_swap *ps)
{
	ps->a = NULL;
	ps->b = NULL;
	ps->op = NULL;
	ps->buf = NULL;
	ps->arr = NULL;
	ps_vis_init(&ps->vis);
}
