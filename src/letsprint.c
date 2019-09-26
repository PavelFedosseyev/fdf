/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:08:10 by pfedosse          #+#    #+#             */
/*   Updated: 2019/09/25 16:17:54 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	borderlines(t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < fdf->row - 1)
	{
		fdf->first->x = fdf->tripleisoarr[i][fdf->column - 1]->x;
		fdf->first->y = fdf->tripleisoarr[i][fdf->column - 1]->y;
		fdf->first->z = fdf->tripleisoarr[i][fdf->column - 1]->z;
		fdf->second->x = fdf->tripleisoarr[i + 1][fdf->column - 1]->x;
		fdf->second->y = fdf->tripleisoarr[i + 1][fdf->column - 1]->y;
		fdf->second->z = fdf->tripleisoarr[i + 1][fdf->column - 1]->z;
		printline(fdf);
		i++;
	}
	i = 0;
	while (i < fdf->column - 1)
	{
		fdf->first->x = fdf->tripleisoarr[fdf->row - 1][i]->x;
		fdf->first->y = fdf->tripleisoarr[fdf->row - 1][i]->y;
		fdf->first->z = fdf->tripleisoarr[fdf->row - 1][i]->z;
		fdf->second->x = fdf->tripleisoarr[fdf->row - 1][i + 1]->x;
		fdf->second->y = fdf->tripleisoarr[fdf->row - 1][i + 1]->y;
		fdf->second->z = fdf->tripleisoarr[fdf->row - 1][i + 1]->z;
		printline(fdf);
		i++;
	}
}

void	letsprint(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->row - 1)
	{
		j = 0;
		while (j < fdf->column - 1)
		{
			fdf->first->x = fdf->tripleisoarr[i][j]->x;
			fdf->first->y = fdf->tripleisoarr[i][j]->y;
			fdf->first->z = fdf->tripleisoarr[i][j]->z;
			fdf->second->x = fdf->tripleisoarr[i + 1][j]->x;
			fdf->second->y = fdf->tripleisoarr[i + 1][j]->y;
			fdf->second->z = fdf->tripleisoarr[i + 1][j]->z;
			printline(fdf);
			fdf->second->x = fdf->tripleisoarr[i][j + 1]->x;
			fdf->second->y = fdf->tripleisoarr[i][j + 1]->y;
			fdf->second->z = fdf->tripleisoarr[i][j + 1]->z;
			printline(fdf);
			j++;
		}
		i++;
	}
	borderlines(fdf);
}
