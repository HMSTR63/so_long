/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:56:25 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/01 00:22:32 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_animation(t_game *game)
{
    char *moves;
    moves = ft_itoa(game->moves);
    mlx_string_put(game->mlx, game->window, 10, 10, 0xFFFF00, "Moves: ");
    mlx_string_put(game->mlx, game->window, 100, 10, 0xFFFF00, moves);
    free(moves);
}
