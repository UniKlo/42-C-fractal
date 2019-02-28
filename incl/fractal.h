/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:41:08 by khou              #+#    #+#             */
/*   Updated: 2019/02/28 00:43:23 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H


/*
** -------------------------- External Headers ---------------------------------
*/

# include "../libft/include/printf.h"
# include "../libft/include/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <pthread.h>

/*
** ----------------------------- Definition ------------------------------------
*/

# define WIN_W 1920
# define WIN_H 1080
# define NBR_THREAD 4

/*
** Keyboard keys
*/

# define ESC_KEY 53
# define MN_KEY 27
# define PL_KEY 24

/*
** Letters keys
*/

# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define Q_KEY 12
# define W_KEY 13
# define E_KEY 14
# define R_KEY 15

/*
** Arrow keys
*/

# define UP_KEY 126
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define LEFT_KEY 123

/*
** Mouse button keycodes
*/

# define BUT1_KEY 1
# define BUT2_KEY 2
# define BUT3_KEY 3
# define SCROLLUP_KEY 4
# define SCROLLDOWN_KEY 5
# define SCROLLLEFT_KEY 6
# define SCROLLRIGHT_KEY 7

/*
** ------------------------- Structure Definition ------------------------------
*/

typedef struct	s_fflag
{
	bool	j;
	bool	m;
}				t_fflag;

typedef struct	s_vct
{
	float		x;
	float		y;
	int		z;
	int			c;
}				t_vct;

typedef struct	s_frame
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_img;
	t_fflag		flag;
	t_vct		**org;
	t_vct		center[2];
}				t_frame;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

int     render(t_frame *frm);
int     deal_key(int key, t_frame *frm);
int     red_close(t_frame *frm);
void	mandelbrot(t_frame *frm);
void	fractal(t_frame *frm);
//void    fractal(t_frame *frm, float left, float top, float xside, float yside);
void    fill_img(t_frame *frm, int x, int y, int a);


#endif
