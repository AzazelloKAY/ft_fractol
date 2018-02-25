/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 21:56:00 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/26 21:56:01 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *res;

	res = dst;
	while (len--)
	{
		if (*src != 0)
		{
			*res = *src;
			src++;
		}
		else
			*res = 0;
		res++;
	}
	return (dst);
}
