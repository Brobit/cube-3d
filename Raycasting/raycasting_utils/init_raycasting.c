/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:44:49 by almarico          #+#    #+#             */
/*   Updated: 2024/11/17 19:24:06 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static void	fill_each_ray(t_raycasting *raycasting)
{
	int	i;

	i = 0;
	while (i < NUMBER_OF_RAY)
	{
		raycasting->ray[i]->angle_of_ray.min = \
			raycasting->player->angle * -M_PI / 6;
		raycasting->ray[i]->angle_of_ray.max = \
			raycasting->player->angle * M_PI / 6;
		raycasting->ray[i]->theta = \
			raycasting->player->fov_width / (NUMBER_OF_RAY - 1);
		raycasting->ray[i]->angle_of_ray.value_of_ray = \
			(M_PI / 3.0) + (i * raycasting->ray[i]->theta);
		raycasting->ray[i]->box_size = 128;
		i++;
	}
}

static int	init_each_ray(t_raycasting *raycasting)
{
	int	i;

	raycasting->ray = malloc((NUMBER_OF_RAY + 1) * sizeof(t_ray *));
	if (!raycasting->ray)
		return (FAIL);
	raycasting->ray[NUMBER_OF_RAY] = NULL;
	i = 0;
	while (i < NUMBER_OF_RAY)
	{
		raycasting->ray[i] = malloc(sizeof(t_ray));
		if (!raycasting->ray[i])
			return (free_raycasting(raycasting), FAIL);
		i++;
	}
	raycasting->player->fov_width = M_PI / 3.0;
	fill_each_ray(raycasting);
	return (SUCCESS);
}

int	init_raycasting(t_info *info)
{
	info->raycasting->player = info->map->player;
	if (info->raycasting->player->direction == NORTH)
		info->raycasting->player->angle = M_PI_2;
	else if (info->raycasting->player->direction == WEST)
		info->raycasting->player->angle = M_PI;
	else if (info->raycasting->player->direction == SOUTH)
		info->raycasting->player->angle = 3.0 * M_PI / 2.0;
	else if (info->raycasting->player->direction == EAST)
		info->raycasting->player->angle = 0;
	if (init_each_ray(info->raycasting) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
