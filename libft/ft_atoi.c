/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 12:58:45 by akokoshk          #+#    #+#             */
/*   Updated: 2017/12/15 20:22:45 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iswspace(char *str)
{
	if (*str == ' ' || *str == '\t')
		return (1);
	else if (*str == '\n' || *str == '\v')
		return (1);
	else if (*str == '\f' || *str == '\r')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int				res;
	int				mod;
	unsigned long	ch;

	res = 0;
	ch = 0;
	mod = 1;
	while (ft_iswspace((char*)str))
		str++;
	if (*str == '-')
		mod = -1;
	if ((*str == '+') || (*str == '-'))
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		res = res * 10 + *str - '0';
		ch = ch * 10 + *str - '0';
		str++;
		if ((mod == -1) && (ch > 9223372036854775807))
			return (0);
		if ((mod == 1) && (ch > 9223372036854775806))
			return (-1);
	}
	return (res *= mod);
}
