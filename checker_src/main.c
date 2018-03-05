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

void	print_stack(t_stack *stk, char name)
{
	ft_printf("----------Stack %c----------\n", name);
	while (stk)
	{
		ft_printf("%d\n", stk->n);
		stk = stk->next;
	}
	ft_putendl("---------------------------");
}

int		main(int argc, char **argv)
{
	t_push_swap ps;

	ps_init(&ps);
	if (argc > 1)
	{
		ps_parser(&ps, argv + 1);
		//ch_parser(&ps);
		print_stack(ps.a, 'a');
		ps_op_reverse_rotate(&ps.a);
		print_stack(ps.a, 'a');
		ps_op_rotate(&ps.a);
		print_stack(ps.a, 'a');
	}
	system("leaks checker");
	return (0);
}
