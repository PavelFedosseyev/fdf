/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 22:14:08 by pfedosse          #+#    #+#             */
/*   Updated: 2019/05/07 22:15:19 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	x;
	int		i;

	i = ft_strlen(s);
	x = (char)c;
	while (i >= 0)
	{
		if (s[i] == x)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
