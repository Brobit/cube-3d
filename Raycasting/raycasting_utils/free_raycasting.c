/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:37:48 by almarico          #+#    #+#             */
/*   Updated: 2024/11/17 19:19:02 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void	free_raycasting(t_raycasting *raycasting)
{
	int	i;

	i = 0;
	while (i < NUMBER_OF_RAY)
		free(raycasting->ray[i++]);
	free(raycasting->ray);
	free(raycasting);
}
