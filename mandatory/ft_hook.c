/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:04:51 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/03 03:57:59 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	{
		game->moves++;
		ft_putstr_fd(PUR "Moves " RES, 1);
		ft_putnbr_fd(game->moves, 1);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}

static void	ft_rendring(t_game *game, char c, int x, int y)
{
	int	win_x;
	int	win_y;

	win_x = x * SIZE;
	win_y = y * SIZE;
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.wall, win_x, win_y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.collectible, win_x, win_y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.exit, win_x, win_y);
	else
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.floor, win_x, win_y);
}

int	ft_setup_render(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->cols)
	{
		x = 0;
		while (x < game->map->rows)
		{
			ft_rendring(game, game->map->grid[y][x], x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->image.player,
		game->player_y * SIZE, game->player_x * SIZE);
	return (0);
}

static int	ft_close(t_game *game)
{
	ft_clean(game);
	exit(0);
}

void	ft_hook(t_game *game)
{
	mlx_hook(game->window, 2, 1L << 0, ft_key, game);
	mlx_hook(game->window, 17, 1L << 17, ft_close, game);
	mlx_loop_hook(game->mlx, ft_setup_render, game);
}
