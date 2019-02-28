/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:47:35 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/03 11:24:52 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

static	void	vertical_line(t_fdf *fdf, int del_x, int del_y)
{
	int err;

	err = -del_y;
	while (fdf->p.x0 != fdf->p.x1 || fdf->p.y0 != fdf->p.y1)
	{
		mlx_pixel_put(fdf->mlx.init, fdf->mlx.win, \
				fdf->p.x0, fdf->p.y0, fdf->color.red);
		fdf->p.y0 += fdf->p.sign_y;
		err += 2 * del_x;
		if (err > 0)
		{
			err -= 2 * del_y;
			fdf->p.x0 += fdf->p.sign_x;
		}
	}
}

static	void	horizontal_line(t_fdf *fdf, int del_x, int del_y)
{
	int err;

	err = -del_x;
	while (fdf->p.x0 != fdf->p.x1 || fdf->p.y0 != fdf->p.y1)
	{
		mlx_pixel_put(fdf->mlx.init, fdf->mlx.win, \
				fdf->p.x0, fdf->p.y0, fdf->color.red);
		fdf->p.x0 += fdf->p.sign_x;
		err += 2 * del_y;
		if (err > 0)
		{
			err -= 2 * del_x;
			fdf->p.y0 += fdf->p.sign_y;
		}
	}
}

void			give_me_line(t_fdf *fdf)
{
	int del_x;
	int del_y;

	del_x = fabs(fdf->p.x1 - fdf->p.x0);
	del_y = fabs(fdf->p.y1 - fdf->p.y0);
	fdf->p.sign_x = fdf->p.x1 >= fdf->p.x0 ? 1 : -1;
	fdf->p.sign_y = fdf->p.y1 >= fdf->p.y0 ? 1 : -1;
	mlx_pixel_put(fdf->mlx.init, fdf->mlx.win, \
			fdf->p.x0, fdf->p.y0, fdf->color.red);
	if (del_y <= del_x)
		horizontal_line(fdf, del_x, del_y);
	else
		vertical_line(fdf, del_x, del_y);
}
