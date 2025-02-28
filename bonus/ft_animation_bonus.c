/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:56:25 by sojammal          #+#    #+#             */
/*   Updated: 2025/02/28 18:50:28 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_animation(t_game *game)
{
    char *moves;
    moves = ft_itoa(game->moves);
    mlx_put_image_to_window(game->mlx, game->window, game->image.floor, 0, 0);
    mlx_put_image_to_window(game->mlx, game->window, game->image.floor, 80, 0);
    ft_setup_render(game);
    mlx_string_put(game->mlx, game->window, 10, 10, 0xFFFF00, "Moves: ");
    mlx_string_put(game->mlx, game->window, 100, 10, 0xFFFF00, moves);
    free(moves);
}
