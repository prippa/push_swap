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

void		*ft_memjoin(void *des, int counter, void *add, int value)
{
	void	*join;
	void	*tmp;

	join = (void *)malloc((counter + value + 1));
	if (!(des))
	{
		join = ft_memcpy(join, add, value);
		((unsigned char *)join)[counter + value] = '\0';
		return (join);
	}
	else if (!add)
	{
		join = ft_memcpy(join, des, counter);
		((unsigned char *)join)[counter] = '\0';
	}
	else
	{
		tmp = join;
		ft_memcpy(join, des, counter);
		tmp += counter;
		ft_memcpy(tmp, add, value);
		((unsigned char *)join)[counter + value] = '\0';
	}
	free(des);
	return (join);
}

int			is_nl(void **rest, int *rm, void **gline, int *counter)
{
	int		dif;
	void	*tmp;

	if (ft_memchr(*rest, '\n', *rm))
	{
		dif = ((ft_memchr(*rest, '\n', *rm) - *rest) + 1);
		*gline = ft_memjoin(*gline, *counter, *rest, (dif - 1));
		*counter += dif;
		if ((*rm = (*rm - dif)))
		{
			tmp = *rest;
			*rest = ft_memjoin(NULL, 0, (*rest + dif), *rm);
			ft_bzero(tmp, (*rm + dif));
			free(tmp);
		}
		else
			ft_memdel(rest);
		return (1);
	}
	*gline = ft_memjoin(*gline, *counter, *rest, *rm);
	*counter += *rm;
	ft_memdel(rest);
	return (0);
}

t_gnl		*lst_fd(void *rest, int rm, int fd)
{
	t_gnl	*newlist;

	newlist = (t_gnl *)malloc(sizeof(t_gnl));
	if (newlist == NULL)
		return (NULL);
	if (rest == NULL)
	{
		newlist->rest = NULL;
		newlist->rm = 0;
		newlist->fd = fd;
	}
	else
	{
		newlist->rest = (void *)malloc(sizeof(rest));
		if (newlist->rest == NULL)
			return (NULL);
		ft_memcpy((newlist->rest), rest, rm);
		newlist->rm = rm;
		newlist->fd = fd;
	}
	newlist->next = NULL;
	return (newlist);
}

t_gnl		*get_right_list(t_gnl *lst, int fd)
{
	t_gnl	*l;

	while (lst)
	{
		if ((lst)->fd == fd)
		{
			l = lst;
			return (l);
		}
		if ((lst)->next)
			lst = (lst)->next;
		else
			break ;
	}
	(lst)->next = lst_fd(NULL, 0, fd);
	l = (lst)->next;
	return (l);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	*pl;
	t_gnl			*l;
	int				counter;
	unsigned char	tmp[BUFF_SIZE];
	void			*gline;

	if ((fd < 0) || !(line) || read(fd, 0, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (!(pl))
		pl = lst_fd(NULL, 0, fd);
	l = get_right_list(pl, fd);
	counter = 0;
	gline = NULL;
	if (!(l->rest && is_nl(&(l->rest), &(l->rm), &gline, &counter)))
		while ((l->rm = read(fd, tmp, BUFF_SIZE)))
		{
			if (l->rm < 0)
				return (-1);
			l->rest = ft_memjoin(l->rest, 0, tmp, l->rm);
			if (is_nl(&(l->rest), &(l->rm), &gline, &counter))
				break ;
		}
	*line = (char *)gline;
	return ((counter > 0) ? 1 : 0);
}
