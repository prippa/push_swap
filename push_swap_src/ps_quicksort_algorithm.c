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

void		ps_quick_sort(t_push_swap *ps)
{
	ps->search_radius = (ps->size_a > 200 ? 7 : 3);
	if (ps_sort_first_stage(ps))
		return ;
	ps_sort_second_stage(ps);
}
