/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_s_modul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:09:49 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:09:55 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_rules(t_printf *fpf, int len, int print)
{
	if (!ft_strlen(fpf->str))
	{
		len = 0;
		print = 0;
	}
	if (print && fpf->flag[F_MINUS] && !(print = 0))
		ft_pf_strjoin(fpf, fpf->str, len);
	if (fpf->width)
	{
		if (fpf->flag[F_ZERO] && !fpf->flag[F_MINUS])
			ft_charjoin(fpf, fpf->width - len, '0');
		else
			ft_charjoin(fpf, fpf->width - len, ' ');
	}
	if (print)
		ft_pf_strjoin(fpf, fpf->str, len);
}

void		ft_output_s_modul(t_printf *fpf)
{
	int	len;
	int	print;

	len = ft_strlen(fpf->str);
	if (fpf->precision < 0)
		fpf->precision = 0;
	else if (fpf->precision)
	{
		if (FC == 'S' && !ft_isascii(fpf->str[fpf->precision - 1]))
		{
			while (fpf->precision % 3 > 0)
				fpf->precision--;
		}
		if (len > fpf->precision)
			len = fpf->precision;
	}
	else if (fpf->flag[F_DOT])
		len = fpf->precision;
	print = 1;
	ft_rules(fpf, len, print);
}
