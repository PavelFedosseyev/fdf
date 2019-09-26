/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:14:45 by pfedosse          #+#    #+#             */
/*   Updated: 2019/05/28 22:26:23 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char			**array;
	unsigned int	i;
	unsigned int	j;

	if (s == NULL || c == '\0')
		return (NULL);
	j = 0;
	i = 0;
	if (!(array = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c && s[i])
			i++;
		else
		{
			array[j] = ft_word(&(s[i]), c);
			j++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	array[j] = 0;
	return (array);
}
