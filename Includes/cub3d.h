/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:52:49 by almarico          #+#    #+#             */
/*   Updated: 2024/11/07 15:56:38 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SUCCESS					0
# define FAIL						1

# include <stdlib.h>

typedef enum e_facing
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}			t_facing;

typedef struct s_player
{
	int			pos_x;
	int			pos_y;
	t_facing	direction;
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

/* raycasting_entry.c */
int							raycasting_entry(t_map_param *info);

#endif // !CUB3D_H
