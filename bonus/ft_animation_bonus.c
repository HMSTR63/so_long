/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:56:25 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/03 00:18:08 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int ft_coin(t_game *game)
{
    static int c_count = 0;
    static int frames = 0;
    int width;
    int height;
    width = SIZE;
    height = SIZE;
    
    frames++;
    if (frames < 12)
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

static int ft_idel(t_game *game)
{
    static int p_count = 0;
    static int frames = 0;
    int width;
    int height;
    width = SIZE;
    height = SIZE;
    
    frames++;
    if (frames < 12)
        return (0);
    frames = 0;
    if(p_count >= 6)
        p_count = 0;
    mlx_destroy_image(game->mlx, game->image.player);
    if(p_count == 0)
        game->image.player = mlx_xpm_file_to_image(game->mlx, "bonus/../images/player_anim/so_long_p1.xpm", &width, &height);
    else if(p_count == 1)
        game->image.player = mlx_xpm_file_to_image(game->mlx, "bonus/../images/player_anim/so_long_p2.xpm", &width, &height);
    else if(p_count == 2)
        game->image.player = mlx_xpm_file_to_image(game->mlx, "bonus/../images/player_anim/so_long_p3.xpm", &width, &height);
    else if(p_count == 3)
        game->image.player = mlx_xpm_file_to_image(game->mlx, "bonus/../images/player_anim/so_long_p4.xpm", &width, &height);
    else if(p_count == 4)
        game->image.player = mlx_xpm_file_to_image(game->mlx, "bonus/../images/player_anim/so_long_p5.xpm", &width, &height);
    else if(p_count == 5)
        game->image.player = mlx_xpm_file_to_image(game->mlx, "bonus/../images/player_anim/so_long_p6.xpm", &width, &height);
    else if(p_count == 5)
        game->image.player = mlx_xpm_file_to_image(game->mlx, "bonus/../images/player_anim/so_long_p7.xpm", &width, &height);
    p_count++;
    return (0);
}
static int ft_enemy(t_game *game)
{
    static int n_count = 0;
    static int frames = 0;
    int width;
    int height;
    width = SIZE;
    height = SIZE;
    
    frames++;
    if (frames < 12)
        return (0);
    frames = 0;
    if(n_count >= 3)
        n_count = 0;
    mlx_destroy_image(game->mlx, game->image.enemy);
    if(n_count == 0)
        game->image.enemy = mlx_xpm_file_to_image(game->mlx, "bonus/../images/enemy_anim/so_long_n1.xpm", &width, &height);
    else if(n_count == 1)
        game->image.enemy = mlx_xpm_file_to_image(game->mlx, "bonus/../images/enemy_anim/so_long_n2.xpm", &width, &height);
    else if(n_count == 2)
        game->image.enemy = mlx_xpm_file_to_image(game->mlx, "bonus/../images/enemy_anim/so_long_n3.xpm", &width, &height);
    n_count++;
    return (0);
}
void	ft_animation(t_game *game)
{
    ft_coin(game);
    ft_idel(game);
    ft_enemy(game);
    char *moves;
    moves = ft_itoa(game->moves);
    mlx_string_put(game->mlx, game->window, 10, 10, 0xFFFF00, "Moves: ");
    mlx_string_put(game->mlx, game->window, 100, 10, 0xFFFF00, moves);
    free(moves);
}
