/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:15:18 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/05 16:55:22 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdio.h>


static void ft_free_anim(t_game *game)
{
	if (game->anim.p1)
		mlx_destroy_image(game->mlx, game->anim.p1);
	if (game->anim.p2)
		mlx_destroy_image(game->mlx, game->anim.p2);
	if (game->anim.p3)
		mlx_destroy_image(game->mlx, game->anim.p3);
	if (game->anim.p4)
		mlx_destroy_image(game->mlx, game->anim.p4);
	if (game->anim.p5)
		mlx_destroy_image(game->mlx, game->anim.p5);
	if (game->anim.p6)
		mlx_destroy_image(game->mlx, game->anim.p6);
}

static void	ft_free_image(t_game *game)
{
	if (game->image.player)
		mlx_destroy_image(game->mlx, game->image.player);
	if (game->image.wall)
		mlx_destroy_image(game->mlx, game->image.wall);
	if (game->image.exit_open)
		mlx_destroy_image(game->mlx, game->image.exit_open);
	if (game->image.exit_close)
		mlx_destroy_image(game->mlx, game->image.exit_close);
	if (game->image.collectible)
		mlx_destroy_image(game->mlx, game->image.collectible);
	if (game->image.floor)
		mlx_destroy_image(game->mlx, game->image.floor);
	if (game->image.enemy)
		mlx_destroy_image(game->mlx, game->image.enemy);
}

static int	ft_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->window = mlx_new_window(game->mlx,
			game->map->rows * SIZE, game->map->cols * SIZE, "so_long");
	if (!game->window)
	{
		free(game->mlx);
		return (0);
	}
	game->moves = 0;
	game->collectibles = 0;
	return (1);
}

static void	ft_img(char *path, void **s, t_game *game)
{
	int	width;
	int	height;

	width = SIZE;
	height = SIZE;
	*s = mlx_xpm_file_to_image(game->mlx,
			path, &width, &height);
}
static int	ft_image_anim(t_game *game)
{
	if (SIZE != 32)
		return (0);
	ft_img("bonus/../images/player_anim/so_long_p1.xpm", &game->anim.p1, game);
	ft_img("bonus/../images/player_anim/so_long_p2.xpm", &game->anim.p2, game);
	ft_img("bonus/../images/player_anim/so_long_p3.xpm", &game->anim.p3, game);
	ft_img("bonus/../images/player_anim/so_long_p4.xpm", &game->anim.p4, game);
	ft_img("bonus/../images/player_anim/so_long_p5.xpm", &game->anim.p5, game);
	ft_img("bonus/../images/player_anim/so_long_p6.xpm", &game->anim.p6, game);
	if (!game->anim.p1 || !game->anim.p2 || !game->anim.p3
		|| !game->anim.p4 || !game->anim.p5 || !game->anim.p6)
	{
		ft_free_anim(game);
		return (0);
	}
	return (1);
}
static int	ft_image(t_game *game)
{
	if (SIZE != 32)
		return (0);
	ft_img("mandatory/../images/so_long_p.xpm", &game->image.player, game);
	ft_img("mandatory/../images/so_long_w.xpm", &game->image.wall, game);
	ft_img("mandatory/../images/so_long_e.xpm", &game->image.exit_close, game);
	ft_img("mandatory/../images/so_long_e_open.xpm",
		&game->image.exit_open, game);
	ft_img("mandatory/../images/so_long_c.xpm", &game->image.collectible, game);
	ft_img("mandatory/../images/so_long_f.xpm", &game->image.floor, game);
	ft_img("mandatory/../images/so_long_n.xpm", &game->image.enemy, game);
	if (!game->image.player || !game->image.wall
		|| !game->image.exit_close || !game->image.exit_open
		|| !game->image.collectible || !game->image.floor
		|| !game->image.enemy)
	{
		ft_free_image(game);
		return (0);
	}
	return (1);
}

int	ft_setup(t_game *game, char *file)
{
	if (!ft_parse_map(game, file))
	{
		ft_putstr_fd("Error: Invalid map\n", 2);
		return (0);
	}
	if (!ft_init(game))
	{
		ft_clean(game);
		return (0);
	}
	if (!ft_image(game) || !ft_image_anim(game))
	{
		ft_putstr_fd("Error: Invalid image\n", 2);
		return (0);
	}
	return (1);
}
