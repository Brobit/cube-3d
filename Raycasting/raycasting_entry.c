/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_entry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:17:07 by almarico          #+#    #+#             */
/*   Updated: 2024/11/16 14:09:26 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	raycasting_entry(t_map_param *map)
{
	t_window	*mlx;

	mlx = malloc(sizeof(t_window));
	if (!mlx)
		return (write_message(ERR_MALLOC), FAIL);
	init_display(mlx);
	display(mlx, map);
	return (SUCCESS);
}
