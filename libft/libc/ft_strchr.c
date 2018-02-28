/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:43:33 by prippa            #+#    #+#             */
/*   Updated: 2017/10/31 14:43:34 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	str = (char*)s;
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (&str[i]);
	return (NULL);
}
