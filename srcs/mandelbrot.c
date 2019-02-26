/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 04:37:39 by khou              #+#    #+#             */
/*   Updated: 2019/02/26 01:02:51 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	op_fractal(t_frame *frm, t_vct *point, int x, int y)
{
	int	x0, y0, tmp, count;

	count = 0;
	x0 = 0;
	y0 = 0;
	while ((x0 * x0 + y0 * y0 < 4) && (count < 10000))
	{
		tmp = x0;
		x0 = x0 * x0 - y0 * y0 + point->x;
		y0 = 2 * tmp * y0 + point->y; 
		count++;
	}
	int color = 0;
	if (count >= 5)
	{
		color = 0x00FFFFFF;
		fill_img(frm, x, y, color);
	}
}

void    mandelbrot(t_frame *frm)
{
	int i;
	int j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			op_fractal(frm, &frm->org[i][j], j , i);//j is col = x, i is row = y 
			j++;
		}
		i++;
	}
}


/*
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
			if (count > 20)
				fill_img(frm, x, y, 0x00707070);
			else if (count > 15)
				fill_img(frm, x, y, 0x00000000);
		
//			printf("x: %d, y: %d, conut: %d\n", x, y, count);
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
*/
