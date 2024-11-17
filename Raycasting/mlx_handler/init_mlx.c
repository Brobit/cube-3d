/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:28:28 by almarico          #+#    #+#             */
/*   Updated: 2024/11/16 17:55:44 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

int	init_display(t_window *mlx)
{
	mlx->width = 1280;
	mlx->height = 720;
	mlx->center_width = mlx->width / 2 - 1;
	mlx->center_height = mlx->height / 2 - 1;
	mlx->init_ptr = mlx_init();
	if (!mlx->init_ptr)
		return (FAIL);
	mlx->window = mlx_new_window(mlx->init_ptr, mlx->width, \
						mlx->height, "cub3d");
	if (!mlx->window)
		return (FAIL);
	return (SUCCESS);
}

int	display(t_window *mlx, t_map_param *map)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (write_message(ERR_MALLOC), FAIL);
	info->mlx = mlx;
	info->map = map;
	image_handler(info->mlx);
	if (fill_image(info) == FAIL)
		return (FAIL);
	mlx_put_image_to_window(mlx->init_ptr, mlx->window, mlx->img.img_ptr, 0, 0);
	event_handler(info);
	mlx_loop(mlx->init_ptr);
	return (SUCCESS);
}
