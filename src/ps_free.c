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

static void	ps_operation_free(t_op **op)
{
	while (*op)
		ps_operation_pop(op);
}

static void	ps_stack_free(t_stack **start, t_stack **end)
{
	while (*start)
		ps_stack_pop(start, end);
}

void		ps_free(t_push_swap *ps)
{
	ps_stack_free(&ps->a, &ps->a_end);
	ps_stack_free(&ps->b, &ps->b_end);
	ps_operation_free(&ps->op);
	ft_str_free(&ps->buf);
	ft_arr_free(&ps->arr);
}
