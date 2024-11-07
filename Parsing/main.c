/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:16:47 by almarico          #+#    #+#             */
/*   Updated: 2024/11/07 15:36:42 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	main(void)
{
	t_map_param	*info;

	info = malloc(sizeof(t_map_param));
	if (!info)
		return (FAIL);
	if (raycasting_entry(info) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
