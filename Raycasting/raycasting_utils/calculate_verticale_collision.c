/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_verticale_collision.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:47:07 by almarico          #+#    #+#             */
/*   Updated: 2024/11/19 18:00:19 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static void	distance_calculation(t_ray *ray, t_player *player)
{
	ray->length_vertical_collision = sqrt(pow((player->pos_y - ray->collision_point.pos_y), 2) + pow((ray->collision_point.pos_x - player->pos_x), 2));
}

static int	check_box(t_ray *ray, t_info *info)
{
	double	x;
	double	y;

	x = ceil(ray->collision_point.pos_x / ray->box_size);
	y = ceil(ray->collision_point.pos_y / ray->box_size);
	if (info->map->map[(int)x][(int)y] == '1')
		return (STOP);
	return (CONTINUE);
}

void	calculate_verticale_collision(t_ray *ray, t_player *player, t_info *info)
{
	ray->collision_point.pos_x = ceil(player->pos_x / ray->box_size) * ray->box_size;
	ray->right_angle.pos_x = ray->collision_point.pos_x;
	ray->right_angle.pos_y = player->pos_y;
	if (ray->angle_of_ray.value_of_ray > 0 && ray->angle_of_ray.value_of_ray <= M_PI)
		ray->collision_point.pos_y = player->pos_y + fabs(ray->collision_point.pos_x - player->pos_x) * tan(ray->theta);
	else
		ray->collision_point.pos_y = player->pos_y - fabs(ray->collision_point.pos_x - player->pos_x) * tan(ray->theta);
	distance_calculation(ray, player);
	while (check_box(ray, info) == CONTINUE)
	{
		ray->collision_point.pos_x += ray->box_size / (cos(ray->theta));
		ray->right_angle.pos_x = ray->collision_point.pos_x;
		ray->right_angle.pos_y = player->pos_y;
		if (ray->angle_of_ray.value_of_ray > 0 && ray->angle_of_ray.value_of_ray <= M_PI)
			ray->collision_point.pos_y = player->pos_y + fabs(ray->collision_point.pos_x - player->pos_x) * tan(ray->theta);
		else
			ray->collision_point.pos_y = player->pos_y - fabs(ray->collision_point.pos_x - player->pos_x) * tan(ray->theta);
		distance_calculation(ray, player);
	}
}
