/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:27:17 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/03 04:23:45 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_horizontal_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		if (game->map->grid[x][y] != '1'
			|| game->map->grid[game->map->cols - 1][y] != '1')
			return (0);
		y++;
	}
	return (1);
}

static int	ft_vertical_wall(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->cols)
	{
		y = 0;
		if (game->map->grid[x][y] != '1'
			|| game->map->grid[x][game->map->rows - 1] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	ft_valid_wall(t_game *game)
{
	return (ft_horizontal_wall(game) && ft_vertical_wall(game));
}
