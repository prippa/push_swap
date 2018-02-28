/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrlowercase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:21:46 by prippa            #+#    #+#             */
/*   Updated: 2017/11/09 15:23:30 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isstrlowercase(const char *str)
{
	size_t i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			if (ft_isalpha(str[i]) && !(ft_islowercase(str[i])))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
