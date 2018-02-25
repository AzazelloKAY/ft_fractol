/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:03:48 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/27 21:03:49 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *res;

	res = 0;
	while (s != NULL && *s)
	{
		if (*s == (char)c)
			res = (char*)s;
		s++;
	}
	if (res != 0)
		return (res);
	else if (*s == (char)c)
		return ((char*)s);
	return (NULL);
}
