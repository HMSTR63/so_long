/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:54:09 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/04 16:42:24 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_won(void)
{
	ft_putstr_fd(GRN "██╗   ██╗ ██████╗ ██╗   ██╗  ", 1);
	ft_putstr_fd(GRN "  ██╗    ██╗ ██████╗ ███╗   ██╗██╗\n", 1);
	ft_putstr_fd(GRN "╚██╗ ██╔╝██╔═══██╗██║   ██║  ", 1);
	ft_putstr_fd(GRN "  ██║    ██║██╔═══██╗████╗  ██║██║\n", 1);
	ft_putstr_fd(GRN " ╚████╔╝ ██║   ██║██║   ██║  ", 1);
	ft_putstr_fd(GRN "  ██║ █╗ ██║██║   ██║██╔██╗ ██║██║\n", 1);
	ft_putstr_fd(GRN "  ╚██╔╝  ██║   ██║██║   ██║  ", 1);
	ft_putstr_fd(GRN "  ██║███╗██║██║   ██║██║╚██╗██║╚═╝\n", 1);
	ft_putstr_fd(GRN "   ██║   ╚██████╔╝╚██████╔╝  ", 1);
	ft_putstr_fd(GRN "  ╚███╔███╔╝╚██████╔╝██║ ╚████║██╗\n", 1);
	ft_putstr_fd(GRN "   ╚═╝    ╚═════╝  ╚═════╝    ", 1);
	ft_putstr_fd(GRN "  ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═══╝╚═╝\n" RES, 1);
}

static void	ft_lost(void)
{
	ft_putstr_fd(RED "██╗    ██╗ █████╗ ███████╗████████", 1);
	ft_putstr_fd(RED "╗███████╗██████╗ \n", 1);
	ft_putstr_fd(RED "██║    ██║██╔══██╗██╔════╝╚══██╔══", 1);
	ft_putstr_fd(RED "╝██╔════╝██╔══██╗\n", 1);
	ft_putstr_fd(RED "██║ █╗ ██║███████║███████╗   ██║  ", 1);
	ft_putstr_fd(RED " █████╗  ██║  ██║\n", 1);
	ft_putstr_fd(RED "██║███╗██║██╔══██║╚════██║   ██║   ", 1);
	ft_putstr_fd(RED "██╔══╝  ██║  ██║\n", 1);
	ft_putstr_fd(RED "╚███╔███╔╝██║  ██║███████║   ██║  ", 1);
	ft_putstr_fd(RED " ███████╗██████╔╝\n", 1);
	ft_putstr_fd(RED " ╚══╝╚══╝ ╚═╝  ╚═╝╚══════╝   ╚═╝  ", 1);
	ft_putstr_fd(RED " ╚══════╝╚═════╝ \n" RES, 1);
}

static int	ft_valid_pos(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map->cols || y < 0 || y >= game->map->rows)
		return (0);
	if (game->map->grid[x][y] == '1' || (game->map->grid[x][y] == 'E'
			&& game->collectibles != game->collectibles_count))
		return (0);
	return (1);
}

static int	ft_win(t_game *game, int x, int y)
{
	if (game->map->grid[x][y] != 'E')
		return (0);
	if (game->collectibles == game->collectibles_count)
	{
		ft_won();
		game->won = 1;
		return (1);
	}
	return (0);
}

int	ft_moves(t_game *game, int x, int y)
{
	int	move_x;
	int	move_y;

	move_x = game->player_x + x;
	move_y = game->player_y + y;
	if (!ft_valid_pos(game, move_x, move_y))
		return (0);
	if (game->map->grid[move_x][move_y] == 'C')
	{
		game->collectibles++;
		game->map->grid[move_x][move_y] = '0';
	}
	else if (ft_win(game, move_x, move_y) == 1)
		exit(0);
	else if (game->map->grid[move_x][move_y] == 'N')
	{
		ft_lost();
		exit(0);
	}
	game->map->grid[game->player_x][game->player_y] = '0';
	game->player_x = move_x;
	game->player_y = move_y;
	game->map->grid[game->player_x][game->player_y] = 'P';
	return (1);
}
