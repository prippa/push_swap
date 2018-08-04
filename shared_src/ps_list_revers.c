/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_revers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:04:10 by prippa            #+#    #+#             */
/*   Updated: 2018/03/05 13:04:11 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_operation_revers(t_op **op)
{
	t_op *prev;
	t_op *current;
	t_op *next;

	prev = NULL;
	current = *op;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*op = prev;
}

static void	ps_stack_prev_revers(t_stack **end)
{
	t_stack *current;
	t_stack *prev;
	t_stack *next;

	prev = NULL;
	current = *end;
	while (current)
	{
		next = current->prev;
		current->prev = prev;
		prev = current;
		current = next;
	}
	*end = prev;
}

void		ps_stack_revers(t_stack **start, t_stack **end)
{
	t_stack *current;
	t_stack *prev;
	t_stack *next;

	ps_stack_prev_revers(end);
	prev = NULL;
	current = *start;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*start = prev;
}
