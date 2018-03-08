/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:11:10 by prippa            #+#    #+#             */
/*   Updated: 2018/03/05 13:11:12 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ch_is_operation(char *op)
{
	if (!ft_strcmp(op, "sa"))
		return (SA);
	else if (!ft_strcmp(op, "sb"))
		return (SB);
	else if (!ft_strcmp(op, "ss"))
		return (SS);
	else if (!ft_strcmp(op, "pa"))
		return (PA);
	else if (!ft_strcmp(op, "pb"))
		return (PB);
	else if (!ft_strcmp(op, "ra"))
		return (RA);
	else if (!ft_strcmp(op, "rb"))
		return (RB);
	else if (!ft_strcmp(op, "rr"))
		return (RR);
	else if (!ft_strcmp(op, "rra"))
		return (RRA);
	else if (!ft_strcmp(op, "rrb"))
		return (RRB);
	else if (!ft_strcmp(op, "rrr"))
		return (RRR);
	else
		return (0);
}

void		ch_parser_debug(t_push_swap *ps)
{
	int catch_error;
	int operation;

	ch_vis_debug_dispatcher(ps, 0, NULL);
	while ((catch_error = get_next_line(0, &ps->buf)) > 0)
	{
		if (!ft_strcmp(ps->buf, "exit"))
			return ;
		if ((operation = ch_is_operation(ps->buf)))
			ch_solve_one_op(ps, operation);
		ch_vis_debug_dispatcher(ps, operation, (!operation ? ps->buf : NULL));
		ft_str_free(&ps->buf);
	}
	if (catch_error == -1)
		ps_free_error_exit(ps);
}

void		ch_parser(t_push_swap *ps)
{
	int catch_error;
	int operation;

	while ((catch_error = get_next_line(0, &ps->buf)) > 0)
	{
		if ((operation = ch_is_operation(ps->buf)))
			ps_stack_push(&ps->op, operation);
		else
			ps_free_error_exit(ps);
		ft_str_free(&ps->buf);
	}
	if (catch_error == -1)
		ps_free_error_exit(ps);
	ps_stack_revers(&ps->op);
}
