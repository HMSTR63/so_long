/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:59:37 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/06 23:26:34 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		res;

	nb = n;
	if (fd < 0)
		return ;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb / 10 > 0)
		ft_putnbr_fd(nb / 10, fd);
	res = nb % 10 + '0';
	write(fd, &res, 1);
}

void	ft_clean(t_game *game)
{
	if (game->mlx && game->window)
		mlx_destroy_window(game->mlx, game->window);
	ft_free_image(game);
	if (!game->mlx)
		free(game->mlx);
	if (game->map)
		free(game->map);
	if (game->map->grid)
		ft_free_grid(game->map->grid, game->map->cols);
}

int	ft_close(t_game *game)
{
	ft_clean(game);
	exit(0);
}
