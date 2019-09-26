/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:55:35 by pfedosse          #+#    #+#             */
/*   Updated: 2019/09/25 16:29:51 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct			s_str
{
	char				*str;
	struct s_str		*next;
}						t_str;

typedef struct			s_point
{
	double				x;
	double				y;
	double				z;
}						t_point;

typedef struct			s_fdf
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					column;
	int					row;
	int					**intarray;
	t_point				***triplearray;
	t_point				***tripleisoarr;
	t_point				*first;
	t_point				*second;

}						t_fdf;

void					fillzero(t_fdf *fdf);
t_str					*openfile(int argc, char **av);
void					error(char *reason);
t_str					*filllist(t_str *list, char *line);
void					countsize(t_str *list, t_fdf *fdf);
void					intarray(t_fdf *fdf);
void					fillarray(t_str *list, t_fdf *fdf);
void					arraystruct(t_fdf *fdf);
void					createiso(t_fdf *fdf);
void					open_window(t_fdf *fdf);
void					letsprint(t_fdf *fdf);
void					borderlines(t_fdf *fdf);
void					printline(t_fdf *fdf);
int						ft_positive(double num);
void					printhigh(t_fdf *fdf, t_point *first, \
					t_point *second, int minimum_altitude);
int						printhigh2(t_point **diff, \
					t_point **point, t_point *first, t_point *second);
void					printlow(t_fdf *fdf, t_point *first, \
					t_point *second, int minimum_altitude);
int						printlow2(t_point **diff, \
					t_point **point, t_point *first, t_point *second);

#endif
