/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_is_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:45:53 by prippa            #+#    #+#             */
/*   Updated: 2018/03/06 15:46:21 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_stack_is_sorted(t_stack *stk)
{
	int tmp;

	if (!stk)
		return (1);
	tmp = stk->n;
	stk = stk->next;
	while (stk)
	{
		if (tmp > stk->n)
			return (0);
		tmp = stk->n;
		stk = stk->next;
	}
	return (1);
}
