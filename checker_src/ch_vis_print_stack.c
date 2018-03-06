/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_vis_print_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:15:32 by prippa            #+#    #+#             */
/*   Updated: 2018/03/06 19:15:38 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ch_vis_print_a_b(t_push_swap *ps, t_stack *a, t_stack *b)
{
	if (ps->vis.flag_col && ((ps->vis.flag_op_a && ps->vis.num_op_a == a->n)
			|| (ps->vis.flag_op_b && ps->vis.num_op_b == b->n)))
	{
		if ((ps->vis.flag_op_a && ps->vis.num_op_a == a->n)
			&& (ps->vis.flag_op_b && ps->vis.num_op_b == b->n))
			ft_printf("[%~*d] | [%~*d]\n",
					  ps->vis.color, ps->vis.width_a, a->n,
					  ps->vis.color, ps->vis.width_b, b->n);
		else if (ps->vis.flag_op_a && ps->vis.num_op_a == a->n)
			ft_printf("[%~*d] | [%*d]\n",
					  ps->vis.color, ps->vis.width_a, a->n,
					  ps->vis.width_b, b->n);
		else if (ps->vis.flag_op_b && ps->vis.num_op_b == b->n)
			ft_printf("[%*d] | [%~*d]\n",
					  ps->vis.width_a, a->n,
					  ps->vis.color, ps->vis.width_b, b->n);
	}
	else
		ft_printf("[%*d] | [%*d]\n",
				  ps->vis.width_a, a->n,
				  ps->vis.width_b, b->n);
}

static void	ch_vis_print_a(t_push_swap *ps, t_stack *a)
{
	if (ps->vis.flag_col && ps->vis.flag_op_a && ps->vis.num_op_a == a->n)
		ft_printf("[%~*d] | \n",
				  ps->vis.color, ps->vis.width_a, a->n);
	else
		ft_printf("[%*d] | \n",
				  ps->vis.width_a, a->n);
}

static void	ch_vis_print_b(t_push_swap *ps, t_stack *b)
{
	if (ps->vis.flag_col && ps->vis.flag_op_b && ps->vis.num_op_b == b->n)
		ft_printf("%*c | [%~*d]\n",
				  ps->vis.width_a + 2, ' ',
				  ps->vis.color, ps->vis.width_b, b->n);
	else
		ft_printf("%*c | [%*d]\n",
				  ps->vis.width_a + 2, ' ',
				  ps->vis.width_b, b->n);
}

void		ch_vis_print_stack(t_push_swap *ps, t_stack *a, t_stack *b)
{
	while (42)
	{
		if (!a && !b)
			return ;
		if (a && b)
			ch_vis_print_a_b(ps, a, b);
		else if (a && !b)
			ch_vis_print_a(ps, a);
		else if (!a && b)
			ch_vis_print_b(ps, b);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
}
