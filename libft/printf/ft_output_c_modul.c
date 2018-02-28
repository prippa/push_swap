/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_c_modul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:08:34 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:08:37 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_join(t_printf *fpf)
{
	if (fpf->str[0])
		ft_pf_strjoin(fpf, fpf->str, ft_strlen(fpf->str));
	else
	{
		if (fpf->out_str)
		{
			fpf->size += write(fpf->fd, fpf->out_str, ft_strlen(fpf->out_str));
			free(fpf->out_str);
			fpf->out_str = NULL;
		}
		fpf->size += write(fpf->fd, &fpf->str[0], 1);
	}
}

static void	ft_modul_wchar(t_printf *fpf)
{
	int	len;
	int	print;

	len = ft_strlen(fpf->str);
	print = 1;
	if (fpf->flag[F_MINUS] && !(print = 0))
		ft_join(fpf);
	if (fpf->width)
	{
		if (fpf->flag[F_ZERO] && !fpf->flag[F_MINUS])
			ft_charjoin(fpf, fpf->width - len, '0');
		else
			ft_charjoin(fpf, fpf->width - len, ' ');
	}
	if (print)
		ft_join(fpf);
}

static void	ft_modul_char(t_printf *fpf)
{
	int	print;

	print = 1;
	if (fpf->flag[F_MINUS] && !(print = 0))
		ft_join(fpf);
	if (fpf->width)
	{
		if (fpf->flag[F_ZERO] && !fpf->flag[F_MINUS])
			ft_charjoin(fpf, fpf->width - 1, '0');
		else
			ft_charjoin(fpf, fpf->width - 1, ' ');
	}
	if (print)
		ft_join(fpf);
}

void		ft_output_c_modul(t_printf *fpf)
{
	if (FC == 'C' || fpf->size_flag == SF_L)
		ft_modul_wchar(fpf);
	else
		ft_modul_char(fpf);
}
