/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:03:21 by prippa            #+#    #+#             */
/*   Updated: 2018/03/12 21:52:51 by prippa           ###   ########.fr       */
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
	vis->flag_col = 0;
	vis->flag_vis = 0;
	vis->flag_debug = 0;
	vis->flag_size = 0;
	vis->flag_history = 0;
	ft_bzero(vis->h, sizeof(int) * HISTORY_SIZE);
	vis->color = 6;
	vis->count_op = 0;
}

void		ps_init(t_push_swap *ps)
{
	ps->a = NULL;
	ps->b = NULL;
	ps->a_end = NULL;
	ps->b_end = NULL;
	ps->size_a = 0;
	ps->size_b = 0;
	ps->op = NULL;
	ps->buf = NULL;
	ps->arr = NULL;
	ps->flag_is_op_a = 0;
	ps->flag_is_op_b = 0;
	ps_vis_init(&ps->vis);
}
