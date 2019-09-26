/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createiso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:19:17 by pfedosse          #+#    #+#             */
/*   Updated: 2019/09/25 16:34:32 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		createiso2(t_fdf *fdf, int *row, int column)
{
	while (*row < fdf->row)
	{
		column = 0;
		if (!(fdf->tripleisoarr[*row] = \
			(t_point **)malloc(sizeof(t_point*) * (fdf->column + 1))))
			return ;
		while (column < fdf->column)
		{
			if (!(fdf->tripleisoarr[*row][column] = \
				(t_point *)malloc(sizeof(t_point))))
				return ;
			fdf->tripleisoarr[*row][column]->x = \
							400 + ((fdf->triplearray[*row][column]->x \
				- fdf->triplearray[*row][column]->y) * cos(0.523599));
			fdf->tripleisoarr[*row][column]->y = \
				150 + (((fdf->triplearray[*row][column]->x \
				+ fdf->triplearray[*row][column]->y) * sin(0.523599)) \
				- fdf->triplearray[*row][column]->z);
			fdf->tripleisoarr[*row][column]->z = \
				fdf->triplearray[*row][column]->z;
			column++;
		}
		fdf->tripleisoarr[*row][column] = NULL;
		(*row)++;
	}
}

void		createiso(t_fdf *fdf)
{
	int		row;
	int		column;

	row = 0;
	column = 0;
	if (!(fdf->tripleisoarr = \
		(t_point ***)malloc(sizeof(t_point **) * (fdf->row + 1))))
		return ;
	createiso2(fdf, &row, column);
	fdf->tripleisoarr[row] = NULL;
}
