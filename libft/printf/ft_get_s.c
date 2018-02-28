/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:06:02 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:06:07 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_s(t_printf *fpf)
{
	void	*data;
	char	*str;

	data = va_arg(fpf->args, void *);
	if (!data)
		str = ft_strdup("(null)");
	else if (FC == 'S' || fpf->size_flag == SF_L)
		str = ft_wstr_to_str((wchar_t *)data);
	else
		str = ft_strdup((char *)data);
	return (str);
}
