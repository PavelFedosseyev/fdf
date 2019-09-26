/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:58:57 by pfedosse          #+#    #+#             */
/*   Updated: 2019/05/28 17:21:01 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_mallst(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	lst = (t_list*)malloc(sizeof(t_list));
	return (lst);
}
