/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:57:45 by prippa            #+#    #+#             */
/*   Updated: 2017/11/06 13:57:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*fresh;
	size_t	end;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	end = ft_strlen(s) - 1;
	while (ft_isspace(s[end]))
		end--;
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if ((++end) - i && end > i)
	{
		if ((fresh = ft_strnew(end - i)) == NULL)
			return (NULL);
		j = 0;
		while (i < end)
			fresh[j++] = s[i++];
		fresh[j] = '\0';
	}
	else
		fresh = ft_strdup("");
	return (fresh);
}
