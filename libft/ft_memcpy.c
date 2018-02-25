/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 21:09:37 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/25 21:09:37 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	uint8_t *res;
	uint8_t *s;

	res = (uint8_t*)dst;
	s = (uint8_t*)src;
	while (n--)
	{
		*res = *s;
		res++;
		s++;
	}
	return (dst);
}
