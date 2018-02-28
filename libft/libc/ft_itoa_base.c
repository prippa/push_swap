/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 17:14:32 by prippa            #+#    #+#             */
/*   Updated: 2017/12/26 17:14:55 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(unsigned long long int num, int base, int letter)
{
	int						i;
	unsigned long long int	tmp;
	unsigned long long int	op;
	char					buf[65];

	if (base < 2 && base > 16)
		return (NULL);
	buf[64] = '\0';
	if (num == 0)
		return (ft_strdup("0"));
	tmp = num;
	i = 64;
	while (tmp)
	{
		op = tmp % base;
		tmp = tmp / base;
		i--;
		if (base > 10 && op > 9)
			buf[i] = op + letter;
		else
			buf[i] = op + 48;
	}
	return (ft_strdup(buf + i));
}
