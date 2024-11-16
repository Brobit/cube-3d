/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:52:49 by almarico          #+#    #+#             */
/*   Updated: 2024/11/16 15:40:56 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft-complete/libft/libft.h"
# include "../libft-complete/printf/ft_printf.h"
# include "../libft-complete/get_next_line/gnl.h"

/* general & error defines */
# define SUCCESS					0
# define FAIL						1
# define STDIN						0
# define STDOUT						1
# define STDERR						2

/* mlx event define */
# define ON_KEYDOWN					2
# define ON_KEYUP					3
# define ON_MOUSEDOWN				4
# define ON_MOUSEUP					5
# define ON_MOUSEMOVE				6
# define ON_EXPOSE					12
# define ON_DESTROY					17

/* color defines */
# define COLOR_RED					0xFF0000
# define COLOR_GREEN				0x00FF00
# define COLOR_BLUE					0x0000FF
# define COLOR_GREY					0x999999
# define DEFAULT_COLOR_VALUE		0xF000FF
# define COLOR_LIGHT_BLUE			0x6BA6B5

/* error define */
# define ERR_MALLOC					"An error occured during the malloc\n"

/* map & player structure */
typedef enum e_facing
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}			t_facing;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	t_facing		direction;
}				t_player;

typedef struct s_map_param
{
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			floor_color[3];
	int			ceiling_color[3];
	char		**map;
	t_player	*player;
}				t_map_param;

/* mlx structure */
typedef struct s_img_info
{
	void			*img_ptr;
	char			*img_data_address;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}				t_img_info;

typedef struct s_window
{
	void			*init_ptr;
	void			*window;
	int				width;
	int				height;
	int				center_width;
	int				center_height;
	t_img_info		img;
}				t_window;

/* general structure */
typedef struct s_info
{
	t_window			*mlx;
	t_map_param			*map;
}				t_info;

/* raycasting_structure */

typedef struct s_coordonate
{
	double				pos_x;
	double				pos_y;
}				t_coordonate;

typedef struct s_raycasting
{
	t_player			*p;
	t_coordonate		*a;
	t_coordonate		*b;
}				t_raycasting;

/* raycasting_entry.c */
int							raycasting_entry(t_map_param *info);

/* init_mlx.c */
int							init_display(t_window *mlx);
int							display(t_window *mlx, t_map_param *map);

/* image_handler.c */
void						image_handler(t_window *mlx);

/* event_handler.c */
int							closes(t_info *info);
int							key_handler(int keycode, t_info *info);
void						destroy_image(t_window *mlx);
void						redraw_window(t_window *mlx);
void						event_handler(t_window *mlx, t_map_param *map);

/* fill_image.c */
void						fill_image(t_window *mlx, t_map_param *map);

/* color_writing.c */
void						set_pixel_color(t_img_info img, int pos_x, int pos_y, int color);
void						fill_background(t_window *mlx);
void						draw_wall(t_window *mlx, t_map_param *map);

/* utils.c */
void						free_map(t_map_param *map);
void						write_message(const char *msg);

#endif // !CUB3D_H
