/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:18:43 by sojammal          #+#    #+#             */
/*   Updated: 2025/02/28 18:10:10 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void ft_fill(char **grid, int x, int y, t_game *game)
{
    if (x < 0 || y < 0 || x >= game->map->cols || y >= game->map->rows)
        return ;
    if (grid[x][y] == 'E')
        game->won = 1;
    if (grid[x][y] == '1' || grid[x][y] == 'X' || grid[x][y] == 'E')
        return ;
    if (grid[x][y] == 'C')
        game->collectibles++;
    grid[x][y] = 'X';
    ft_fill(grid, x + 1, y, game);
    ft_fill(grid, x - 1, y, game);
    ft_fill(grid, x, y + 1, game);
    ft_fill(grid, x, y - 1, game);
}

int ft_valid_map(t_game *game)
{
    char **tmp_grid;
    int x;
    
    tmp_grid = malloc(sizeof(char *) * game->map->cols);
    if (!tmp_grid)
        return (0);
    x = 0;
    while (x < game->map->cols)
    {
        tmp_grid[x] = ft_strdup(game->map->grid[x]);
        if (!tmp_grid[x])
        {
            ft_free_grid(tmp_grid, x);
            return (0);
        }
        x++;
    }
    game->collectibles = 0;
    game->won = 0;
    ft_fill(tmp_grid, game->player_x, game->player_y, game);
    ft_free_grid(tmp_grid, game->map->cols);
    return (game->collectibles == game->collectibles_count && game->won == 1);
}
