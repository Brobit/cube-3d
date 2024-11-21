/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_raycasting_result.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:55:18 by almarico          #+#    #+#             */
/*   Updated: 2024/11/20 17:13:00 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void	display_raycasting_result(t_info *info)
{
	int	i;
	int	x;
	int	y;
	int	end;

	i = 0;
	while (i < NUMBER_OF_RAY)
	{
		x = (info->raycasting->ray[i]->angle_of_ray.value_of_ray - info->raycasting->ray[i]->angle_of_ray.min) / (info->raycasting->ray[i]->angle_of_ray.max - info->raycasting->ray[i]->angle_of_ray.min);
		y = info->mlx->height - (info->raycasting->ray[i]->height_to_display / 2);
		end = info->mlx->center_height + (info->raycasting->ray[i]->height_to_display / 2);
		while (y < end)
		{
			if (y > 0 && y < end && y < info->mlx->height && x > 0 && x < info->mlx->width)
				set_pixel_color(info->mlx->img, x, y, COLOR_GREEN);
			y++;
		}
		i++;
	}
}
