/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:18:50 by khou              #+#    #+#             */
/*   Updated: 2019/02/26 12:24:31 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	recenter(t_frame *frm)
{
	int i;
	int j;

	frm->center[0].x = -1 * (WIN_W / 2);
	frm->center[0].y = -1 * (WIN_H / 2);
	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			frm->org[i][j].x += frm->center[0].x + frm->center[1].x;
			frm->org[i][j].y += frm->center[0].y + frm->center[1].y;
			frm->org[i][j].x = 0.01 * frm->org[i][j].x * 108/192;
			frm->org[i][j].y = 0.01 * frm->org[i][j].y;
//			printf("x: %f, y: %f ", frm->org[i][j].x, frm->org[i][j].y);
			j++;
		}
//		printf("\n");
		i++;
	}
}

void	fractal(t_frame *frm)
{
	int		i = 0;
	int	j;
	
	frm->org = malloc(sizeof(t_vct *) * WIN_H);
	while (i < WIN_H)
	{
		frm->org[i] = malloc(sizeof(t_vct) * WIN_W);
		j = 0;
		while (j < WIN_W)
		{
			frm->org[i][j].x = j;
			frm->org[i][j].y = i;
			frm->org[i][j].z = 0;
			frm->org[i][j].c = 0;
//			printf("I m here in op. i: %d, j: %d\n", i, j);
			j++;
		}
		i++;
	}
	recenter(frm);
	if (frm->flag.j == 1)
		printf("I m here for Julia\n");
	else if (frm->flag.m == 1)
		mandelbrot(frm);
}
