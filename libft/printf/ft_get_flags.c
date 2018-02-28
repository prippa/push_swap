/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:02:14 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:02:31 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_flags(t_printf *fpf)
{
	while (PC)
	{
		if (ft_get_flag_type(fpf))
			fpf->i++;
		else
			return ;
	}
}

static void		ft_get_width_or_precision(t_printf *fpf, char c)
{
	char	wipi[20];
	int		i;

	i = 0;
	while (ft_isdigit(PC) && i < 20)
	{
		wipi[i] = PC;
		fpf->i++;
		i++;
	}
	wipi[i] = '\0';
	if (i)
	{
		if (c == 'w')
			fpf->width = ft_atoi(wipi);
		else if (c == 'p')
			fpf->precision = ft_atoi(wipi);
	}
	else if (c == 'p')
		fpf->precision = 0;
}

static void		ft_precision(t_printf *fpf)
{
	while (PC)
	{
		if (PC == '.')
			fpf->flag[F_DOT] = '.';
		else
			break ;
		fpf->i++;
	}
	if (fpf->flag[F_DOT])
	{
		if (PC == '*')
		{
			while (PC == '*')
			{
				fpf->precision = va_arg(fpf->args, int);
				fpf->i++;
			}
		}
		else
			ft_get_width_or_precision(fpf, 'p');
	}
}

static void		ft_size_flag(t_printf *fpf)
{
	while (SIZE_FLAGS(PC))
	{
		if (PC == 'l' && PC_1 == 'l' && fpf->size_flag < SF_LL
			&& (fpf->size_flag = SF_LL))
			fpf->i += 2;
		else if (PC == 'l' && fpf->size_flag < SF_L
			&& (fpf->size_flag = SF_L))
			fpf->i += 1;
		else if (PC == 'h' && PC_1 == 'h' && fpf->size_flag < SF_HH
			&& (fpf->size_flag = SF_HH))
			fpf->i += 2;
		else if (PC == 'h' && fpf->size_flag < SF_H
			&& (fpf->size_flag = SF_H))
			fpf->i += 1;
		else if (PC == 'j' && fpf->size_flag < SF_J
			&& (fpf->size_flag = SF_J))
			fpf->i += 1;
		else if (PC == 'z' && fpf->size_flag < SF_Z
			&& (fpf->size_flag = SF_Z))
			fpf->i += 1;
		else
			fpf->i++;
	}
}

void			ft_get_flags(t_printf *fpf)
{
	while (SIZE_FLAGS(PC) || FLAGS(PC) || BONUS_FLAGS(PC) || ft_isdigit(PC))
	{
		ft_flags(fpf);
		ft_get_width_or_precision(fpf, 'w');
		ft_precision(fpf);
		ft_size_flag(fpf);
	}
}
