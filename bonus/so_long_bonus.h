/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:54:17 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/02 14:29:33 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "../mlx/mlx.h"
# include <X11/X.h>

# define GRN "\033[0;32m"
# define RED "\033[0;31m"
# define PUR "\033[0;35m"
# define RES "\033[0m"

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 63
# endif

# define SIZE 32

// LINUX
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
// MAC
// # define ESC 53
// # define W 13
// # define A 0
// # define S 1
// # define D 2
// # define UP 126
// # define LEFT 123
// # define DOWN 125
// # define RIGHT 124
// image
typedef struct s_image
{
    void    *wall;
    void    *player;
    void    *exit_open;
    void    *exit_close;
    void    *collectible;
    void    *floor;
    void    *enemy;
}	t_image;
// map
typedef struct s_map
{
    int		rows;
    int		cols;
    char	**grid;
}	t_map;

// game
typedef struct s_game
{
    t_map	*map;
    t_image image;
    void    *mlx;
    void    *window;
    int		player_x;
    int		player_y;
    int     prev_player_y;
    int     prev_player_x;
    int		collectibles;
    int		collectibles_count;
    int     enemy_count;
    int     player;
    int		exit;
    int		moves;
    int		won;
}	t_game;


// utils
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);
size_t		ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(size_t i);


// parsing
int		ft_check_extension(char *file);
int		ft_parse_map(t_game *game, char *file);
void    ft_free_grid(char **grid, int rows);
int     ft_filling(int fd, t_game *game);
int     ft_valid_wall(t_game *game);
int     ft_valid_chars(t_game *game);
int     ft_valid_map(t_game *game);

// so_long
int		ft_setup(t_game *game, char *file);
void	setup_hooks(t_game *game);
void    ft_clean(t_game *game);
void	ft_hook(t_game *game);
int ft_setup_render(t_game *game);
int ft_moves(t_game *game, int x, int y);
void ft_animation(t_game *game);

// get_next_line
char	*ft_strjoin(char *s1, char *s2);
char    *get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, int c);
int		len_at_newline(char *line, int i);
#endif