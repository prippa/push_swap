/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quicksort_algorithm.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:23:40 by prippa            #+#    #+#             */
/*   Updated: 2018/03/16 15:23:42 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_get_right_radius(double size_a)
{
	int		size;
	double	radius;

	size = 100;
	radius = 3;
	while (size < size_a)
	{
		size *= 2.24;
		radius++;
	}
	return (radius);
}

void		ps_quick_sort(t_push_swap *ps)
{
	ps->search_radius = ps_get_right_radius((double)ps->size_a);
	if (ps_sort_first_stage(ps))
		return ;
	ps_sort_second_stage(ps);
}
