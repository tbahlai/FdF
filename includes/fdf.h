/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 10:58:08 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/03 12:32:03 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../lib/libft.h"
# include "mlx.h"
# include <stdio.h>
# define MAX_WID 2000
# define MAX_H 1200

typedef	struct	s_point
{
	int		x_start;
	int		y_start;
	int		x_end;
	int		y_end;
	double	x0;
	double	y0;
	double	x1;
	double	y1;
	int		sign_x;
	int		sign_y;
	double	angle;
	int		valya;
	double	step;
	double	angle_z;
	double	angle_y;
	int		po_z;
}				t_point;

typedef struct	s_color
{
	int red;
	int green;
	int blue;
	int ind_col;
}				t_color;

typedef struct	s_map
{
	int width;
	int	height;
	int	**values;
}				t_map;

typedef struct	s_mlx
{
	void	*init;
	void	*win;
}				t_mlx;

typedef struct	s_fdf
{
	t_mlx	mlx;
	t_map	map;
	t_point	p;
	t_color	color;
}				t_fdf;

void			rotate_po_z(t_fdf *fdf);
void			ft_puterror(char *error, int ret);
int				*fdf_reader(char *argv, t_fdf *fdf);
void			map_in_int(char **map, t_fdf *fdf);
int				fdf_drawer(t_fdf *fdf);
void			give_me_line(t_fdf *fdf);
void			initial_values(t_fdf *fdf);
int				effect(t_fdf *fdf);
void			two_colors(t_fdf *fdf, int i, int j, int n);
void			menu(t_fdf *fdf);
int				change_color(t_fdf *fdf);

#endif
