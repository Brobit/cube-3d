/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_shortest_length_of_ray.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:47:12 by almarico          #+#    #+#             */
/*   Updated: 2024/11/19 11:21:05 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void	set_shortest_length_of_ray(t_ray *ray)
{
	if (ray->length_vertical_collision > ray->length_horizontal_collision)
		ray->shortest_lenght = ray->length_horizontal_collision;
	else
		ray->shortest_lenght = ray->length_vertical_collision;
}
