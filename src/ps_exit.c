/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_trash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:04:20 by prippa            #+#    #+#             */
/*   Updated: 2018/03/13 13:33:49 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_free_exit(t_push_swap *ps, char *str)
{
	ft_putendl(str);
	ps_free(ps);
	exit(0);
}

void	ps_free_error_exit(t_push_swap *ps, char *str)
{
	ft_putendl_fd(str, 2);
	ps_free(ps);
	exit(-1);
}

void	ps_free_perror_exit(t_push_swap *ps, char *message)
{
	perror(message);
	ps_free(ps);
	exit(-2);
}
