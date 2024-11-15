/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_entry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:17:07 by almarico          #+#    #+#             */
/*   Updated: 2024/11/15 17:02:15 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	raycasting_entry(t_map_param *map)
{
	// t_info		*info;
	t_window	*mlx;

	// info = malloc(sizeof(t_info));
	// mlx = malloc(sizeof(t_window));
	// if (!mlx || !info)
	// 	return (write_message(ERR_MALLOC), FAIL);
	// info->mlx = mlx;
	// info->map = map;
	// init_display(info->mlx);
	// display(info->mlx, info->map);
	// info = malloc(sizeof(t_info));
	mlx = malloc(sizeof(t_window));
	if (!mlx)
		return (write_message(ERR_MALLOC), FAIL);
	init_display(mlx);
	display(mlx, map);
	return (SUCCESS);
}
