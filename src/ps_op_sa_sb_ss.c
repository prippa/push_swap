/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_sa_sb_ss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:36:27 by prippa            #+#    #+#             */
/*   Updated: 2018/03/05 13:36:30 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_op_swap(t_stack **stk)
{
	int tmp;

	if (!(*stk) || !(*stk)->next)
		return (0);
	tmp = (*stk)->n;
	(*stk)->n = (*stk)->next->n;
	(*stk)->next->n = tmp;
	return (1);
}

void	ps_op_swap_duo(t_push_swap *ps)
{
	ps->flag_is_op_a = ps_op_swap(&ps->a);
	ps->flag_is_op_b = ps_op_swap(&ps->b);
}
