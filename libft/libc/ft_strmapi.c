/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:44:21 by prippa            #+#    #+#             */
/*   Updated: 2017/11/05 13:23:23 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*fresh;

	if (!s || !f)
		return (NULL);
	if ((fresh = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		fresh[i] = (*f)(i, s[i]);
		i++;
	}
	return (fresh);
}
