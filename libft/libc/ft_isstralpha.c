/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstralpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:23:47 by prippa            #+#    #+#             */
/*   Updated: 2017/11/09 14:28:40 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isstralpha(const char *str)
{
	size_t i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			if (!(ft_isalpha(str[i])))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
