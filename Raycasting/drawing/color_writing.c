/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_writing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:37:14 by almarico          #+#    #+#             */
/*   Updated: 2024/11/15 16:58:42 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

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
			set_pixel_color(mlx->img, x, y, COLOR_BLUE);
		while (y > mlx->center_height && y < mlx->height)
			set_pixel_color(mlx->img, x, y++, COLOR_GREEN);
	}
}

void	draw_wall(t_window *mlx, t_map_param *map)
{
	(void)mlx;
	(void)map;
}
