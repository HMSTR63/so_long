/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:03:50 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/02 23:39:49 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int ft_alloc_grid(t_game *game, char *line, int i)
{
    game->map->grid[i] = malloc(sizeof(char) * (game->map->rows + 1));
    if (!game->map->grid[i])
    {
        ft_free_grid(game->map->grid, i);
        return (0);
    }
    ft_strlcpy(game->map->grid[i], line, game->map->rows + 1);
    return (1);
}

void ft_free_grid(char **grid, int cols)
{
    int i;

    if (!grid)
        return ;
    i = 0;
    while (i < cols)
    {
        free(grid[i]);
        i++;
    }
    free(grid);
}

int ft_filling(int fd, t_game *game)
{
    int i;
    char *line;

    i = 0;
    while (i < game->map->cols)
    {
        line = get_next_line(fd);
        if (!line || !ft_alloc_grid(game, line, i))
        {
            ft_free_grid(game->map->grid, i);
            free(line);
            close(fd);
            return (0);
        }
        free(line);
        i++;
    }
    return (1);
}
