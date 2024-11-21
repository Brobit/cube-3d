/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calculation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:34:11 by almarico          #+#    #+#             */
/*   Updated: 2024/11/21 13:34:12 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static	void	check_angle(t_ray *ray)
{
	while (ray->theta < 0 || ray->theta >= M_2_PI)
	{
		if (ray->theta < 0)
			ray->theta += M_2_PI;
		else
			ray->theta -= M_2_PI;
	}
}

void	raycasting_calculation(t_info *info)
{
	int	i;

	i = 0;
	info->ray.theta = info->map->player->angle - ANGLE_FOV / 2;
	while (i >= 0)
	{
		check_angle(&info->ray);
		calculate_horizontale_collision(info);
		calculate_verticale_collision(info);
		set_shortest_length_of_ray(&info->ray);
		calculate_height_to_display(info);
		i++;
	}
}
