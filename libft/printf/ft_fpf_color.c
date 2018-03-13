/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fpf_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:58:54 by prippa            #+#    #+#             */
/*   Updated: 2018/03/12 21:52:51 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fpf_bold_color(t_printf *fpf)
{
	if (fpf->color == F_BOLD_GRAY)
		ft_pf_strjoin(fpf, BOLD_GRAY, ft_strlen(BOLD_GRAY));
	else if (fpf->color == F_BOLD_RED)
		ft_pf_strjoin(fpf, BOLD_RED, ft_strlen(BOLD_RED));
	else if (fpf->color == F_BOLD_GREEN)
		ft_pf_strjoin(fpf, BOLD_GREEN, ft_strlen(BOLD_GREEN));
	else if (fpf->color == F_BOLD_YELLOW)
		ft_pf_strjoin(fpf, BOLD_YELLOW, ft_strlen(BOLD_YELLOW));
	else if (fpf->color == F_BOLD_BLUE)
		ft_pf_strjoin(fpf, BOLD_BLUE, ft_strlen(BOLD_BLUE));
	else if (fpf->color == F_BOLD_MAGENTA)
		ft_pf_strjoin(fpf, BOLD_MAGENTA, ft_strlen(BOLD_MAGENTA));
	else if (fpf->color == F_BOLD_CYAN)
		ft_pf_strjoin(fpf, BOLD_CYAN, ft_strlen(BOLD_CYAN));
	else if (fpf->color == F_BOLD_WHITE)
		ft_pf_strjoin(fpf, BOLD_WHITE, ft_strlen(BOLD_WHITE));
}

void		ft_fpf_color(t_printf *fpf)
{
	if (fpf->color == F_RED)
		ft_pf_strjoin(fpf, RED, ft_strlen(RED));
	else if (fpf->color == F_YELLOW)
		ft_pf_strjoin(fpf, YELLOW, ft_strlen(YELLOW));
	else if (fpf->color == F_GREEN)
		ft_pf_strjoin(fpf, GREEN, ft_strlen(GREEN));
	else if (fpf->color == F_CYAN)
		ft_pf_strjoin(fpf, CYAN, ft_strlen(CYAN));
	else if (fpf->color == F_BLUE)
		ft_pf_strjoin(fpf, BLUE, ft_strlen(BLUE));
	else if (fpf->color == F_MAGENTA)
		ft_pf_strjoin(fpf, MAGENTA, ft_strlen(MAGENTA));
	else if (fpf->color == F_WHITE)
		ft_pf_strjoin(fpf, WHITE, ft_strlen(WHITE));
	else
		ft_fpf_bold_color(fpf);
}
