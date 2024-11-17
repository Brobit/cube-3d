/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_entry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:17:07 by almarico          #+#    #+#             */
/*   Updated: 2024/11/16 17:57:19 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	raycasting_entry(t_map_param *map)
{
	t_window	*mlx;

	mlx = malloc(sizeof(t_window));
	if (!mlx)
		return (write_message(ERR_MALLOC), FAIL);
	if (init_display(mlx) == FAIL || display(mlx, map) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
