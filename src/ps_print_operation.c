/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_operation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:03:43 by prippa            #+#    #+#             */
/*   Updated: 2018/03/05 13:03:45 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_print_operation(int op)
{
	if (op == SA)
		ft_putendl_fd("sa", 0);
	else if (op == SB)
		ft_putendl_fd("sb", 0);
	else if (op == SS)
		ft_putendl_fd("ss", 0);
	else if (op == PA)
		ft_putendl_fd("pa", 0);
	else if (op == PB)
		ft_putendl_fd("pb", 0);
	else if (op == RA)
		ft_putendl_fd("ra", 0);
	else if (op == RB)
		ft_putendl_fd("rb", 0);
	else if (op == RR)
		ft_putendl_fd("rr", 0);
	else if (op == RRA)
		ft_putendl_fd("rra", 0);
	else if (op == RRB)
		ft_putendl_fd("rrb", 0);
	else if (op == RRR)
		ft_putendl_fd("rrr", 0);
}
