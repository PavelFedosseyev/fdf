/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:23:29 by pfedosse          #+#    #+#             */
/*   Updated: 2019/05/28 22:33:18 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	size_t	len;
	char	*new;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	new = malloc(len + 1);
	if (new != NULL)
	{
		while (s[i])
		{
			new[i] = (*f)(s[i]);
			i++;
		}
		new[len] = '\0';
	}
	return (new);
}
