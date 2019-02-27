/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:57:34 by khou              #+#    #+#             */
/*   Updated: 2019/02/26 15:57:36 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	error_usage()
{
	ft_printf("usage:  ./fractol [jm]\nmodels: j - julia\n        \
m - mandelbrot\n        X - XXX\n        X - XXXX\n");
	exit(0);
}

void	error_arg(t_fflag *flag,int argc, char **argv)
{
	flag->j = 0;
	flag->m = 0;
	if (argc < 2)
		error_usage();
	int	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp("mandelbrot", argv[i]) || !ft_strcmp("m", argv[i]))
			flag->m = 1;
		else if (!ft_strcmp("julia", argv[i]) || !ft_strcmp("j", argv[i]))
			flag->j = 1;
		else
			error_usage();
		i++;
	}
}

void	frame_init(t_frame *frm)
{
//	frm->ai_z.x = 0;
//	frm->ai_z.y = 0;
	frm->center[0].x = 0;
	frm->center[0].y = 0;
	frm->center[0].z = 0;
	frm->center[1].x = 0;
	frm->center[1].y = 0;
	frm->center[1].z = 0;
//	frm->ang.x = 5;
//	frm->ang.y = 5;
//	frm->ang.z = 5;
}

int		main(int argc, char **argv)
{
	t_frame frm;
	int		bpp;
	int		size_line;
	int		endian;
//-- error management for argv ----
	error_arg(&frm.flag, argc, argv);
	frame_init(&frm);
	printf("Mian: j: %d, m: %d\n", frm.flag.j, frm.flag.m);
	frm.mlx = mlx_init();
	frm.win = mlx_new_window(frm.mlx, WIN_W, WIN_H, "The VIEW");
	frm.img = mlx_new_image(frm.mlx, WIN_W, WIN_H);
	frm.data_img = mlx_get_data_addr(frm.img, &bpp, &size_line, &endian);
	if (!frm.mlx || !frm.win || !frm.img || !frm.data_img)
		exit(0);
	printf("endian: %d\n", endian);


	mlx_hook(frm.win, 2, 0, deal_key, &frm);
//	mlx_hook(frm.win, 4, 0, deal_mouse, &frm);
	mlx_hook(frm.win, 17, 0, red_close, &frm);
	mlx_loop_hook(frm.mlx, render, &frm);
	mlx_loop(frm.mlx);
	return (0);
}
