/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:44:21 by prippa            #+#    #+#             */
/*   Updated: 2018/02/26 15:44:26 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrnew(int y, int x, char c)
{
	char **arr;

	arr = (char **)malloc(sizeof(char *) * y + 1);
	arr[y] = NULL;
	while (--y >= 0)
	{
		arr[y] = (char *)malloc(sizeof(char) * x + 1);
		arr[y][x] = '\0';
		ft_memset(arr[y], c, x);
	}
	return (arr);
}
