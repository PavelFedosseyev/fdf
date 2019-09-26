/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:23:52 by pfedosse          #+#    #+#             */
/*   Updated: 2019/09/25 16:56:04 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int ac, char **av)
{
	t_fdf		fdf;
	t_str		*list;

	list = NULL;
	ft_bzero(&fdf, sizeof(t_fdf));
	fillzero(&fdf);
	list = openfile(ac, av);
	countsize(list, &fdf);
	intarray(&fdf);
	fillarray(list, &fdf);
	arraystruct(&fdf);
	createiso(&fdf);
	open_window(&fdf);
	return (0);
}
