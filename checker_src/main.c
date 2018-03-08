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

static int	ch_get_bonus_flags(t_push_swap *ps, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "-v"))
			ps->vis.flag_vis = 1;
		else if (!ft_strcmp(argv[i], "-c"))
			ps->vis.flag_col = 1;
		else if (!ft_strcmp(argv[i], "-d"))
			ps->vis.flag_debug = 1;
		else if (!ft_strcmp(argv[i], "-s"))
			ps->vis.flag_size = 1;
		else if (!ft_strcmp(argv[i], "-h"))
			ps->vis.flag_history = 1;
		else
			break ;
		i++;
	}
	return (i);
}

int			main(int argc, char **argv)
{
	t_push_swap ps;
	int 		skip_bonus_flags;

	if (argc > 1)
	{
		ps_init(&ps);
		skip_bonus_flags = ch_get_bonus_flags(&ps, argv);
		if (argv[skip_bonus_flags])
		{
			ps_parser(&ps, argv + skip_bonus_flags);
			if (!ps.vis.flag_debug)
			{
				ch_parser(&ps);
				ch_solve_list_op(&ps);
			}
			else
				ch_parser_debug(&ps);
			if (!ps.b && ps_stack_is_sorted(ps.a))
				ft_putstr("OK\n");
			else
				ft_putstr("KO\n");
			ps_free(&ps);
		}
	}
	return (0);
}
