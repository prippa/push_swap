/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstruppercase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:58:26 by prippa            #+#    #+#             */
/*   Updated: 2017/11/09 15:05:05 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isstruppercase(const char *str)
{
	size_t i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			if (ft_isalpha(str[i]) && !(ft_isuppercase(str[i])))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
