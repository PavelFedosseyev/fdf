/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:57:39 by pfedosse          #+#    #+#             */
/*   Updated: 2019/09/25 16:18:16 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fillzero(t_fdf *fdf)
{
	fdf->first = (t_point *)malloc(sizeof(t_point));
	fdf->second = (t_point *)malloc(sizeof(t_point));
	fdf->first->x = 0;
	fdf->first->y = 0;
	fdf->first->z = 0;
	fdf->second->x = 0;
	fdf->second->y = 0;
	fdf->second->z = 0;
}
