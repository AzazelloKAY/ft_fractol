/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:39:29 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/26 19:39:30 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	uint8_t	*a;
	uint8_t	*b;
	int		dif;

	a = (uint8_t*)s1;
	b = (uint8_t*)s2;
	dif = 0;
	while (n--)
	{
		dif = *a - *b;
		if (dif != 0)
			return (dif);
		a++;
		b++;
	}
	return (0);
}
