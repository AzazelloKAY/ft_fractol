/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 22:35:42 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/27 22:35:42 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int dif;

	while ((*s1 || *s2) && n--)
	{
		dif = (unsigned char)*s1 - (unsigned char)*s2;
		if (dif != 0)
			return (dif);
		s1++;
		s2++;
	}
	return (0);
}
