/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_writing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:37:14 by almarico          #+#    #+#             */
/*   Updated: 2024/11/18 11:45:35 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void	set_pixel_color(t_img_info img, int pos_x, int pos_y, int color)
{
	int		offset;
	char	*dst;

	offset = (pos_y * img.size_line + pos_x * (img.bits_per_pixel / 8));
	dst = img.img_data_address + offset;
	*(unsigned int *)dst = color;
}

void	fill_background(t_window *mlx)
{
	int	x;
	int	y;

	x = -1;
	while (++x <= mlx->width)
	{
		y = -1;
		while (++y <= mlx->center_height)
			set_pixel_color(mlx->img, x, y, COLOR_LIGHT_BLUE);
		while (y > mlx->center_height && y < mlx->height)
			set_pixel_color(mlx->img, x, y++, COLOR_GREY);
	}
}

int	draw_wall(t_info *info)
{
	t_raycasting	*raycasting;

	raycasting = malloc(sizeof(t_raycasting));
	if (!raycasting)
		return (write_message(ERR_MALLOC), FAIL);
	info->raycasting = raycasting;
	if (init_raycasting(info) == FAIL)
		return (FAIL);
	raycasting_calculation(info);
	display_raycasting_result(info);
	return (SUCCESS);
}
