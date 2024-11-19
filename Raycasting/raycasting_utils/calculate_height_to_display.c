/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_height_to_display.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:47:03 by almarico          #+#    #+#             */
/*   Updated: 2024/11/19 14:44:44 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void	calculate_height_to_display(t_ray *ray, t_info *info)
{
	double	pwp;

	pwp = info->mlx->center_width / tan(ray->theta / 2);
	ray->height_to_display = ray->box_size * (pwp / ray->shortest_lenght);
}
