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

static int 	ch_vis_get_width(t_stack *stk)
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

void		ch_visualize(t_push_swap *ps)
{
	ft_clear();
	ft_putstr("Operation -> ");
	ps_print_operation(ps->vis.op, 1);
	ps->vis.width_a = ch_vis_get_width(ps->a);
	ps->vis.width_b = ch_vis_get_width(ps->b);
	ft_printf("\n%*a  |  b\n", ps->vis.width_a + 1);
	ch_vis_print_stack(ps, ps->a, ps->b);
	read(1, 0, 1);
}
