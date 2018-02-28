/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:11:14 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:11:19 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_strjoin(t_printf *fpf, char *str, int size)
{
	char	*buf;
	int		len;
	int		i;

	if (!size)
		return ;
	if (!fpf->out_str && !(fpf->out_str = ft_strdup("")))
		return ;
	len = ft_strlen(fpf->out_str);
	if (!(buf = (char *)malloc(sizeof(char) * len + size + 1)))
		return ;
	buf[len + size] = '\0';
	i = -1;
	while (fpf->out_str[++i])
		buf[i] = fpf->out_str[i];
	i = 0;
	while (str[i] && i < size)
		buf[len++] = str[i++];
	free(fpf->out_str);
	fpf->out_str = ft_strdup(buf);
	free(buf);
}
