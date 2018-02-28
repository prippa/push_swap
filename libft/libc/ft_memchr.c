/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:50:26 by prippa            #+#    #+#             */
/*   Updated: 2017/10/30 17:50:31 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	tmp;
	size_t			i;

	str = (unsigned char*)s;
	tmp = (unsigned char)c;
	i = 0;
	while (n--)
	{
		if (str[i] == tmp)
			return (str + i);
		i++;
	}
	return (NULL);
}
