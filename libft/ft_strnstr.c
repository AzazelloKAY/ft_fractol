/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:38:31 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/27 21:38:31 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (*little == 0)
		return ((char*)big);
	while (*big && len--)
	{
		i = 0;
		while ((big[i] == little[i]) && (little[i] != 0) && (i <= len))
			i++;
		if (little[i] == 0)
			return ((char*)big);
		big++;
	}
	return (NULL);
}
