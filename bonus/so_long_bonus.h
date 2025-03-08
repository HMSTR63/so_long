/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:54:17 by sojammal          #+#    #+#             */
/*   Updated: 2025/03/07 02:05:07 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# define GRN "\033[0;32m"
# define RED "\033[0;31m"
# define PUR "\033[0;35m"
# define RES "\033[0m"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 63
# endif

# ifndef SIZE
#  define SIZE 32
# endif

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124

typedef struct s_anim
{
	void	*p1;
	void	*p2;
	void	*p3;
	void	*p4;
	void	*p5;
	void	*p6;
	void	*c1;
	void	*c2;
	void	*c3;
	void	*n1;
	void	*n2;
	void	*n3;
}	t_anim;

typedef struct s_image
{
	void	*wall;
	void	*player;
	void	*exit_open;
	void	*exit_close;
	void	*collectible;
	void	*floor;
	void	*enemy;
}	t_image;

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**grid;
}	t_map;

typedef struct s_game
{
	t_map	*map;
	t_image	image;
	t_anim	anim;
	void	*mlx;
	void	*window;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		collectibles_count;
	int		enemy_count;
	int		player;
	int		exit;
	int		moves;
	int		won;
}	t_game;

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(size_t i);

int		ft_check_extension(char *file);
int		ft_parse_map(t_game *game, char *file);
void	ft_free_grid(char **grid, int cols);
int		ft_filling(int fd, t_game *game);
int		ft_valid_wall(t_game *game);
int		ft_valid_chars(t_game *game);
int		ft_valid_map(t_game *game);

int		ft_setup(t_game *game, char *file);
void	setup_hooks(t_game *game);
void	ft_clean(t_game *game);
void	ft_hook(t_game *game);
int		ft_setup_render(t_game *game);
int		ft_moves(t_game *game, int x, int y);
void	ft_animation(t_game *game);
int		ft_close(t_game *game);
void	ft_free_image(t_game *game);
void	ft_free_anim(t_game *game);
void	ft_img(char *path, void **s, t_game *game);
void	ft_idel_animation(int count, t_game *game);
void	ft_enemy_animation(int count, t_game *game);
void	ft_coin_animation(int count, t_game *game);
int		ft_get_player(t_game *game);
int		ft_get_coin(t_game *game);
int		ft_get_enemy(t_game *game);
void	ft_lost(void);

char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, int c);
int		len_at_newline(char *line, int i);
void	ft_rendring(t_game *game, char c, int x, int y);

#endif