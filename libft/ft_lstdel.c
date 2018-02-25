/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:42:03 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/29 15:42:03 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *nxt;

	if (alst != NULL)
		while (*alst)
		{
			nxt = (*alst)->next;
			ft_lstdelone(alst, del);
			(*alst) = nxt;
		}
}
