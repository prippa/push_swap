/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:20:08 by prippa            #+#    #+#             */
/*   Updated: 2018/03/12 21:52:51 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ch_end(t_push_swap *ps)
{
	if (!ps->b && ps_stack_is_sorted(ps->a))
		ft_printf("%~s\n", F_BOLD_GREEN, "OK");
	else
		ft_printf("%~s\n", F_BOLD_RED, "KO");
}

static void	ch_print_usage(void)
{
	ft_putstr("Usage 🚀🚀🚀 : ./checker [-v -d -s -h -o -t] [integer numbers ...]\n");
	ft_putstr("####################### Flags Manual #######################\n");
	ft_putstr("-v : Visualizes how the stack was sorted when we already have \
the entire list of operations.\n");
	ft_putstr("-d : Debug mode. A mode where you can sort the stack by \
yourself without using push_swap programme.\n");
	ft_putstr("-s : Shows the stacks size (work with -v or -d flag)\n");
	ft_putstr("-h : Shows the last five operations that have already \
been executed (work with -v or -d flag)\n");
	ft_putstr("-o : Shows the sum of operations that have already been \
executed (work with -v or -d flag)\n");
	ft_putstr("-t : Shows the operation counter (work with -v or -d flag)\n");
	ft_putstr("-help : prints usage.\n");
	ft_putstr("############################################################\n");
	exit(0);
}

static int	ch_get_bonus_flags(t_push_swap *ps, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "-v"))
			ps->vis.f[F_VIS] = '1';
		else if (!ft_strcmp(argv[i], "-o"))
			ps->vis.f[F_OP] = '1';
		else if (!ft_strcmp(argv[i], "-d"))
			ps->vis.f[F_DEBUG] = '1';
		else if (!ft_strcmp(argv[i], "-s"))
			ps->vis.f[F_SIZE] = '1';
		else if (!ft_strcmp(argv[i], "-h"))
			ps->vis.f[F_HISTORY] = '1';
		else if (!ft_strcmp(argv[i], "-t"))
			ps->vis.f[F_TOTAL_OP] = '1';
		else if (!ft_strcmp(argv[i], "-help"))
			ch_print_usage();
		else
			break ;
		i++;
	}
	return (i);
}

int			main(int argc, char **argv)
{
	t_push_swap	ps;
	int			skip_bonus_flags;

	if (argc > 1)
	{
		ps_init(&ps);
		skip_bonus_flags = ch_get_bonus_flags(&ps, argv);
		if (!argv[skip_bonus_flags])
			ps_free_error_exit(&ps, "ERROR: No arguments");
		ps_parser(&ps, argv + skip_bonus_flags);
		if (!ps.vis.f[F_DEBUG])
		{
			ch_parser(&ps);
			ch_solve_list_op(&ps);
		}
		else
			ch_parser_debug(&ps);
		ch_end(&ps);
		ps_free(&ps);
	}
	else
		ch_print_usage();
	return (0);
}
