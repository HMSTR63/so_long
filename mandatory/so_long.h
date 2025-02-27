/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:54:17 by sojammal          #+#    #+#             */
/*   Updated: 2025/02/27 20:53:11 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 63
# endif

# define SIZE 64

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
// image
typedef struct s_image
{
    void    *wall;
    void    *player;
    void    *exit;
    void    *collectible;
    void    *floor;
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

// get_next_line
char	*ft_strjoin(char *s1, char *s2);
char    *get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, int c);
int		len_at_newline(char *line, int i);
#endif