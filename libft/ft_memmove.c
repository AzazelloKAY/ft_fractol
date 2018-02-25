/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 21:58:16 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/25 21:58:16 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	uint8_t *tmp;
	uint8_t *res;
	size_t	i;

	tmp = (uint8_t*)src;
	res = (uint8_t*)dst;
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			res[i] = tmp[i];
			i++;
		}
	}
	else
		while (len--)
			res[len] = tmp[len];
	return (dst);
}
