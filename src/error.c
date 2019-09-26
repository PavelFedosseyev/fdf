/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:25:03 by pfedosse          #+#    #+#             */
/*   Updated: 2019/09/25 16:17:41 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_positive(double number)
{
	if (number < 0)
		return (-number);
	return (number);
}

void	error(char *s)
{
	write(1, "Error: ", 7);
	ft_putstr(s);
	ft_putchar('\n');
	exit(1);
}
