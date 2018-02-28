/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tostruppercase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:13:31 by prippa            #+#    #+#             */
/*   Updated: 2017/11/09 16:15:20 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tostruppercase(const char *str)
{
	size_t	i;
	char	*s;

	if (str)
	{
		s = ft_strdup(str);
		i = 0;
		while (s[i])
		{
			if (ft_isalpha(s[i]) && !(ft_isuppercase(s[i])))
				s[i] = ft_toupper(s[i]);
			i++;
		}
		return (s);
	}
	return (NULL);
}
