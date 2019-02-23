/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:37:12 by khou              #+#    #+#             */
/*   Updated: 2019/02/23 02:18:26 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	instruction(t_frame *m)
{
	mlx_string_put(m->mlx, m->win, 0, 0, 0x00c3d1, "Instructions: ");
	mlx_string_put(m->mlx, m->win, 0, 20, 0x01858e, "Zoom in/out: mouse wheel");
	mlx_string_put(m->mlx, m->win, 0, 40, 0x01858e,
				"Reposition: key <up down left right> arrows");
	mlx_string_put(m->mlx, m->win, 0, 60, 0x01858e,
				"Change altitude: key <+ ->");
	mlx_string_put(m->mlx, m->win, 0, 80, 0x01858e, "Rotate x: key <W S>");
	mlx_string_put(m->mlx, m->win, 0, 100, 0x01858e, "Rotate y: key <A D>");
	mlx_string_put(m->mlx, m->win, 0, 120, 0x01858e, "Rotate z: key <Q E>");
	mlx_string_put(m->mlx, m->win, 0, 140, 0x01858e, "Reset: key <R>");
	mlx_string_put(m->mlx, m->win, 0, 160, 0x01858e,
				"Exit: click reb button / key <ESC>");
}

void	clear_img(t_frame *frm)
{
	int		i = 0;
	while (i < WIN_W * WIN_H * 4)
	{
		int color = 0x00FFFFFF;	
		int alpha = (color >> 24) & 0xFF;
		int red = (color >> 16) & 0xFF;
		int green = (color >> 8) & 0xFF;
		int blue =  color & 0xFF;


		frm->data_img[i++] = blue;
		frm->data_img[i++] = green;
		frm->data_img[i++] = red;
		frm->data_img[i++] = alpha;
	}
}


int		render(t_frame *frm, t_fflag *flag)
{
	clear_img(frm);
	(void) flag;
/*
	if (flag->j)
		;
	else if (flag->m)
		mandelbrot(frm);
*/
//	scale(frm);
//	rotate(frm);
//	project(frm);
//	recenter(frm);
//	draw_img(frm);
	mlx_put_image_to_window(frm->mlx, frm->win, frm->img, 0, 0);
	instruction(frm);
	return (0);
}
