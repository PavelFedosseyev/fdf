/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 12:31:29 by pfedosse          #+#    #+#             */
/*   Updated: 2019/05/29 13:31:23 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	i = 0;
	s1 = (char*)str1;
	s2 = (char*)str2;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}
