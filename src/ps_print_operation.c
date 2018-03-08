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

char	*ps_get_operation(int op)
{
	if (op == SA)
		return ("sa");
	else if (op == SB)
		return ("sb");
	else if (op == SS)
		return ("ss");
	else if (op == PA)
		return ("pa");
	else if (op == PB)
		return ("pb");
	else if (op == RA)
		return ("ra");
	else if (op == RB)
		return ("rb");
	else if (op == RR)
		return ("rr");
	else if (op == RRA)
		return ("rra");
	else if (op == RRB)
		return ("rrb");
	else if (op == RRR)
		return ("rrr");
	return ("");
}
