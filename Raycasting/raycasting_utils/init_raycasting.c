/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:44:49 by almarico          #+#    #+#             */
/*   Updated: 2024/11/21 13:22:13 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

// static void	fill_each_ray(t_raycasting *raycasting)
// {
// 	int	i;
//
// 	i = 0;
// 	while (i < NUMBER_OF_RAY)
// 	{
// 		raycasting->ray[i]->angle_of_ray.min = \
// 			raycasting->player->angle * -M_PI / 6;
// 		raycasting->ray[i]->angle_of_ray.max = \
// 			raycasting->player->angle * M_PI / 6;
// 		raycasting->ray[i]->theta = \
// 			raycasting->player->fov_width / (NUMBER_OF_RAY - 1);
// 		raycasting->ray[i]->angle_of_ray.value_of_ray = \
// 			(M_PI / 3.0) + (i * raycasting->ray[i]->theta);
// 		raycasting->ray[i]->box_size = 180;
// 		i++;
// 	}
// }

// static int	init_ray(t_info *info)
// {
// 	int	i;
//
// 	info->ray.theta = info->map->player->angle - ANGLE_FOV / 2;
// 	i = info->mlx->width -1;
// 	while (i >= 0)
// 	{
// 		raycasting->ray[i] = malloc(sizeof(t_ray));
// 		if (!raycasting->ray[i])
// 			return (free_raycasting(raycasting), FAIL);
// 		i++;
// 	}
// 	raycasting->player->fov_width = M_PI / 3.0;
// 	fill_each_ray(raycasting);
// 	return (SUCCESS);
// }

int	init_raycasting(t_info *info)
{
	if (info->map->player->direction == NORTH)
		info->map->player->angle = M_PI_2;
	else if (info->map->player->direction == WEST)
		info->map->player->angle = M_PI;
	else if (info->map->player->direction == SOUTH)
		info->map->player->angle = 3.0 * M_PI / 2.0;
	else if (info->map->player->direction == EAST)
		info->map->player->angle = 0;
	// if (init_ray(info) == FAIL)
		// return (FAIL);
	return (SUCCESS);
}
