/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_ox_modul.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:09:10 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:09:13 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_percision_tricks(t_printf *fpf, int *len)
{
	if (fpf->flag[F_DOT] && !fpf->precision && fpf->str[0] == '0'
		&& !fpf->flag[F_SHARP])
		*len = 0;
	if (fpf->flag[F_DOT] && !fpf->precision && fpf->str[0] == '0'
		&& fpf->flag[F_SHARP] && (FC == 'x' || FC == 'X'))
		*len = 0;
	if (fpf->flag[F_DOT] && fpf->precision
		&& fpf->flag[F_SHARP] && (FC == 'o' || FC == 'O'))
		fpf->flag[F_SHARP] = '\0';
}

static int		ft_write_sharp(t_printf *fpf)
{
	if (FC == 'x')
	{
		ft_pf_strjoin(fpf, "0x", 2);
		return (2);
	}
	else if (FC == 'X')
	{
		ft_pf_strjoin(fpf, "0X", 2);
		return (2);
	}
	else if (FC == 'o' || FC == 'O')
	{
		ft_pf_strjoin(fpf, "0", 1);
		return (1);
	}
	return (0);
}

static void		ft_base_ox_modul_logic(t_printf *fpf, int len)
{
	if (fpf->width && fpf->flag[F_SHARP] && FC != 'o' && FC != 'O')
		fpf->width -= 2;
	else if (fpf->width && fpf->flag[F_SHARP] && (FC == 'o' || FC == 'O'))
		fpf->width--;
	if (fpf->width)
	{
		if (fpf->flag[F_ZERO] && !fpf->precision)
		{
			if (fpf->flag[F_SHARP])
				ft_write_sharp(fpf);
			ft_charjoin(fpf, fpf->width - len, '0');
		}
		else
			ft_charjoin(fpf, fpf->width - MAX(len, fpf->precision), ' ');
	}
	if (fpf->flag[F_SHARP] && fpf->str[0] != '0'
		&& (!fpf->flag[F_ZERO] || !fpf->width))
		ft_write_sharp(fpf);
	if (fpf->precision)
		ft_charjoin(fpf, fpf->precision - len, '0');
	ft_pf_strjoin(fpf, fpf->str, len);
}

void			ft_output_ox_modul(t_printf *fpf)
{
	int	len;
	int	size;

	len = ft_strlen(fpf->str);
	ft_percision_tricks(fpf, &len);
	size = 0;
	if (fpf->flag[F_MINUS])
	{
		if (fpf->flag[F_SHARP] && len)
			size += ft_write_sharp(fpf);
		if (fpf->precision)
			ft_charjoin(fpf, fpf->precision - len, '0');
		ft_pf_strjoin(fpf, fpf->str, len);
		if (fpf->width)
			ft_charjoin(fpf, fpf->width - MAX(len, fpf->precision) - size, ' ');
	}
	else
		ft_base_ox_modul_logic(fpf, len);
}
