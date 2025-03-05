/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:03:16 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/05 15:19:05 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void f()
// {
// 	// system("leaks so_long");
// 	system("lsof -c so_long");
// }

int	main(int c, char **v)
{
	// atexit(f);
	t_game	game;

	if (c != 2)
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		exit(1);
	}
	if (!ft_check_extension(v[1]))
	{
		ft_putstr_fd("Error: Invalid file\n", 2);
		exit(1);
	}
	if (!ft_setup(&game, v[1]))
		exit(1);
	ft_hook(&game);
	mlx_loop(game.mlx);
	ft_clean(&game);
	return (0);
}
