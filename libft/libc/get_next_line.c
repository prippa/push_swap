/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:47:04 by prippa            #+#    #+#             */
/*   Updated: 2017/11/22 17:47:18 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		fill_str(t_gnl **file)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp_buf;
	t_gnl	*tmp;

	tmp = *file;
	if (!tmp->str && !(tmp->str = ft_strdup("")))
		return (-1);
	while ((ret = read(tmp->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp_buf = (char*)malloc(sizeof(char)
			* ((ret + ft_strlen(tmp->str)) + 1))))
			return (-1);
		ft_strcpy(tmp_buf, tmp->str);
		ft_strcat(tmp_buf, buf);
		free(tmp->str);
		if (!(tmp->str = ft_strdup(tmp_buf)))
			return (-1);
		free(tmp_buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (1);
}

static int		if_str_end(t_gnl **file, int i)
{
	char	*buf;
	t_gnl	*tmp;

	tmp = *file;
	if ((i - tmp->start) > 0 && !(tmp->str[i]))
	{
		if (!(buf = ft_strsub(tmp->str, tmp->start, (size_t)(i - tmp->start))))
			return (-1);
		free(tmp->str);
		if (!(tmp->str = ft_strdup(buf)))
			return (-1);
		free(buf);
		if (fill_str(&tmp) == -1)
			return (-1);
		tmp->start = 0;
		i = tmp->start;
		while (tmp->str[i] && tmp->str[i] != '\n')
			i++;
	}
	return (i);
}

static int		line_valid(t_gnl **file)
{
	int		i;
	t_gnl	*tmp;

	tmp = *file;
	if (!tmp->str && fill_str(&tmp) == -1)
		return (-1);
	if (!(tmp->str[tmp->start]))
	{
		free(tmp->str);
		tmp->str = NULL;
		if (fill_str(&tmp) == -1)
			return (-1);
		tmp->start = 0;
	}
	if (tmp->str[tmp->start] == '\n')
		return (1);
	i = tmp->start;
	while (tmp->str[i] && tmp->str[i] != '\n')
		i++;
	i = if_str_end(&tmp, i);
	i -= tmp->start;
	return (i);
}

static int		get_line(t_gnl **file, char **line)
{
	int		i;
	t_gnl	*tmp;

	tmp = *file;
	i = line_valid(&tmp);
	if (i == 0)
		return (0);
	else if (i < 0)
		return (-1);
	if (tmp->str[tmp->start] == '\n')
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		tmp->start++;
		return (1);
	}
	if (!(*line = ft_strsub(tmp->str, tmp->start, (size_t)i)))
		return (-1);
	if (tmp->str[i])
		tmp->start += (i + 1);
	else
		tmp->start += i;
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_gnl	*file;
	t_gnl			*tmp;

	if (fd < 0 || !line || read(fd, 0, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	tmp = file;
	while (tmp)
	{
		if (tmp->fd == fd)
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
	{
		if (!(tmp = (t_gnl*)malloc(sizeof(*tmp))))
			return (-1);
		tmp->str = NULL;
		tmp->fd = fd;
		tmp->start = 0;
		tmp->next = file;
		file = tmp;
	}
	return (get_line(&tmp, &(*line)));
}
