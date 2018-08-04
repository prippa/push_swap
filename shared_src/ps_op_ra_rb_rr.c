/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_ra_rb_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:38:43 by prippa            #+#    #+#             */
/*   Updated: 2018/03/05 13:38:45 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_op_rotate(t_stack **stk)
{
	int		first;
	t_stack	*tmp;

	if (!(*stk) || !((*stk)->next))
		return (0);
	tmp = *stk;
	first = tmp->n;
	while (tmp->next)
	{
		tmp->n = tmp->next->n;
		tmp = tmp->next;
	}
	tmp->n = first;
	return (1);
}

void	ps_op_rotate_duo(t_push_swap *ps)
{
	ps->flag_is_op_a = ps_op_rotate(&ps->a);
	ps->flag_is_op_b = ps_op_rotate(&ps->b);
}
