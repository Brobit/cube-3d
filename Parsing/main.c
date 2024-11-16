/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:16:47 by almarico          #+#    #+#             */
/*   Updated: 2024/11/16 14:09:44 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

static void	init_player(t_map_param *map)
{
	map->player = malloc(sizeof(t_player));
	map->player->pos_x = 26;
	map->player->pos_y = 11;
	map->player->direction = NORTH;
}

static void	init_map(t_map_param *map)
{
	map->map = malloc(15 * sizeof(char *));
	map->map[0] = ft_strdup("        1111111111111111111111111");
	map->map[1] = ft_strdup("        1000000000110000000000001");
	map->map[2] = ft_strdup("        1011000001110000000000001");
	map->map[3] = ft_strdup("        1001000000000000000000001");
	map->map[4] = ft_strdup("111111111011000001110000000000001");
	map->map[5] = ft_strdup("100000000011000001110111111111111");
	map->map[6] = ft_strdup("11110111111111011100000010001");
	map->map[7] = ft_strdup("11110111111111011101010010001");
	map->map[8] = ft_strdup("11000000110101011100000010001");
	map->map[9] = ft_strdup("10000000000000001100000010001");
	map->map[10] = ft_strdup("10000000000000001101010010001");
	map->map[11] = ft_strdup("11000001110101011111011110N0111");
	map->map[12] = ft_strdup("11110111 1110101 101111010001");
	map->map[13] = ft_strdup("11111111 1111111 111111111111");
	map->map[14] = NULL;
}

static void	init_info(t_map_param *map)
{
	map->north_texture = ft_strdup("./textures/eagle.xpm");
	map->south_texture = ft_strdup("./textures/greystone.xpm");
	map->west_texture = ft_strdup("./textures/red.xpm");
	map->east_texture = ft_strdup("./textures/purplestone.xpm");
	map->floor_color[0] = 210;
	map->floor_color[1] = 100;
	map->floor_color[2] = 0;
	map->ceiling_color[0] = 225;
	map->ceiling_color[1] = 30;
	map->ceiling_color[2] = 0;
	init_map(map);
	init_player(map);
}

int	main(void)
{
	t_map_param	*map;

	map = malloc(sizeof(t_map_param));
	if (!map)
		return (FAIL);
	init_info(map);
	if (raycasting_entry(map) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
