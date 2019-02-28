/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:37:12 by khou              #+#    #+#             */
/*   Updated: 2019/02/28 01:02:22 by khou             ###   ########.fr       */
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

//void	paint_bg(t_frame *frm)
void	paint_bg(t_frame *frm, int id, int thread_size)
{
	int		i = 0;
//	printf("I m in paint\n");
	while (i < thread_size)
	{
		int color = 0x00FFFFFF;	
		int alpha = (color >> 24) & 0xFF;
		int red = (color >> 16) & 0xFF;
		int green = (color >> 8) & 0xFF;
		int blue =  color & 0xFF;


		frm->data_img[id++] = blue;
		frm->data_img[id++] = green;
		frm->data_img[id++] = red;
		frm->data_img[id++] = alpha;
		i++;
/*
		data_img[i++] = blue;
		data_img[i++] = green;
		data_img[i++] = red;
		data_img[i] = alpha;
*/
	}
}


void	*op_thread(void *arg)
{
	t_frame *frm;
	int	thread_size;
	int		id;
	static int	i = 0;

	frm = (t_frame *)arg;
	if (i == NBR_THREAD)
		i = 0;
	thread_size = WIN_W * WIN_H * 4 / NBR_THREAD;
	id = thread_size * i;
	printf("op_thread: before i: %d,  id: %d\n", i, id);
//	paint_bg(&frm->data_img[id], thread_size);
	paint_bg(frm, id, thread_size);
//	printf("after  i: %d,  id: %d\n", i, id);

//	fractal(frm);
	i++;

//	printf("i: %d\n", i);
	pthread_exit(0);
}

int		render(t_frame *frm)
{
	pthread_t	thread[NBR_THREAD];

	int	i = 0;
	while (i < NBR_THREAD)
	{
		pthread_create(&thread[i], NULL, op_thread, frm);
		i++;
	}
	i = 0;
	while (i < NBR_THREAD)
	{
		pthread_join(thread[i], NULL);
		i++;
	}

//	mandelbrot(frm);
//	printf("Render: j: %d, m: %d\n", flag->j, flag->m);//keep changes value
//	scale(frm);
//	rotate(frm);
//	project(frm);
//	recenter(frm);
//	draw_img(frm);
	mlx_put_image_to_window(frm->mlx, frm->win, frm->img, 0, 0);
	instruction(frm);
	return (0);
}
