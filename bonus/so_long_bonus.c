/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:03:16 by sojammal          #+#    #+#             */
/*   Updated: 2025/02/28 18:09:40 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int main(int c, char **v)
{
    t_game game;

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
    return (0);
}