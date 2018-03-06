/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:20:08 by prippa            #+#    #+#             */
/*   Updated: 2018/03/01 18:20:10 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ch_solve(t_push_swap *ps)
{
	t_stack *tmp;

	tmp = ps->op;
	while (tmp)
	{
		ps->flag_is_op_a = 0;
		ps->flag_is_op_b = 0;
		ps_make_operation(ps, tmp->n);
		if (ps->vis.flag_vis || ps->vis.flag_col)
		{
			ps->vis.op = tmp->n;
			ch_vis_get_op_num(ps);
			ch_visualize(ps);
			ps->vis.flag_op_a = 0;
			ps->vis.flag_op_b = 0;
		}
		tmp = tmp->next;
	}
}

static int	ch_get_bonus_flags(t_push_swap *ps, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] != '-')
			break ;
		if (!ft_strcmp(argv[i], "-v"))
			ps->vis.flag_vis = 1;
		else if (!ft_strcmp(argv[i], "-c"))
			ps->vis.flag_col = 1;
		i++;
	}
	return (i);
}

int			main(int argc, char **argv)
{
	t_push_swap ps;

	if (argc > 1)
	{
		ps_init(&ps);
		ps_parser(&ps, argv + ch_get_bonus_flags(&ps, argv));
		ch_parser(&ps);
		ch_solve(&ps);
		if (!ps.b && ps_stack_is_sorted(ps.a))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		ps_free(&ps);
	}
	return (0);
}
