/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:59:31 by prippa            #+#    #+#             */
/*   Updated: 2017/11/06 13:59:40 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(long long int n)
{
	long long int	flag;
	int				len;

	if (n < 0)
		flag = -0 - n;
	else
		flag = n;
	len = 0;
	while (flag)
	{
		flag /= 10;
		len++;
	}
	if (n == 0)
		len++;
	return (len);
}

char		*ft_itoa(long long int n)
{
	int		len;
	int		flag;
	char	*fresh;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_itoa_len(n);
	flag = 0;
	if (n < 0)
		flag++;
	if ((fresh = ft_strnew(len + flag)) == NULL)
		return (NULL);
	if (flag == 1)
	{
		fresh[0] = '-';
		n = -0 - n;
	}
	len += flag;
	fresh[len] = '\0';
	while (flag <= --len)
	{
		fresh[len] = ((n % 10) + '0');
		n /= 10;
	}
	return (fresh);
}
