/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_push_pop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:03:59 by prippa            #+#    #+#             */
/*   Updated: 2018/03/05 13:04:01 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_operation_push(t_op **op, int n)
{
	t_op *new;

	if (!(new = (t_op *)malloc(sizeof(t_op))))
		exit(0);
	new->n = n;
	new->next = *op;
	*op = new;
}

void		ps_operation_pop(t_op **op)
{
	t_op *tmp;

	tmp = *op;
	*op = (*op)->next;
	free(tmp);
}

void		ps_stack_push(t_stack **start, t_stack **end, int n)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		exit(0);
	new->n = n;
	new->next = *start;
	new->prev = NULL;
	if (*start)
		(*start)->prev = new;
	else
		*end = new;
	*start = new;
}

void		ps_stack_pop(t_stack **start, t_stack **end)
{
	t_stack *tmp;

	tmp = *start;
	*start = (*start)->next;
	if (*start)
		(*start)->prev = NULL;
	else
		*end = NULL;
	free(tmp);
}
