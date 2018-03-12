/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:24:12 by prippa            #+#    #+#             */
/*   Updated: 2018/03/12 13:24:14 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_algorithm(t_push_swap *ps)
{
	ft_printf("%d\n", ps->size_a);
	ft_printf("%d\n", ps->size_b);
	ps_op_push(&ps->a, &ps->b);
	ps_op_push(&ps->a, &ps->b);
	ft_printf("%d\n", ps->size_a);
	ft_printf("%d\n", ps->size_b);
}
