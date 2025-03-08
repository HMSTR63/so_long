/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_anim_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:04:45 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/06 00:55:59 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_get_player(t_game *game)
{
	if (SIZE != 32)
		return (0);
	ft_img("bonus/../textures/player_anim/so_long_p1.xpm",
		&game->anim.p1, game);
	ft_img("bonus/../textures/player_anim/so_long_p2.xpm",
		&game->anim.p2, game);
	ft_img("bonus/../textures/player_anim/so_long_p3.xpm",
		&game->anim.p3, game);
	ft_img("bonus/../textures/player_anim/so_long_p4.xpm",
		&game->anim.p4, game);
	ft_img("bonus/../textures/player_anim/so_long_p5.xpm",
		&game->anim.p5, game);
	ft_img("bonus/../textures/player_anim/so_long_p6.xpm",
		&game->anim.p6, game);
	if (!game->anim.p1 || !game->anim.p2 || !game->anim.p3
		|| !game->anim.p4 || !game->anim.p5 || !game->anim.p6)
	{
		ft_free_anim(game);
		return (0);
	}
	return (1);
}

int	ft_get_coin(t_game *game)
{
	if (SIZE != 32)
		return (0);
	ft_img("bonus/../textures/coine_anim/so_long_c1.xpm", &game->anim.c1, game);
	ft_img("bonus/../textures/coine_anim/so_long_c2.xpm", &game->anim.c2, game);
	ft_img("bonus/../textures/coine_anim/so_long_c3.xpm", &game->anim.c3, game);
	if (!game->anim.c1 || !game->anim.c2 || !game->anim.c3)
	{
		ft_free_anim(game);
		return (0);
	}
	return (1);
}

int	ft_get_enemy(t_game *game)
{
	if (SIZE != 32)
		return (0);
	ft_img("bonus/../textures/enemy_anim/so_long_n1.xpm", &game->anim.n1, game);
	ft_img("bonus/../textures/enemy_anim/so_long_n2.xpm", &game->anim.n2, game);
	ft_img("bonus/../textures/enemy_anim/so_long_n3.xpm", &game->anim.n3, game);
	if (!game->anim.n1 || !game->anim.n2 || !game->anim.n3)
	{
		ft_free_anim(game);
		return (0);
	}
	return (1);
}
