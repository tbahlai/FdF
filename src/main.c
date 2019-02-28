/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 12:40:44 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/03 12:10:28 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/keys.h"

void		initial_values(t_fdf *fdf)
{
	fdf->p.x_start = 450;
	fdf->p.y_start = 250;
	fdf->p.x_end = 270;
	fdf->p.angle = 0;
	fdf->p.y_end = 270;
	fdf->p.valya = 1;
	fdf->p.step = 5;
	fdf->p.po_z = 0;
	fdf->color.red = 5822086;
	fdf->color.green = 5822086;
	fdf->color.blue = 5822086;
	fdf->p.angle_z = 0;
	fdf->p.angle_y = 0;
	fdf->color.ind_col = 0;
}

static	int	fdf_keys(int keycode, t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
	ANG1(keycode);
	ANG2(keycode);
	ESCAPE(keycode);
	KEY_ENTER(keycode);
	STEP(keycode);
	STEP1(keycode);
	DEPL(keycode);
	DEPL1(keycode);
	DEPL_X(keycode);
	DE2(keycode);
	DEPL_Y(keycode);
	DE(keycode);
	COLOR(keycode);
	EFFECT(keycode);
	TWO_COLORS(keycode);
	MENU(keycode);
	ROT(keycode);
	fdf_drawer(fdf);
	return (0);
}

static	int	destroy(void)
{
	exit(0);
}

int			main(int ac, char *av[])
{
	t_fdf	*fdf;

	if (ac == 2)
	{
		fdf = (t_fdf*)malloc(sizeof(t_fdf));
		fdf->mlx.init = mlx_init();
		fdf->mlx.win = mlx_new_window(fdf->mlx.init, 2000, 1200, "fdf");
		fdf_reader(av[1], fdf);
		fdf_drawer(fdf);
		mlx_hook(fdf->mlx.win, 2, 0, fdf_keys, fdf);
		mlx_hook(fdf->mlx.win, 17, 0, destroy, NULL);
		mlx_loop(fdf->mlx.init);
	}
	else
	{
		ft_putstr("Give me valid file");
	}
	return (0);
}
