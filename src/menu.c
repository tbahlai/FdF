/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:57:38 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/03 12:13:24 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/keys.h"
#include "../includes/fdf.h"

void	menu(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 1450, 1020, 5822086,
		"move:              1, 2, 3, 5");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 1450, 1040, 5822086,
		"grow up/grow down: W/S");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 1450, 1060, 5822086,
		"zoom and rotation: arrows up, down, left and right");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 1450, 1080, 5822086,
		"projection:        SPACE");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 1450, 1100, 5822086,
		"some interesting:  O");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 1450, 1120, 5822086,
		"two colors:        L");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 1450, 1140, 5822086,
		"change color:      C");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 1450, 1160, 5822086,
		"reset:             ENTER");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 1450, 1180, 5822086,
		"exit:              (X) or ESC");
}
