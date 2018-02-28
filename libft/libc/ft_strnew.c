/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:43:39 by prippa            #+#    #+#             */
/*   Updated: 2017/11/03 16:43:40 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *fresh;

	fresh = (char*)malloc(sizeof(char) * (size + 1));
	if (fresh)
		fresh = ft_memset(fresh, '\0', size + 1);
	return (fresh);
}
