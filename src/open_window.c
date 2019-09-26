/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:23:58 by pfedosse          #+#    #+#             */
/*   Updated: 2019/09/25 16:31:40 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		esc(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

void	open_window(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1524, 1524, "FDF");
	letsprint(fdf);
	mlx_hook(fdf->win_ptr, 17, 0, close_window, (void *)0);
	mlx_hook(fdf->win_ptr, 2, 0, esc, (void *)0);
	mlx_loop(fdf->mlx_ptr);
}
