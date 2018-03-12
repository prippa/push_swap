/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_trash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:04:20 by prippa            #+#    #+#             */
/*   Updated: 2018/03/05 13:04:22 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ps_free_error_exit(t_push_swap *ps)
{
	ft_putstr_fd("Error\n", 2);
	ps_free(ps);
	system("leaks -quiet push_swap");
	exit(0);
}
