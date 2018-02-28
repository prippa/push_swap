/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:06:18 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:06:28 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_get_type_1(t_printf *fpf)
{
	if (PC == 'o' && (FC = PC))
		fpf->str = ft_get_oux(fpf);
	else if (PC == 'O' && (FC = PC))
		fpf->str = ft_get_oux(fpf);
	else if (PC == 'u' && (FC = PC))
		fpf->str = ft_get_oux(fpf);
	else if (PC == 'U' && (FC = PC))
		fpf->str = ft_get_oux(fpf);
	else if (PC == 'x' && (FC = PC))
		fpf->str = ft_get_oux(fpf);
	else if (PC == 'X' && (FC = PC))
		fpf->str = ft_get_oux(fpf);
	else if (PC)
	{
		FC = 'c';
		if (!(fpf->str = (char*)malloc(sizeof(char) * 2)))
			return ;
		fpf->str[0] = PC;
		fpf->str[1] = '\0';
	}
}

void		ft_get_type(t_printf *fpf)
{
	if (PC == 's' && (FC = PC))
		fpf->str = ft_get_s(fpf);
	else if (PC == 'd' && (FC = PC))
		fpf->str = ft_get_di(fpf);
	else if (PC == 'c' && (FC = PC))
		fpf->str = ft_get_c(fpf);
	else if (PC == 'S' && (FC = PC))
		fpf->str = ft_get_s(fpf);
	else if (PC == 'C' && (FC = PC))
		fpf->str = ft_get_c(fpf);
	else if (PC == 'D' && (FC = PC))
		fpf->str = ft_get_di(fpf);
	else if (PC == 'i' && (FC = PC))
		fpf->str = ft_get_di(fpf);
	else if (PC == 'p' && (FC = PC))
		fpf->str = ft_itoa_base(va_arg(fpf->args, unsigned long int), 16, 87);
	else
		ft_get_type_1(fpf);
}

static int	ft_get_flag_type_bonus(t_printf *fpf)
{
	if (PC == '*')
	{
		if ((fpf->width = va_arg(fpf->args, int)) < 0)
		{
			fpf->flag[F_MINUS] = '-';
			fpf->width = fpf->width * -1;
		}
	}
	else if (PC == '~')
	{
		fpf->color = va_arg(fpf->args, int);
		fpf->flag[F_COLOR] = '~';
	}
	else
		return (0);
	return (1);
}

int			ft_get_flag_type(t_printf *fpf)
{
	if (PC == '-')
		fpf->flag[F_MINUS] = '-';
	else if (PC == '+')
		fpf->flag[F_PLUS] = '+';
	else if (PC == ' ')
		fpf->flag[F_SPACE] = ' ';
	else if (PC == '#')
		fpf->flag[F_SHARP] = '#';
	else if (PC == '0')
		fpf->flag[F_ZERO] = '0';
	else if (!ft_get_flag_type_bonus(fpf))
		return (0);
	return (1);
}
