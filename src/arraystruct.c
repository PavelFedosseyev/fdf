/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraystruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:18:51 by pfedosse          #+#    #+#             */
/*   Updated: 2019/09/25 16:18:55 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		arraystruct2(t_fdf *fdf, int *row, int colomn)
{
	while (*row < fdf->row)
	{
		colomn = 0;
		if (!(fdf->triplearray[*row] = \
			(t_point **)malloc(sizeof(t_point*) * (fdf->column + 1))))
			return ;
		while (colomn < fdf->column)
		{
			if (!(fdf->triplearray[*row][colomn] = \
					(t_point *)malloc(sizeof(t_point))))
				return ;
			fdf->triplearray[*row][colomn]->x = (colomn + 1) * 30;
			fdf->triplearray[*row][colomn]->y = (*row + 1) * 30;
			fdf->triplearray[*row][colomn]->z = \
							(fdf->intarray[*row][colomn]) * 10;
			colomn++;
		}
		fdf->triplearray[*row][colomn] = NULL;
		(*row)++;
	}
}

void		arraystruct(t_fdf *fdf)
{
	int		row;

	row = 0;
	if (!(fdf->triplearray = \
			(t_point ***)malloc(sizeof(t_point **) * (fdf->row + 1))))
		return ;
	arraystruct2(fdf, &row, 0);
	fdf->triplearray[row] = NULL;
}
