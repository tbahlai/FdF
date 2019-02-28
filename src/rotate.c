/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:13:16 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/03 12:25:30 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/keys.h"

void	rotate_po_z(t_fdf *fdf)
{
	fdf->p.angle = 5;
	fdf->p.angle_z = -5;
	fdf->p.angle_y = -30;
}
