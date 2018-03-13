/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:44:27 by prippa            #+#    #+#             */
/*   Updated: 2018/03/13 13:36:09 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_print_list_operations(t_push_swap *ps)
{
	t_stack *tmp;
	
	ps_stack_revers(&ps->op);
	tmp = ps->op;
	while (tmp)
	{
		ft_printf("%s\n", ps_get_operation(tmp->n));
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
		ps_algorithm(&ps);
		ps_print_list_operations(&ps);
		ps_free(&ps);
	}
	return (0);
}
