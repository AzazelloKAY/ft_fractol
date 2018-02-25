/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:24:22 by akokoshk          #+#    #+#             */
/*   Updated: 2017/09/25 18:24:24 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int dif;

	while (*s1 || *s2)
	{
		dif = (unsigned char)*s1 - (unsigned char)*s2;
		if (dif != 0)
			return (dif);
		s1++;
		s2++;
	}
	return (0);
}
