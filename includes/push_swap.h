/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:44:11 by prippa            #+#    #+#             */
/*   Updated: 2018/02/28 19:44:13 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef	struct		s_stack
{
	int				n;
	struct s_stack	*next;
}					t_stack;

typedef	struct		s_push_swap
{
	t_stack			*a;
	t_stack			*b;
}					t_push_swap;

void				ps_init(t_push_swap *ps);

void				ps_free(t_push_swap *ps);

void				ps_free_error_exit(t_push_swap *ps);
void				ps_free_exit(t_push_swap *ps);

#endif
