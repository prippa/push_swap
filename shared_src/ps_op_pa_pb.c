/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_pa_pb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:38:26 by prippa            #+#    #+#             */
/*   Updated: 2018/03/05 13:38:29 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_op_push(t_stack **take_start, t_stack **take_end,
					t_stack **put_start, t_stack **put_end)
{
	if (!(*take_start))
		return (0);
	ps_stack_push(put_start, put_end, (*take_start)->n);
	ps_stack_pop(take_start, take_end);
	return (1);
}
