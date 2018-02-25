/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:27:50 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/27 19:27:50 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strmaxlen(size_t len, size_t size)
{
	if (len > size)
		return (size);
	return (len);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t reslen;

	i = ft_strlen(dst);
	reslen = ft_strlen(src) + ft_strmaxlen(i, size);
	while (size != 0 && i < (size - 1) && src != NULL && *src)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = 0;
	return (reslen);
}
