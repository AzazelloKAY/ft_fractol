/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:24:15 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/28 17:24:16 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(char c)
{
	if ((c == ' ') ||
		(c == '\n') ||
		(c == '\t'))
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	size_t	len;

	if (s == NULL)
		return (NULL);
	while (ft_isspace(*s))
		s++;
	len = ft_strlen(s);
	if (len == 0)
		return (ft_strnew(0));
	while (ft_isspace(s[len - 1]))
		len--;
	return (ft_strsub(s, 0, len));
}
