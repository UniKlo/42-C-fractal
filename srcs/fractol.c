/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:17:13 by khou              #+#    #+#             */
/*   Updated: 2019/02/21 23:49:51 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void	error_usage()
{
	ft_printf("usage:  ./fractol [jm]\nmodels: j - julia\n        \
m - mandelbrot\n        X - XXX\n        X - XXXX\n");
}

void	error_arg(int argc, char **argv)
{
	if (argc < 2)
	{
		error_usage();
		exit(0);
	}
	int	i = 1;
	while (i < argc)
	{
//		ft_printf("%c\n", *argv[i]);
		if (*argv[i] == 'j' || *argv[i] == 'm')
			;
		else
			error_usage();
		i++;
	}
}
int		main(int argc, char **argv)
{
//error management for argv
	t_frame frm;
	int		bpp;
	int		size_line;
	int		endian;
	
	error_arg(argc, argv);
	frm.mlx = mlx_init();
	frm.win = mlx_new_window(frm.mlx, WIN_W, WIN_H, "The VIEW");
	frm.img = mlx_new_image(frm.mlx, WIN_W, WIN_H);
	frm.data_img = mlx_get_data_addr(frm.img, &bpp, &size_line, &endian);
	if (!frm.mlx || !frm.win || !frm.img || !frm.data_img)
		exit(0);
	mlx_hook(frm.win, 2, 0, deal_key, &frm);
//	mlx_hook(frm.win, 4, 0, deal_mouse, &frm);
	mlx_hook(frm.win, 17, 0, red_close, &frm);
//	mlx_loop_hook(frm.mlx, render, &frm);
	mlx_loop(frm.mlx);
	return (0);
}
