/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 23:45:11 by khou              #+#    #+#             */
/*   Updated: 2019/02/23 01:20:09 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		deal_key(int key, t_frame *frm)
{
	ft_printf("pressed a key-------------------\n");
	key == ESC_KEY ? red_close(frm) : 0;
	return (0);
}


int		red_close(t_frame *frm)
{
	mlx_destroy_image(frm->mlx, frm->img);
	exit(0);
	return (0);
}
