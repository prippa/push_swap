/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:37:50 by prippa            #+#    #+#             */
/*   Updated: 2017/10/31 15:37:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*cpy;
	char	*buf;
	size_t	length;

	cpy = (char *)haystack;
	buf = (char *)(haystack + len);
	length = ft_strlen(needle);
	if (length == 0)
		return ((char *)haystack);
	while ((cpy = ft_strchr(cpy, *needle)) && cpy <= buf)
	{
		if ((cpy + length <= buf) && !ft_strncmp(cpy, needle, length))
			return (cpy);
		cpy++;
	}
	return (NULL);
}
