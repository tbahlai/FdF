/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:02:32 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/03 13:08:31 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H
# define KEY_ENTER(l) if (l == 36) initial_values(fdf);
# define ESCAPE(l) if (l == 53) exit (0);
# define ANG1(l) if ((l == 123) && (fdf->p.angle <= 20)){fdf->p.angle += 15;}
# define ANG2(l) if ((l == 124) && fdf->p.angle >= -20){fdf->p.angle -= 15;}
# define STEP(l) if (l == 126){fdf->p.step += 1;}
# define STEP1(l) if (l == 125){fdf->p.step -= 1;}
# define DEPL(l) if ((l == 13 && fdf->p.po_z <= 7)){fdf->p.po_z += 1;}
# define DEPL1(l) if(l == 1 && (fdf->p.po_z >= -7)){fdf->p.po_z -= 1;}
# define DEPL_X(l) if ((l == 85)) {fdf->p.x_start += 40;}
# define DE2(l) if ((l == 83) && (fdf->p.x_start >= 15)){fdf->p.x_start -= 40;}
# define DEPL_Y(l) if ((l == 84) && (fdf->p.y_start)){fdf->p.y_start += 40;}
# define DE(l) if ((l == 87) &&	(fdf->p.y_start >= 40)){fdf->p.y_start -= 40;}
# define COLOR(l) if (l == 8) change_color(fdf);
# define EFFECT(l) if (l == 31) effect(fdf);
# define TWO_COLORS(l) if (l == 37) fdf->color.ind_col = 1;
# define MENU(l) if (l == 82) menu(fdf);
# define ROT(l) if (l == 49) rotate_po_z(fdf);

#endif
