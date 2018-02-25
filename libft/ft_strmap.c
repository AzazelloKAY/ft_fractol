/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:21:44 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/28 15:21:44 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (!(res = ft_strnew(len)))
		return (NULL);
	while (len--)
		res[len] = f(s[len]);
	return (res);
}
