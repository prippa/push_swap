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

void	ps_print_operation(int op, int fd)
{
	if (op == SA)
		ft_putendl_fd("sa", fd);
	else if (op == SB)
		ft_putendl_fd("sb", fd);
	else if (op == SS)
		ft_putendl_fd("ss", fd);
	else if (op == PA)
		ft_putendl_fd("pa", fd);
	else if (op == PB)
		ft_putendl_fd("pb", fd);
	else if (op == RA)
		ft_putendl_fd("ra", fd);
	else if (op == RB)
		ft_putendl_fd("rb", fd);
	else if (op == RR)
		ft_putendl_fd("rr", fd);
	else if (op == RRA)
		ft_putendl_fd("rra", fd);
	else if (op == RRB)
		ft_putendl_fd("rrb", fd);
	else if (op == RRR)
		ft_putendl_fd("rrr", fd);
}
