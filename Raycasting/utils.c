/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:46:36 by almarico          #+#    #+#             */
/*   Updated: 2024/11/15 17:04:15 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	free_map(t_map_param *map)
{
	int	i;

	i = 0;
	if (map && map->map && map->player)
	{
		free(map->north_texture);
		free(map->south_texture);
		free(map->west_texture);
		free(map->east_texture);
		while (map->map[i])
			free(map->map[i++]);
		free(map->map);
		free(map->player);
	}
}

void	write_message(const char *msg)
{
	write(STDERR, msg, ft_strlen(msg));
}
