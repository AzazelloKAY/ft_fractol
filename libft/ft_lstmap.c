/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:53:43 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/29 18:53:43 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lscontentdel(void *c, size_t i)
{
	uint8_t *t;

	t = (uint8_t*)c;
	while (i--)
	{
		*t = 0;
		t++;
	}
	free(c);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;
	t_list *cur;
	t_list *tmp;

	res = NULL;
	cur = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (!(tmp = ft_lstnew(tmp->content, tmp->content_size)))
			ft_lstdel(&res, ft_lscontentdel);
		if (tmp == NULL)
			return (NULL);
		if (cur == NULL)
			cur = tmp;
		else
		{
			cur->next = tmp;
			cur = cur->next;
		}
		if (res == NULL)
			res = cur;
		lst = lst->next;
	}
	return (res);
}
