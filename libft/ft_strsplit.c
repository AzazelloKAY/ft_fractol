/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:54:38 by akokoshk          #+#    #+#             */
/*   Updated: 2017/12/22 22:15:56 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_wordsnum(char const *s, char c)
{
	size_t num;

	num = 0;
	if (*s && *s != c)
	{
		num++;
		s++;
	}
	while (*s)
	{
		if ((*(s - 1) == c) && (*s != c))
			num++;
		s++;
	}
	return (num);
}

static char		**ft_makeword(char ***c, size_t i, char const *s, size_t len)
{
	if (!((*c)[i] = ft_strsub(s, 0, len)))
	{
		while (i--)
			ft_strdel(c[i]);
		free(*c);
		return (NULL);
	}
	return (*c);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**res;

	if (s == NULL)
		return (NULL);
	if (!(res = (char**)ft_memalloc(sizeof(char*) * (ft_wordsnum(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (len > 0)
		{
			if (!(ft_makeword(&res, i++, s, len)))
				return (NULL);
			s = &s[len];
		}
		else
			s++;
	}
	return (res);
}
