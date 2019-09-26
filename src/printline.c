/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:19:33 by pfedosse          #+#    #+#             */
/*   Updated: 2019/09/25 16:33:10 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				printlow2(t_point **diff, t_point **point, \
							t_point *first, t_point *second)
{
	int			i;

	i = 0;
	(*diff)->x = second->x - first->x;
	(*diff)->y = second->y - first->y;
	(*diff)->z = (second->z > first->z) ? (second->z - first->z) : \
											(first->z - second->z);
	i = 0;
	((*diff)->y < 0) ? (i -= 1) : (i += 1);
	((*diff)->y < 0) ? ((*diff)->y = -(*diff)->y) : (i += 0);
	(*point)->z = 2 * (*diff)->y - (*diff)->x;
	(*point)->y = first->y;
	(*point)->x = first->x - 1;
	return (i);
}

void			printlow(t_fdf *fdf, t_point *first, \
					t_point *second, int minimum_altitude)
{
	t_point		*diff;
	t_point		*point;
	int			i;
	double		color_increment;

	diff = (t_point *)malloc(sizeof(t_point));
	point = (t_point *)malloc(sizeof(t_point));
	i = printlow2(&diff, &point, first, second);
	color_increment = diff->z / (second->y - point->y);
	while (++point->x < second->x)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)point->x, \
				(int)point->y, minimum_altitude);
		(point->z > 0) ? \
			(point->y = point->y + i) : (minimum_altitude += 0);
		(point->z > 0) ? (point->z = point->z - 2 * diff->x) : \
					(minimum_altitude += 0);
		minimum_altitude += color_increment * 200;
		point->z = point->z + 2 * diff->y;
	}
	free(diff);
	free(point);
}

int				printhigh2(t_point **diff, t_point **point, \
				t_point *first, t_point *second)
{
	int			xi;

	xi = 0;
	(*diff)->x = second->x - first->x;
	(*diff)->y = second->y - first->y;
	(*diff)->z = (second->z > first->z) ? (second->z - first->z) : \
											(first->z - second->z);
	xi = 0;
	((*diff)->x < 0) ? (xi -= 1) : (xi = 1);
	((*diff)->x < 0) ? ((*diff)->x = -(*diff)->x) : (xi += 0);
	(*point)->z = 2 * (*diff)->x - (*diff)->y;
	(*point)->y = first->y - 1;
	(*point)->x = first->x;
	return (xi);
}

void			printhigh(t_fdf *fdf, t_point *first, \
					t_point *second, int minimum_altitude)
{
	t_point		*diff;
	t_point		*point;
	int			xi;
	double		color_increment;

	diff = (t_point *)malloc(sizeof(t_point));
	point = (t_point *)malloc(sizeof(t_point));
	xi = printhigh2(&diff, &point, first, second);
	color_increment = diff->z / (second->y - point->y);
	while (++point->y < second->y)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)point->x, \
				(int)point->y, minimum_altitude);
		(point->z > 0) ? (point->x = point->x + xi) : (minimum_altitude += 0);
		(point->z > 0) ? (point->z = point->z - 2 * diff->y) : \
						(minimum_altitude += 0);
		minimum_altitude += color_increment * 200;
		point->z = point->z + 2 * diff->x;
	}
	free(diff);
	free(point);
}

void			printline(t_fdf *fdf)
{
	int			minimum_altitude;

	minimum_altitude = (fdf->first->z > fdf->second->z ? \
						fdf->second->z : fdf->first->z);
	if (ft_positive(fdf->second->y - fdf->first->y) < \
		ft_positive(fdf->second->x - fdf->first->x))
	{
		if (fdf->first->x > fdf->second->x)
			printlow(fdf, fdf->second, fdf->first, \
						minimum_altitude + 9056567);
		else
			printlow(fdf, fdf->first, fdf->second, \
						minimum_altitude + 9056567);
	}
	else
	{
		if (fdf->first->y > fdf->second->y)
			printhigh(fdf, fdf->second, fdf->first, \
						minimum_altitude + 9056567);
		else
			printhigh(fdf, fdf->first, fdf->second, \
						minimum_altitude + 9056567);
	}
}
