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

//void	print_stack(t_stack *stk, char name)
//{
//	ft_printf("----------Stack %c----------\n", name);
//	while (stk)
//	{
//		ft_printf("%d\n", stk->n);
//		stk = stk->next;
//	}
//	ft_putendl("---------------------------");
//}

static void	ch_solve(t_push_swap *ps)
{
	t_stack *tmp;

	tmp = ps->op;
	while (tmp)
	{
		ps_make_operation(ps, tmp->n);
		tmp = tmp->next;
	}
}

int			main(int argc, char **argv)
{
	t_push_swap ps;

	if (argc > 1)
	{
		ps_init(&ps);
		ps_parser(&ps, argv + 1);
		ch_parser(&ps);
		ch_solve(&ps);
		if (ps_stack_is_sorted(ps.a))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		ps_free(&ps);
	}
	return (0);
}
