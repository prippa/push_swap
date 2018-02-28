/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:57:21 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 12:57:23 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_charjoin(t_printf *fpf, int n, char c)
{
	char	*str;
	int		size;

	size = n;
	if (n < 1)
		return ;
	if (!(str = (char *)malloc(sizeof(char) * n + 1)))
		return ;
	str[n] = '\0';
	while (--n >= 0)
		str[n] = c;
	ft_pf_strjoin(fpf, str, size);
	free(str);
}
