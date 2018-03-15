/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:24:12 by prippa            #+#    #+#             */
/*   Updated: 2018/03/13 20:01:13 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_get_position_of_min_number(t_push_swap *ps)
{
	int		global_pos;
	int		pos;
	int		min;
	t_stack	*a;

	global_pos = 2;
	pos = 1;
	min = ps->a->n;
	a = ps->a->next;
	while (a)
	{
		if (a->n < min)
		{
			min = a->n;
			pos = global_pos;
		}
		global_pos++;
		a = a->next;
	}
	return (pos);
}

static int	ps_base_simple_logic(t_push_swap *ps)
{
	int pos;

	pos = ps_get_position_of_min_number(ps);
	if (pos == 1)
		return (PB);
	else if (pos == 2)
		return (SA);
	else if (((ps->size_a / 2) + 1) == pos)
		return (RA);
	else if ((ps->size_a / 2) >= pos)
		return (RA);
	else if ((ps->size_a / 2) < pos)
		return (RRA);
	return (0);
}

void		ps_algorithm(t_push_swap *ps)
{
	int sorted;
	int op;

	while (!(sorted = ps_stack_is_sorted(ps->a)) || ps->b)
	{
		if (sorted)
			op = PA;
		else
			op = ps_base_simple_logic(ps);
		ps_make_operation(ps, op);
		ps_operation_push(&ps->op, op);
	}
}
