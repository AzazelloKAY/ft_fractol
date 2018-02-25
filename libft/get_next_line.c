/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:17:12 by akokoshk          #+#    #+#             */
/*   Updated: 2018/01/15 23:10:38 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memrealloc(void *src, size_t len, size_t extralen)
{
	void *res;

	if (len + extralen == 0)
		return (src);
	if (!(res = ft_memalloc(len + extralen)))
		return (NULL);
	if (src == NULL)
		return (res);
	res = ft_memcpy(res, src, len);
	ft_memdel(&src);
	return (res);
}

static t_fd		*ft_addfdbuf(const int fd, t_fhand **fdlist, size_t bytlen)
{
	unsigned int	num;

	(*fdlist)->fdbuf = ft_memrealloc((*fdlist)->fdbuf, bytlen, sizeof(t_fd));
	if (!((*fdlist)->fdbuf))
		return (NULL);
	num = (*fdlist)->fdnum;
	(*fdlist)->fdbuf[num].fd = fd;
	(*fdlist)->fdnum++;
	return (&((*fdlist)->fdbuf[num]));
}

static t_fd		*ft_fdlistinit(t_fhand **fdlist, const int fd)
{
	t_fd			*tfbuf;
	unsigned int	i;

	i = 0;
	tfbuf = NULL;
	if (*fdlist == NULL && !(*fdlist = (t_fhand*)ft_memalloc(sizeof(t_fhand))))
		return (NULL);
	while (i++ < (*fdlist)->fdnum)
		if ((*fdlist)->fdbuf[i - 1].fd == fd)
		{
			tfbuf = &((*fdlist)->fdbuf[i - 1]);
			break ;
		}
	if (tfbuf == NULL)
		tfbuf = ft_addfdbuf(fd, fdlist, (sizeof(t_fd) * (*fdlist)->fdnum));
	if (tfbuf && tfbuf->buf == NULL)
	{
		tfbuf->start = 0;
		tfbuf->buflen = 0;
		tfbuf->isfull = 0;
		if (!(tfbuf->buf = ft_memalloc(sizeof(uint8_t) * (BUFF_SIZE + 1))))
			return (NULL);
	}
	return (tfbuf);
}

static int		ft_makeres(char **res, size_t *reslen, t_fd *fd, uint8_t *isupd)
{
	long	addlen;

	if ((fd->isfull == 0) || (fd->buflen > 0 && fd->start == fd->buflen))
		return (1);
	if (fd->buflen <= 0)
		return (0);
	addlen = 0;
	while (((fd->start + addlen) < fd->buflen) &&
		(fd->buf[fd->start + addlen] != '\n'))
		addlen++;
	if (addlen > 0)
	{
		*res = ft_memrealloc(*res, *reslen, (addlen + 1));
		ft_memcpy((*res + *reslen), (fd->buf + fd->start), addlen);
	}
	fd->start += (fd->start + addlen < fd->buflen) ? addlen + 1 : addlen;
	*reslen += addlen;
	*isupd = 1;
	if ((fd->start == fd->buflen) && (fd->buf[fd->start - 1] != '\n'))
		return (1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_fhand	*fdlist;
	t_fd			*curfd;
	uint8_t			isupd;
	size_t			reslen;

	isupd = 0;
	reslen = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	*line = (char*)ft_memalloc(1);
	if ((curfd = ft_fdlistinit(&fdlist, fd)))
		while (ft_makeres(line, &reslen, curfd, &isupd))
		{
			curfd->start = 0;
			if ((curfd->buflen = read(fd, curfd->buf, BUFF_SIZE)) <= 0)
			{
				ft_memdel((void**)&(curfd->buf));
				return ((curfd->buflen < 0) ? -1 : isupd);
			}
			curfd->isfull = 1;
		}
	else
		return (-1);
	return (1);
}
