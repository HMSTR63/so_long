/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:17:39 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/02 23:46:32 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
static int ft_validate_line(char *line, int rows)
{
    int i;

    i = ft_strlen(line);
    if (line[i - 1] == '\n')
        i--;
    return (i == rows);
}

static int ft_get_dimensions(t_game *game, char *file)
{
    int     fd;
    char    *line;
    
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    game->map->cols = 0;
    line = get_next_line(fd);
    if (line == NULL)
        return (0);
    game->map->rows = ft_strlen(line) - 1;
    while (line)
    {
        if (!ft_validate_line(line, game->map->rows))
        {
            free(line);
            close(fd);
            return (0);
        }
        game->map->cols++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (game->map->cols > 0 && game->map->rows > 0);
}

static int ft_fill_map(t_game *game, char *file)
{
    int fd;

    game->map->grid = malloc(sizeof(char *) * game->map->cols);
    if (!game->map->grid)
        return (-1);
    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
		ft_free_grid(game->map->grid, game->map->cols);
        return (-1);
    }
    if (!ft_filling(fd, game))
    {
		ft_free_grid(game->map->grid, game->map->cols);
        close(fd);
        return (0);
    }
    close(fd);
    return (1);
}

int ft_parse_map(t_game *game, char *file)
{
    game->map = malloc(sizeof(t_map));
    if (!game->map)
        return (0);
    if (!ft_get_dimensions(game, file) || game->map->cols > 32 || game->map->rows > 60)
    {
		ft_clean(game);
        return (0);
    }
    if (!ft_fill_map(game, file))
    {
		ft_clean(game);
        return (0);
    }
    if (!ft_valid_wall(game) || !ft_valid_chars(game) || !ft_valid_map(game))
    {
        ft_free_grid(game->map->grid, game->map->cols);
		ft_clean(game);
        return (0);
    }
    return (1);
}
