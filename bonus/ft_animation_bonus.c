/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:56:25 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/06 23:23:31 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_coin(t_game *game)
{
	static int	c_count = 0;
	static int	frames = 0;

	frames++;
	if (frames < 5)
		return (0);
	frames = 0;
	if (c_count >= 3)
		c_count = 0;
	ft_coin_animation(c_count, game);
	c_count++;
	return (0);
}

static int	ft_idel(t_game *game)
{
	static int	p_count = 0;
	static int	frames = 0;

	frames++;
	if (frames < 5)
		return (0);
	frames = 0;
	if (p_count >= 6)
		p_count = 0;
	ft_idel_animation(p_count, game);
	p_count++;
	return (0);
}

static int	ft_enemy(t_game *game)
{
	static int	n_count = 0;
	static int	frames = 0;

	frames++;
	if (frames < 5)
		return (0);
	frames = 0;
	if (n_count >= 3)
		n_count = 0;
	ft_enemy_animation(n_count, game);
	n_count++;
	return (0);
}

void	ft_animation(t_game *game)
{
	char	*moves;

	ft_coin(game);
	ft_idel(game);
	ft_enemy(game);
	moves = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->window, 10, 5, 0xFFFF00, "Moves: ");
	mlx_string_put(game->mlx, game->window, 100, 5, 0xFFFF00, moves);
	free(moves);
}
