/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:34:11 by pfedosse          #+#    #+#             */
/*   Updated: 2019/05/28 14:08:35 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (lst != NULL && f != NULL)
	{
		if (!(new = (t_list*)malloc(sizeof(lst))))
			return (NULL);
		new = (*f)(lst);
		tmp = new;
		while (lst->next)
		{
			lst = lst->next;
			tmp->next = (*f)(lst);
			tmp = tmp->next;
		}
		return (new);
	}
	return (NULL);
}
