/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_horizontale_collision.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:46:58 by almarico          #+#    #+#             */
/*   Updated: 2024/11/21 14:27:20 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"
#include <math.h>

static void	distance_calculation(t_ray *ray, t_player *player)
{
	ray->length_horizontal_collision = sqrt(pow((player->pos_y - ray->collision_point.pos_y), 2) + pow((ray->collision_point.pos_x - player->pos_x), 2));
}

static int	check_box(t_ray *ray, t_info *info)
{
	double	x;
	double	y;

	x = floor(ray->collision_point.pos_x / ray->box_size);
	y = floor(ray->collision_point.pos_y / ray->box_size);
	if (info->map->map[(int)fabs(x)][(int)fabs(y)] == '1')
		return (STOP);
	return (CONTINUE);
}

void	calculate_horizontale_collision(t_info *info)
{
	info->ray.collision_point.pos_y = floor(info->map->player->pos_y / info->ray.box_size) * info->ray.box_size;
	info->ray.right_angle.pos_y = info->map->player->pos_y;
	if (info->ray.angle_of_ray.value_of_ray >= M_PI_2 && info->ray.angle_of_ray.value_of_ray < (3 * M_PI_2))
		info->ray.collision_point.pos_x = - (fabs(info->map->player->pos_y - info->ray.collision_point.pos_y) / tan(info->ray.theta)) + info->map->player->pos_x;
	else
		info->ray.collision_point.pos_x = (fabs(info->map->player->pos_y - info->ray.collision_point.pos_y) / tan(info->ray.theta)) + info->map->player->pos_x;
	info->ray.right_angle.pos_x = info->ray.collision_point.pos_x;
	distance_calculation(&info->ray, info->map->player);
	while (check_box(&info->ray, info) == CONTINUE)
	{
		info->ray.collision_point.pos_y += info->ray.box_size / (sin(info->ray.theta));
		info->ray.right_angle.pos_y = info->map->player->pos_y;
		if (info->ray.angle_of_ray.value_of_ray >= M_PI_2 && info->ray.angle_of_ray.value_of_ray < (3 * M_PI_2))
			info->ray.collision_point.pos_x = - (fabs(info->map->player->pos_y - info->ray.collision_point.pos_y) / tan(info->ray.theta)) + info->map->player->pos_x;
		else
			info->ray.collision_point.pos_x = (fabs(info->map->player->pos_y - info->ray.collision_point.pos_y) / tan(info->ray.theta)) + info->map->player->pos_x;
		info->ray.right_angle.pos_x = info->ray.collision_point.pos_x;
		distance_calculation(&info->ray, info->map->player);
	}
}
