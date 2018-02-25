/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 20:56:47 by akokoshk          #+#    #+#             */
/*   Updated: 2017/12/16 15:50:44 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlength(int n)
{
	size_t res;

	res = 0;
	if (n <= 0)
		res++;
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char			*ft_itoa(int n)
{
	char			*res;
	size_t			len;
	unsigned int	un;

	len = ft_intlength(n);
	if (!(res = ft_strnew(len)))
		return (NULL);
	un = FTABS(n);
	while (un != 0)
	{
		res[--len] = (un % 10) + '0';
		un /= 10;
	}
	if (n == 0)
		res[0] = '0';
	else if (len > 0)
		res[0] = '-';
	return (res);
}
