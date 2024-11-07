/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:16:47 by almarico          #+#    #+#             */
/*   Updated: 2024/11/07 15:15:09 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	main(void)
{
	t_map_param	*info;

	info = malloc(sizeof(t_map_param));
	raycasting_entry(info);
	return (SUCCESS);
}
