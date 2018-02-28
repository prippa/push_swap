/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:14:55 by prippa            #+#    #+#             */
/*   Updated: 2017/11/09 14:22:05 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isstrdigit(const char *str)
{
	size_t i;

	if (str)
	{
		i = 0;
		if ((str[i] == '-' || str[i] == '+') && str[i + 1])
			i++;
		while (str[i])
		{
			if (!(ft_isdigit(str[i])))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
