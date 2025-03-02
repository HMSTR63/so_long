/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:56:25 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/02 04:12:31 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int ft_coin(t_game *game)
{
    static int c_count = 0;
    static int frames = 0;
    int width;
    int height;
    width = SIZE;
    height = SIZE;
    
    frames++;
    if (frames < 100)
        return (0);
    frames = 0;
    if(c_count >= 3)
        c_count = 0;
    mlx_destroy_image(game->mlx, game->image.collectible);
    if(c_count == 0)
        game->image.collectible = mlx_xpm_file_to_image(game->mlx, "bonus/../images/coine_anim/so_long_c1.xpm", &width, &height);
    else if(c_count == 1)
        game->image.collectible = mlx_xpm_file_to_image(game->mlx, "bonus/../images/coine_anim/so_long_c2.xpm", &width, &height);
    else if(c_count == 2)
        game->image.collectible = mlx_xpm_file_to_image(game->mlx, "bonus/../images/coine_anim/so_long_c3.xpm", &width, &height);
    c_count++;
    return (0);
}
void	ft_animation(t_game *game)
{
    ft_coin(game);
    char *moves;
    moves = ft_itoa(game->moves);
    mlx_string_put(game->mlx, game->window, 10, 10, 0xFFFF00, "Moves: ");
    mlx_string_put(game->mlx, game->window, 100, 10, 0xFFFF00, moves);
    free(moves);
}
