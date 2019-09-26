/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:29:43 by pfedosse          #+#    #+#             */
/*   Updated: 2019/05/29 13:31:20 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ls;
	size_t	ld;
	size_t	n;

	ls = ft_strlen(src);
	ld = ft_strlen(dst);
	ld = ld > dstsize ? dstsize : ld;
	n = dstsize - ld;
	if (n == 0)
		return (ld + ls);
	dst = dst + ld;
	while (*src)
	{
		if (n != 1)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (ld + ls);
}
