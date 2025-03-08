/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:15:18 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/06 23:29:30 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_img(char *path, void **s, t_game *game)
{
	int	width;
	int	height;

	width = SIZE;
	height = SIZE;
	*s = mlx_xpm_file_to_image(game->mlx,
			path, &width, &height);
}

static int	ft_image(t_game *game)
{
	if (SIZE != 32)
		return (0);
	ft_img("mandatory/../textures/so_long_p.xpm", &game->image.player, game);
	ft_img("mandatory/../textures/so_long_w.xpm", &game->image.wall, game);
	ft_img("mandatory/../textures/so_long_e.xpm",
		&game->image.exit_close, game);
	ft_img("mandatory/../textures/so_long_e_open.xpm",
		&game->image.exit_open, game);
	ft_img("mandatory/../textures/so_long_c.xpm",
		&game->image.collectible, game);
	ft_img("mandatory/../textures/so_long_f.xpm", &game->image.floor, game);
	ft_img("mandatory/../textures/so_long_n.xpm", &game->image.enemy, game);
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
	if (!ft_image(game) || !ft_get_player(game)
		|| !ft_get_coin(game) || !ft_get_enemy(game))
	{
		ft_putstr_fd("Error: Invalid image\n", 2);
		return (0);
	}
	return (1);
}
