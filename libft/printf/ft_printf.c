/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:10:22 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:10:24 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_dispatcher(t_printf *fpf)
{
	if (fpf->flag[F_COLOR])
		ft_fpf_color(fpf);
	if (FC == 'c' || FC == 'C')
		ft_output_c_modul(fpf);
	else if (FC == 's' || FC == 'S')
		ft_output_s_modul(fpf);
	else if (FC == 'd' || FC == 'i' || FC == 'D')
		ft_output_d_modul(fpf);
	else if (FC == 'u' || FC == 'U')
		ft_output_u_modul(fpf);
	else if (FC == 'o' || FC == 'O' || FC == 'x' || FC == 'X')
		ft_output_ox_modul(fpf);
	else if (FC == 'p')
		ft_output_p_modul(fpf);
	else
		ft_pf_strjoin(fpf, fpf->str, ft_strlen(fpf->str));
	if (fpf->flag[F_COLOR])
		ft_pf_strjoin(fpf, COLOR_RESET, ft_strlen(COLOR_RESET));
}

void		ft_initialization(t_printf *fpf)
{
	ft_bzero(fpf->flag, FPF_FLAG_SIZE);
	fpf->width = 0;
	fpf->precision = 0;
	fpf->size_flag = 0;
	fpf->type = '\0';
	fpf->str = NULL;
	ft_get_flags(fpf);
	ft_get_type(fpf);
}

void		ft_base_output(t_printf *fpf)
{
	int		len;
	int		i;
	char	*str;

	i = fpf->i;
	len = 0;
	while (fpf->format[i] && fpf->format[i] != '%')
	{
		len++;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return ;
	str[len] = '\0';
	i = 0;
	while (i < len)
	{
		str[i] = PC;
		i++;
		fpf->i++;
	}
	ft_pf_strjoin(fpf, str, len);
	free(str);
	fpf->i--;
}

void		ft_lobi(t_printf *fpf)
{
	while (PC)
	{
		if (PC == '%')
		{
			fpf->i++;
			if (!PC)
				continue;
			ft_initialization(fpf);
			if (fpf->type && fpf->str)
			{
				ft_dispatcher(fpf);
				free(fpf->str);
			}
			else
				fpf->i--;
		}
		else
			ft_base_output(fpf);
		fpf->i++;
	}
}

int			ft_printf(const char *format, ...)
{
	t_printf	fpf;
	int			len;

	fpf.fd = 1;
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
