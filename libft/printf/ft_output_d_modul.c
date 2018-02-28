/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_d_modul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:08:50 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:08:53 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_d_modul(t_printf *fpf, int len, int len2)
{
	if (len < len2)
		ft_pf_strjoin(fpf, fpf->str + 1, len);
	else
		ft_pf_strjoin(fpf, fpf->str, len);
}

static void		ft_print_if_psm(t_printf *fpf, int *len, int *flag)
{
	if (*flag)
	{
		if (fpf->flag[F_PLUS] && fpf->str[0] != '-' && !(*flag = 0))
			ft_charjoin(fpf, 1, '+');
		else if (fpf->str[0] == '-' && !(*flag = 0))
		{
			ft_charjoin(fpf, 1, '-');
			*len -= 1;
		}
		else if (fpf->flag[F_SPACE] && !(*flag = 0))
			ft_charjoin(fpf, 1, ' ');
	}
}

static void		ft_base_d_modul_logic(t_printf *fpf, int len, int flag)
{
	int tmp;

	if (fpf->width)
	{
		if (fpf->flag[F_ZERO] && !fpf->precision)
		{
			tmp = len;
			ft_print_if_psm(fpf, &len, &flag);
			ft_charjoin(fpf, fpf->width - tmp, '0');
		}
		else
			ft_charjoin(fpf, fpf->width - MAX(len, fpf->precision), ' ');
	}
	if (fpf->precision)
	{
		ft_print_if_psm(fpf, &len, &flag);
		ft_charjoin(fpf, fpf->precision - len, '0');
		ft_print_d_modul(fpf, len, ft_strlen(fpf->str));
	}
	else
	{
		ft_print_if_psm(fpf, &len, &flag);
		ft_print_d_modul(fpf, len, ft_strlen(fpf->str));
	}
}

static void		ft_logic_d_with_minus(t_printf *fpf, int len)
{
	int	size;

	size = 0;
	if (fpf->flag[F_PLUS] && fpf->str[0] != '-' && (size += 1))
		ft_charjoin(fpf, 1, '+');
	else if (fpf->str[0] == '-' && (size += 1))
	{
		ft_charjoin(fpf, 1, '-');
		len--;
	}
	else if (fpf->flag[F_SPACE] && (size += 1))
		ft_charjoin(fpf, 1, ' ');
	if (fpf->precision)
		ft_charjoin(fpf, fpf->precision - len, '0');
	ft_print_d_modul(fpf, len, ft_strlen(fpf->str));
	if (fpf->width)
		ft_charjoin(fpf, fpf->width - MAX(len, fpf->precision) - size, ' ');
}

void			ft_output_d_modul(t_printf *fpf)
{
	int	len;

	len = ft_strlen(fpf->str);
	if (fpf->precision < 0 && (fpf->precision = fpf->width))
		fpf->width = 0;
	if (fpf->flag[F_DOT] && fpf->flag[F_ZERO] && !fpf->precision)
		fpf->flag[F_ZERO] = '\0';
	if (fpf->str[0] == '0' && fpf->flag[F_DOT])
		len = 0;
	if (fpf->flag[F_MINUS])
		ft_logic_d_with_minus(fpf, len);
	else
	{
		if (fpf->width && !fpf->flag[F_MINUS]
		&& ((fpf->flag[F_PLUS] && fpf->str[0] != '-')
		|| (fpf->flag[F_SPACE] && fpf->str[0] != '-')
		|| (fpf->precision == len && fpf->str[0] == '-')
		|| (fpf->str[0] == '-' && !fpf->flag[F_ZERO]
		&& fpf->precision && fpf->precision > len)))
			fpf->width--;
		ft_base_d_modul_logic(fpf, len, 1);
	}
}
