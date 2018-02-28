/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:01:12 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:01:20 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_di(t_printf *fpf)
{
	char	*str;

	if (FC == 'd' || FC == 'i')
		str = ft_itoa(ft_conv_sig_int(fpf));
	else
	{
		fpf->size_flag = SF_L;
		str = ft_itoa(ft_conv_sig_int(fpf));
	}
	return (str);
}
