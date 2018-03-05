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

void	ps_op_swap(t_stack **stk)
{
	int tmp;

	if (!(*stk) || !(*stk)->next)
		return ;
	tmp = (*stk)->n;
	(*stk)->n = (*stk)->next->n;
	(*stk)->next->n = tmp;
}

void	ps_op_swap_duo(t_stack **a, t_stack **b)
{
	ps_op_swap(a);
	ps_op_swap(b);
}
