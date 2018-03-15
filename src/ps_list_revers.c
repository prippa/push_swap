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

void	ps_operation_revers(t_op **op)
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

void	ps_stack_revers(t_stack **start, t_stack **end)
{
	t_stack *current;
	t_stack *prev;
	t_stack *next;
	t_stack *current_prev;
	t_stack *prev_prev;
	t_stack *next_prev;

	prev = NULL;
	prev_prev = NULL;
	current = *start;
	current_prev = *end;
	while (current)
	{
		next = current->next;
		next_prev = current_prev->prev;
		current->next = prev;
		current_prev->prev = prev_prev;
		prev = current;
		prev_prev = current_prev;
		current = next;
		current_prev = next_prev;
	}
	*start = prev;
	*end = prev_prev;
}
