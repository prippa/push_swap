/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:58:36 by prippa            #+#    #+#             */
/*   Updated: 2017/11/20 18:01:57 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MAX_LONG_LONG 9223372036854775807

int		ft_atoi(const char *str)
{
	unsigned long		i;
	unsigned long long	res;
	int					sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = (unsigned long long)(res * 10 + str[i] - '0');
		if (res > (long long)MAX_LONG_LONG && sign == 1)
			return (-1);
		if (res > (long long)MAX_LONG_LONG && sign == -1)
			return (0);
		i++;
	}
	return ((int)(res * sign));
}
