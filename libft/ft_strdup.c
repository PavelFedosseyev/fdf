/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 14:20:48 by pfedosse          #+#    #+#             */
/*   Updated: 2019/05/04 14:31:25 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;

	new = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (new != NULL)
		ft_strcpy(new, s1);
	return (new);
}
