/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:40:17 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/28 15:40:17 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (!(res = ft_strnew(len)))
		return (NULL);
	while (len--)
		res[len] = f((unsigned int)len, s[len]);
	return (res);
}
