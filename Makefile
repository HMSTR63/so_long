NAME_M = so_long
NAME_B = so_long_bonus
SRC_M = mandatory/ft_check_extension.c mandatory/ft_filling.c mandatory/ft_hook.c mandatory/ft_moves.c mandatory/ft_parse_map.c mandatory/ft_setup.c mandatory/ft_valid_chars.c mandatory/ft_valid_map.c mandatory/ft_valid_wall.c mandatory/get_next_line_utils.c mandatory/get_next_line.c mandatory/so_long.c mandatory/utils.c 
SRC_B = bonus/ft_animation_bonus.c bonus/ft_check_extension_bonus.c bonus/ft_filling_bonus.c bonus/ft_free_image_bonus.c bonus/ft_get_animation_bonus.c bonus/ft_hook_bonus.c bonus/ft_moves_bonus.c bonus/ft_parse_map_bonus.c bonus/ft_setup_bonus.c bonus/ft_setup_anim_bonus.c bonus/ft_valid_chars_bonus.c bonus/ft_valid_map_bonus.c bonus/ft_valid_wall_bonus.c bonus/get_next_line_utils_bonus.c bonus/get_next_line_bonus.c bonus/so_long_bonus.c bonus/utils_bonus.c bonus/utils1_bonus.c
OBJ_M = $(SRC_M:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
INCLUDE_M = mandatory/so_long.h
INCLUDE_B = bonus/so_long_bonus.h

all: $(NAME_M)

$(NAME_M): $(OBJ_M)
	$(CC) $(CFLAGS) $(OBJ_M) $(MLX) -o $(NAME_M)

%_bonus.o: %_bonus.c $(INCLUDE_B)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c $(INCLUDE_M)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_B)

$(NAME_B): $(OBJ_B)
	$(CC) $(CFLAGS) $(OBJ_B) $(MLX) -o $(NAME_B)

clean:
	$(RM) $(OBJ_M) $(OBJ_B)

fclean: clean
	$(RM) $(NAME_M) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re bonus