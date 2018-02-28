/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:38:01 by prippa            #+#    #+#             */
/*   Updated: 2018/02/06 11:38:04 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dprintf(int fd, const char *format, ...)
{
	t_printf	fpf;
	int			len;

	fpf.fd = fd;
	fpf.format = ft_strdup(format);
	fpf.out_str = NULL;
	fpf.i = 0;
	fpf.size = 0;
	va_start(fpf.args, format);
	ft_lobi(&fpf);
	va_end(fpf.args);
	free(fpf.format);
	len = 0;
	if (fpf.out_str)
	{
		len = write(fpf.fd, fpf.out_str, ft_strlen(fpf.out_str));
		free(fpf.out_str);
	}
	return (len + fpf.size);
}
