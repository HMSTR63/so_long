/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:04:51 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/06 23:13:14 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_key(int code, t_game *game)
{
	int	move;

	move = 0;
	if (code == ESC)
	{
		ft_clean(game);
		exit(0);
	}
	if (code == W || code == UP)
		move = ft_moves(game, -1, 0);
	else if (code == S || code == DOWN)
		move = ft_moves(game, 1, 0);
	else if (code == A || code == LEFT)
		move = ft_moves(game, 0, -1);
	else if (code == D || code == RIGHT)
		move = ft_moves(game, 0, 1);
	if (move)
		game->moves++;
	return (0);
}

void	ft_rendring(t_game *game, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.floor, x, y);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.player,
			game->player_y * SIZE, game->player_x * SIZE);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.wall, x, y);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.collectible, x, y);
	if (c == 'N')
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.enemy, x, y);
	if (c == 'E' && game->collectibles != game->collectibles_count)
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.exit_close, x, y);
	if (c == 'E' && game->collectibles == game->collectibles_count)
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.exit_open, x, y);
}

int	ft_setup_render(t_game *game)
{
	int	x;
	int	y;
	int	win_x;
	int	win_y;

	y = 0;
	while (y < game->map->cols)
	{
		x = 0;
		while (x < game->map->rows)
		{
			win_x = x * SIZE;
			win_y = y * SIZE;
			ft_rendring(game, game->map->grid[y][x], win_x, win_y);
			x++;
		}
		y++;
	}
	ft_animation(game);
	return (0);
}

void	ft_hook(t_game *game)
{
	mlx_hook(game->window, 2, 1L << 0, ft_key, game);
	mlx_hook(game->window, 17, 1L << 17, ft_close, game);
	mlx_loop_hook(game->mlx, ft_setup_render, game);
}
