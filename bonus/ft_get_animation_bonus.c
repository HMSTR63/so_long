/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_animation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:22:42 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/06 00:40:11 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_idel_animation(int count, t_game *game)
{
	if (count == 0)
		game->image.player = game->anim.p1;
	else if (count == 1)
		game->image.player = game->anim.p2;
	else if (count == 2)
		game->image.player = game->anim.p3;
	else if (count == 3)
		game->image.player = game->anim.p4;
	else if (count == 4)
		game->image.player = game->anim.p5;
	else if (count == 5)
		game->image.player = game->anim.p6;
}

void	ft_enemy_animation(int count, t_game *game)
{
	if (count == 0)
		game->image.enemy = game->anim.n1;
	else if (count == 1)
		game->image.enemy = game->anim.n2;
	else if (count == 2)
		game->image.enemy = game->anim.n3;
}

void	ft_coin_animation(int count, t_game *game)
{
	if (count == 0)
		game->image.collectible = game->anim.c1;
	else if (count == 1)
		game->image.collectible = game->anim.c2;
	else if (count == 2)
		game->image.collectible = game->anim.c3;
}
