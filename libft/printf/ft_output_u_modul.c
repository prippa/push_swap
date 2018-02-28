/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_u_modul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:10:07 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:10:09 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_base_u_modul_logic(t_printf *fpf, int len)
{
	if (fpf->width)
	{
		if (fpf->flag[F_ZERO] && !fpf->precision)
			ft_charjoin(fpf, fpf->width - len, '0');
		else
			ft_charjoin(fpf, fpf->width - MAX(len, fpf->precision), ' ');
	}
	if (fpf->precision)
		ft_charjoin(fpf, fpf->precision - len, '0');
	ft_pf_strjoin(fpf, fpf->str, len);
}

void		ft_output_u_modul(t_printf *fpf)
{
	int	len;

	len = ft_strlen(fpf->str);
	if (fpf->flag[F_DOT] && !fpf->precision && fpf->str[0] == '0')
		len = 0;
	if (fpf->flag[F_MINUS])
	{
		if (fpf->precision)
			ft_charjoin(fpf, fpf->precision - len, '0');
		ft_pf_strjoin(fpf, fpf->str, len);
		if (fpf->width)
			ft_charjoin(fpf, fpf->width - MAX(len, fpf->precision), ' ');
	}
	else
		ft_base_u_modul_logic(fpf, len);
}
