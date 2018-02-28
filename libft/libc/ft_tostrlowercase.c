/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tostrlowercase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:24:42 by prippa            #+#    #+#             */
/*   Updated: 2017/11/09 15:25:26 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tostrlowercase(const char *str)
{
	size_t	i;
	char	*s;

	if (str)
	{
		s = ft_strdup(str);
		i = 0;
		while (s[i])
		{
			if (ft_isalpha(s[i]) && !(ft_islowercase(s[i])))
				s[i] = ft_tolower(s[i]);
			i++;
		}
		return (s);
	}
	return (NULL);
}
