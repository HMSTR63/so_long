/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:15:18 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/03 01:28:32 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_free_image(t_game *game)
{
    if (game->image.player)
        mlx_destroy_image(game->mlx, game->image.player);
    if (game->image.wall)
        mlx_destroy_image(game->mlx, game->image.wall);
    if (game->image.exit)
        mlx_destroy_image(game->mlx, game->image.exit);
    if (game->image.collectible)
        mlx_destroy_image(game->mlx, game->image.collectible);
    if (game->image.floor)
        mlx_destroy_image(game->mlx, game->image.floor);
}

static int ft_init(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        return (0);
    game->window = mlx_new_window(game->mlx, game->map->rows * SIZE, game->map->cols * SIZE, "so_long");
    if (!game->window)
    {
        free(game->mlx);
        return (0);
    }
    game->moves = 0;
    game->collectibles = 0;
    return (1);
}
void    ft_clean(t_game *game)
{
    if (game->mlx && game->window)
        mlx_destroy_window(game->mlx, game->window);
    if (game->mlx)
        free(game->mlx);
    if (game->map)
        free(game->map);
    if (game->map->grid)
        ft_free_grid(game->map->grid, game->map->cols);
}
static int ft_image(t_game *game)
{
    int width;
    int height;

    width = SIZE;
    height = SIZE;
    if (SIZE != 32)
        return (0);
    game->image.player = mlx_xpm_file_to_image(game->mlx, "mandatory/../images/so_long_p.xpm", &width, &height);
    game->image.wall = mlx_xpm_file_to_image(game->mlx, "mandatory/../images/so_long_w.xpm", &width, &height);
    game->image.exit = mlx_xpm_file_to_image(game->mlx, "mandatory/../images/so_long_e.xpm", &width, &height);
    game->image.collectible = mlx_xpm_file_to_image(game->mlx, "mandatory/../images/so_long_c.xpm", &width, &height);
    game->image.floor = mlx_xpm_file_to_image(game->mlx, "mandatory/../images/so_long_f.xpm", &width, &height);
    if (!game->image.player || !game->image.wall || !game->image.exit || !game->image.collectible || !game->image.floor)
    {
        ft_free_image(game);  
        return (0);
    }
    return (1);
}

int ft_setup(t_game *game, char *file)
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
    if (!ft_image(game))
    {
        ft_putstr_fd("Error: Invalid image\n", 2);
        return (0);
    }
    return (1);
}
