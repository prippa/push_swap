/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_vis_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:58:00 by prippa            #+#    #+#             */
/*   Updated: 2018/03/20 11:58:03 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ch_identify_color(int op)
{
	if (op == SA || op == SB || op == SS)
		return (F_BOLD_CYAN);
	else if (op == PA || op == PB)
		return (F_BOLD_BLUE);
	else if (op == RA || op == RB || op == RR)
		return (F_BOLD_MAGENTA);
	else if (op == RRA || op == RRB || op == RRR)
		return (F_BOLD_YELLOW);
	return (F_WHITE);
}

int		ch_vis_get_width(t_stack *stk)
{
	int width;
	int tmp;

	if (!stk)
		return (1);
	width = ft_nbrlen(stk->n);
	stk = stk->next;
	while (stk)
	{
		tmp = ft_nbrlen(stk->n);
		if (width < tmp)
			width = tmp;
		stk = stk->next;
	}
	return (width);
}

void	ch_vis_pull_history(int h[HISTORY_SIZE], int op)
{
	int pull;
	int tmp;
	int i;

	i = 0;
	pull = op;
	while (i < HISTORY_SIZE)
	{
		tmp = h[i];
		h[i] = pull;
		pull = tmp;
		i++;
	}
}
