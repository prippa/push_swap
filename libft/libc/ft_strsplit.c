/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:59:58 by prippa            #+#    #+#             */
/*   Updated: 2017/11/06 14:00:05 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t count;
	size_t i;

	count = 1;
	i = 0;
	while (s[i] == c)
		i++;
	if (!s[i])
		return (count - 1);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static char		*ft_split(char const *s, char c, size_t *si)
{
	size_t	i;
	size_t	len;
	char	*str;

	while (s[*si] && s[*si] == c)
		*si += 1;
	len = 0;
	i = 0;
	while (s[*si + len] && s[*si + len] != c)
		len++;
	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[*si];
		*si += 1;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	words;
	size_t	i;
	size_t	si;
	char	**result;

	if (!s || !c)
		return (NULL);
	words = ft_count_word((char*)s, c);
	if ((result = (char**)malloc(sizeof(char*) * (words + 1))) == NULL)
		return (NULL);
	if (words)
	{
		i = 0;
		si = 0;
		while (i < words)
		{
			result[i] = ft_split(s, c, &si);
			i++;
		}
	}
	result[words] = NULL;
	return (result);
}
