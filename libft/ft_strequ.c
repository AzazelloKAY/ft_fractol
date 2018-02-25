/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:51:40 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/28 15:51:40 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if ((s1 == NULL) && (s2 == NULL))
		return (1);
	if (((s1 == NULL) && (s2 != NULL)) ||
		((s1 != NULL) && (s2 == NULL)))
		return (0);
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	return (0);
}
