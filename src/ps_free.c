/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:03:10 by prippa            #+#    #+#             */
/*   Updated: 2018/03/05 13:03:12 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_stack_free(t_stack **stack)
{
	while (*stack)
	{
		free(*stack);
		*stack = (*stack)->next;
	}
}

void		ps_free(t_push_swap *ps)
{
	if (ps->a)
		ps_stack_free(&ps->a);
	if (ps->b)
		ps_stack_free(&ps->b);
	if (ps->op)
		ps_stack_free(&ps->op);
	if (ps->buf)
		ft_str_free(&ps->buf);
	if (ps->arr)
		ft_arr_free(&ps->arr);
}
