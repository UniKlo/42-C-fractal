/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 23:48:13 by khou              #+#    #+#             */
/*   Updated: 2019/02/23 01:49:41 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/*
**need to carry more info about color
*/

void	fill_img(t_frame *frm, int x, int y, int color)
{
/*
	if (a == 0)
		return ;
	if ((y * WIN_W + x) * 4 - 1 < 0 ||
		(y * WIN_W + x) * 4 - 1 > WIN_H * WIN_W * 4)
		return ;*/
	int i = (y * WIN_W + x) * 4 - 1;
	int alpha = (color >> 24) & 0xFF;
	int red = (color >> 16) & 0xFF;
	int green = (color >> 8) & 0xFF;
	int blue =  color & 0xFF;

	frm->data_img[i++] = blue;
	frm->data_img[i++] = green;
	frm->data_img[i++] = red;
	frm->data_img[i++] = alpha;
}
