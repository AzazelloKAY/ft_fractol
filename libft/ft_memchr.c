/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:13:51 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/26 19:13:52 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	uint8_t *src;

	src = (uint8_t*)s;
	while (n--)
	{
		if (*src == (uint8_t)c)
			return (src);
		src++;
	}
	return (NULL);
}
