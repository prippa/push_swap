/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:03:32 by prippa            #+#    #+#             */
/*   Updated: 2018/03/05 13:03:34 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_duplicate_num_valid(t_push_swap *ps, int n)
{
	t_stack *stk;

	stk = ps->a;
	while (stk)
	{
		if (stk->n == n)
			ps_free_error_exit(ps, "ERROR: duplicate number");
		stk = stk->next;
	}
}

static void	ps_get_valid_number(t_push_swap *ps, char *arg)
{
	long long int	num;
	int				i;

	ps->arr = ft_strsplit(arg, ' ');
	i = 0;
	while (ps->arr[i])
	{
		if (ft_isstrdigit(ps->arr[i]))
		{
			num = ft_atoi_max(ps->arr[i]);
			if (num > MAXINT || num < MININT)
				ps_free_error_exit(ps,
					"ERROR: Underflow or Overflow on a number (int)");
			ps_duplicate_num_valid(ps, (int)num);
			ps_stack_push(&ps->a, &ps->a_end, (int)num);
			ps->size_a++;
		}
		else
			ps_free_error_exit(ps, "ERROR: argument is not a number");
		i++;
	}
	ft_arr_free(&ps->arr);
}

void		ps_parser(t_push_swap *ps, char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		ps_get_valid_number(ps, argv[i]);
		i++;
	}
	if (!ps->a)
		ps_free_error_exit(ps, "ERROR: No arguments");
	ps_stack_revers(&ps->a, &ps->a_end);
}
