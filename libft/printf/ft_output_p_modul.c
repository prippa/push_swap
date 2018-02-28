/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_p_modul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:09:36 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:09:39 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_base_p_modul_logic(t_printf *fpf, int len)
{
	int	flag;

	fpf->width -= 2;
	flag = 1;
	if (fpf->width)
	{
		if (fpf->flag[F_ZERO] && !fpf->precision)
		{
			flag = 0;
			ft_pf_strjoin(fpf, "0x", 2);
			ft_charjoin(fpf, fpf->width - len, '0');
		}
		else
			ft_charjoin(fpf, fpf->width - MAX(len, fpf->precision), ' ');
	}
	if (flag)
		ft_pf_strjoin(fpf, "0x", 2);
	if (fpf->precision)
		ft_charjoin(fpf, fpf->precision - len, '0');
	ft_pf_strjoin(fpf, fpf->str, len);
}

void			ft_output_p_modul(t_printf *fpf)
{
	int	len;

	len = ft_strlen(fpf->str);
	if (fpf->flag[F_DOT] && !fpf->precision && fpf->str[0] == '0')
		len = 0;
	if (fpf->flag[F_MINUS])
	{
		ft_pf_strjoin(fpf, "0x", 2);
		if (fpf->precision)
			ft_charjoin(fpf, fpf->precision - len, '0');
		ft_pf_strjoin(fpf, fpf->str, len);
		if (fpf->width)
			ft_charjoin(fpf, fpf->width - MAX(len, fpf->precision) - 2, ' ');
	}
	else
		ft_base_p_modul_logic(fpf, len);
}
