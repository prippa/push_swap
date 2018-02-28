/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:28:28 by prippa            #+#    #+#             */
/*   Updated: 2017/10/30 14:28:38 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char*)dst;
	ptr2 = (char*)src;
	i = 0;
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		if (ptr2[i] == c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
