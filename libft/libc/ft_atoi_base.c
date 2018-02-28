/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:28:13 by prippa            #+#    #+#             */
/*   Updated: 2018/02/13 12:28:15 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_base(const char c)
{
	int		tmp;

	if (c >= '0' && c <= '9')
		tmp = c - '0';
	else if (c >= 'a' && c <= 'z')
		tmp = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		tmp = c - 'A' + 10;
	else
		tmp = -1;
	return (tmp);
}

int			ft_atoi_base(const char *str, int base)
{
	int		sign;
	int		res;
	int		current;

	res = 0;
	sign = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	current = ft_base(*str);
	while (current >= 0 && current < base)
	{
		res = res * base + current;
		str++;
		current = ft_base(*str);
	}
	return (sign ? -res : res);
}
