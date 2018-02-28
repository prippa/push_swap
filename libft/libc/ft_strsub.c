/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:55:18 by prippa            #+#    #+#             */
/*   Updated: 2017/11/06 13:55:21 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		length;
	char		*fresh;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	fresh = NULL;
	if ((start + len) <= length)
	{
		fresh = ft_strnew(len);
		if (fresh)
		{
			fresh = ft_strncpy(fresh, s + start, len);
			fresh[len] = '\0';
		}
	}
	return (fresh);
}
