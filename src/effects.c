/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:56:11 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/03 11:51:51 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/keys.h"
#include "../includes/fdf.h"
#include "math.h"

int				change_color(t_fdf *fdf)
{
	fdf->color.red += 2000;
	fdf->color.green += 255;
	fdf->color.blue += 255;
	return (0);
}

static	void	draw_hor_line(t_fdf *fdf, int i, int j)
{
	fdf->p.x0 = fdf->p.x_start + (j * fdf->p.step) - \
		(i * fdf->p.angle) + (i * fdf->p.angle_y);
	fdf->p.y0 = fdf->p.y_start + (i * fdf->p.step) - \
		fdf->map.values[i][j] * fdf->p.po_z - \
		(j * fdf->p.angle_z) - (j * fdf->p.angle_y);
	fdf->p.x1 = fdf->p.x_start + ((j + 1) * fdf->p.step) \
		- (i * fdf->p.angle) + (i * fdf->p.angle_y);
	fdf->p.y1 = fdf->p.y_start + ((i) * fdf->p.step) - \
		fdf->map.values[i][j + 1] * fdf->p.po_z - ((j + 1) * \
		fdf->p.angle_z) - ((j + 1) * fdf->p.angle_y);
	give_me_line(fdf);
}

static	void	draw_vert_line(t_fdf *fdf, int i, int j)
{
	fdf->p.x1 = fdf->p.x_start + (j * fdf->p.step) - \
		((i + 1) * fdf->p.angle);
	fdf->p.y1 = fdf->p.y_start + ((i + 1) * fdf->p.step) \
		- fdf->map.values[i + 1][j] * fdf->p.po_z;
	give_me_line(fdf);
}

int				effect(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
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
