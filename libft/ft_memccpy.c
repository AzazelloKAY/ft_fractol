/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 21:37:16 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/25 21:37:16 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	uint8_t *res;
	uint8_t *s;

	res = (uint8_t*)dst;
	s = (uint8_t*)src;
	while (n--)
	{
		*res = *s;
		res++;
		if (*s == (uint8_t)c)
			return (res);
		s++;
	}
	return (NULL);
}
