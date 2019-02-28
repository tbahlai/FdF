/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:13:41 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/03 12:03:05 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

void			two_colors(t_fdf *fdf, int i, int j, int n)
{
	if (fdf->color.ind_col == 1)
	{
		if (n != 0 && (fdf->map.values[i][j] != 0))
			fdf->color.red = 16739072;
		else
			fdf->color.red = 5822086;
	}
}

static	void	draw_hor_line(t_fdf *fdf, int i, int j)
{
	fdf->p.x0 = fdf->p.x_start + (j * fdf->p.step) - \
		(i * fdf->p.angle) + (i * fdf->p.angle_y);
	fdf->p.y0 = fdf->p.y_start + (i * fdf->p.step) - fdf->map.values[i][j] \
		* fdf->p.po_z - (j * fdf->p.angle_z) - (j * fdf->p.angle_y);
	fdf->p.x1 = fdf->p.x_start + ((j + 1) * fdf->p.step) - \
		(i * fdf->p.angle) + (i * fdf->p.angle_y);
	fdf->p.y1 = fdf->p.y_start + (i * fdf->p.step) - \
		fdf->map.values[i][j + 1] * fdf->p.po_z - ((j + 1) \
		* fdf->p.angle_z) - ((j + 1) * fdf->p.angle_y);
	two_colors(fdf, i, j, fdf->map.values[i][j]);
	give_me_line(fdf);
}

static	void	draw_vert_line(t_fdf *fdf, int i, int j)
{
	fdf->p.x0 = fdf->p.x_start + (j * fdf->p.step) - \
		(i * fdf->p.angle) + (i * fdf->p.angle_y);
	fdf->p.y0 = fdf->p.y_start + (i * fdf->p.step) - \
		fdf->map.values[i][j] * fdf->p.po_z - ((j) * \
		fdf->p.angle_z) - (j * fdf->p.angle_y);
	fdf->p.x1 = fdf->p.x_start + (j * fdf->p.step) - ((i + 1) * \
		fdf->p.angle) + ((i + 1) * fdf->p.angle_y);
	fdf->p.y1 = fdf->p.y_start + ((i + 1) * fdf->p.step) - \
		fdf->map.values[i + 1][j] * fdf->p.po_z - \
		(j * fdf->p.angle_z) - (j * fdf->p.angle_y);
	two_colors(fdf, i, j, fdf->map.values[i][j]);
	give_me_line(fdf);
}

int				fdf_drawer(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	if (fdf->p.valya != 1)
		initial_values(fdf);
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, \
		1700, 10, 5822086, "Press key 0");
	while (fdf->map.height > i)
	{
		j = 0;
		while (fdf->map.width > j)
		{
			if (j < fdf->map.width - 1)
				draw_hor_line(fdf, i, j);
			if (i < fdf->map.height - 1)
				draw_vert_line(fdf, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
