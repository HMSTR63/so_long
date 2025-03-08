/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_image_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:42:10 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/06 00:42:20 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_anim(t_game *game)
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

void	ft_free_image(t_game *game)
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
