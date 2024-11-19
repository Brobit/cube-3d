/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calculation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:34:11 by almarico          #+#    #+#             */
/*   Updated: 2024/11/19 14:42:22 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void	raycasting_calculation(t_info *info)
{
	int	i;

	i = 0;
	while (i < NUMBER_OF_RAY)
	{
		calculate_horizontale_collision(info->raycasting->ray[i], info->raycasting->player, info);
		calculate_verticale_collision(info->raycasting->ray[i], info->raycasting->player, info);
		set_shortest_length_of_ray(info->raycasting->ray[i]);
		calculate_height_to_display(info->raycasting->ray[i], info);
		i++;
	}
}
