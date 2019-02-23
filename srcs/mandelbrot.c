/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 04:37:39 by khou              #+#    #+#             */
/*   Updated: 2019/02/23 01:51:50 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	fractal(t_frame *frm, float left, float top, float xside, float yside)
{
	float xscale, yscale, zx, zy, cx, tempx, cy;
	int x, y;
	int maxx, maxy, count;

	maxx = WIN_W;
	maxy = WIN_H;
	xscale = xside / maxx;
	yscale = yside / maxy;
	y = 1;
	while (y < maxy)
	{
		x = 1;
		while (x < maxx)
		{
			cx = x * xscale + left;
			cy = y * yscale + top;
			zx = 0;
			zy = 0;
			count = 0;
			while ((zx * zx + zy * zy < 4) && (count < 10000))
			{
				tempx = zx * zx - zy * zy + cx;
				zy = 2 * zx * zy + cy;
				zx = tempx;
				count = count + 1; 
            }
			fill_img(frm, x, y, count);
			x++;
		}
		y++;
	}
}

void	mandelbrot(t_frame *frm)
{
	float	left = -1.75;
	float	top = -0.25;
	float	xside = 0.25;
	float	yside = 0.45;
	fractal(frm, left, top, xside, yside);
}
