/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_chars_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:01:35 by sojammal          #+#    #+#             */
/*   Updated: 2025/02/28 18:10:13 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int ft_chars(char c, t_game *game, int x, int y)
{
    if (x >= game->map->cols || y >= game->map->rows)
        return (0);
    if (c == 'P')
    {
        game->player++;
        game->player_x = x;
        game->player_y = y;
    }
    else if (c == 'E')
        game->exit++;
    else if (c == 'C')
        game->collectibles_count++;
    else if (c != '1' && c != '0')
        return (0);
    return (1);
}

int ft_valid_chars(t_game *game)
{
    int x;
    int y;

    x = 0;
    game->player = 0;
    game->exit = 0;
    game->collectibles_count = 0;
    while (x < game->map->cols)
    {
        y = 0;
        while (y < game->map->rows)
        {
            if (!ft_chars(game->map->grid[x][y], game, x, y))
                return (0);
            y++;
        }
        x++;
    }
    return (game->player == 1 && game->exit == 1 && game->collectibles_count > 0);
}