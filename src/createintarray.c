/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createintarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:24:43 by pfedosse          #+#    #+#             */
/*   Updated: 2019/09/25 16:23:39 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fillarray(t_str *list, t_fdf *fdf)
{
	int			row;
	int			column;
	int			count;
	t_str		*tmp;

	tmp = list;
	row = 0;
	while (tmp)
	{
		column = 0;
		count = 0;
		while (tmp->str[count])
		{
			fdf->intarray[row][column] = ft_atoi(&tmp->str[count]);
			while (tmp->str[count] != ' ' && tmp->str[count] != '\0')
				count++;
			while (tmp->str[count] == ' ' && tmp->str[count] != '\0')
				count++;
			column++;
		}
		row++;
		tmp = tmp->next;
	}
}

void		intarray(t_fdf *fdf)
{
	int		i;

	i = 0;
	if (!(fdf->intarray = (int**)malloc(sizeof(int*) * fdf->row)))
		return ;
	while (i < fdf->row)
	{
		if (!(fdf->intarray[i] = (int*)malloc(sizeof(int) * fdf->column)))
			return ;
		i++;
	}
}

void		countsize(t_str *list, t_fdf *fdf)
{
	int		i;

	i = 0;
	fdf->column = 0;
	fdf->row = 0;
	while (list->str[i])
	{
		if (list->str[i] != ' ' && list->str[i] != '\0')
		{
			fdf->column++;
			while (list->str[i] != ' ' && list->str[i] != '\0')
				i++;
			while (list->str[i] == ' ')
				i++;
		}
	}
	while (list)
	{
		fdf->row++;
		list = list->next;
	}
}
