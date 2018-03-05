/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_rra_rrb_rrr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:39:02 by prippa            #+#    #+#             */
/*   Updated: 2018/03/05 13:39:04 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_op_reverse_rotate(t_stack **stk)
{
	int		up;
	int		pull;
	int		last;
	t_stack	*tmp;

	if (!(*stk))
		return ;
	tmp = *stk;
	last = tmp->n;
	pull = tmp->n;
	while (tmp)
	{
		if (!tmp->next)
			last = tmp->n;
		up = tmp->n;
		tmp->n = pull;
		pull = up;
		tmp = tmp->next;
	}
	(*stk)->n = last;
}

void	ps_op_reverse_rotate_duo(t_stack **a, t_stack **b)
{
	ps_op_reverse_rotate(a);
	ps_op_reverse_rotate(b);
}
