/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:21:18 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/27 21:21:18 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t i;

	if ((*little == 0) || (little == NULL))
		return ((char*)big);
	while (*big)
	{
		i = 0;
		while ((big[i] == little[i]) && (little[i] != 0))
			i++;
		if (little[i] == 0)
			return ((char*)big);
		big++;
	}
	return (NULL);
}
