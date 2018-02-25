/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 00:00:14 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/28 00:00:15 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	uint8_t *res;

	if (size == 0)
		return (NULL);
	if (!(res = (uint8_t*)malloc(size)))
		return (NULL);
	ft_bzero(res, size);
	return (res);
}
