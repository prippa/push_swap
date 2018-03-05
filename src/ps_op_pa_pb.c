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

void	ps_op_push(t_stack **take, t_stack **put)
{
	int tmp;

	if (!(*take))
		return ;
	tmp = (*take)->n;
	ps_stack_pop(take);
	ps_stack_push(put, tmp);
}
