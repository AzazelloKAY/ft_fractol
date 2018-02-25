/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:10:49 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/27 19:10:49 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*tmp;

	tmp = s1;
	while (*tmp)
		tmp++;
	while (n--)
	{
		if (*s2)
			*tmp = *s2;
		else
			break ;
		s2++;
		tmp++;
	}
	*tmp = 0;
	return (s1);
}
