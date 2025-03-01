NAME_M = so_long
NAME_B = so_long_bonus
SRC_M = mandatory/ft_check_extension.c mandatory/ft_filling.c mandatory/ft_hook.c mandatory/ft_moves.c mandatory/ft_parse_map.c mandatory/ft_setup.c mandatory/ft_valid_chars.c mandatory/ft_valid_map.c mandatory/ft_valid_wall.c mandatory/get_next_line_utils.c mandatory/get_next_line.c mandatory/so_long.c mandatory/utils.c 
SRC_B = bonus/ft_animation_bonus.c bonus/ft_check_extension_bonus.c bonus/ft_filling_bonus.c bonus/ft_hook_bonus.c bonus/ft_moves_bonus.c bonus/ft_parse_map_bonus.c bonus/ft_setup_bonus.c bonus/ft_valid_chars_bonus.c bonus/ft_valid_map_bonus.c bonus/ft_valid_wall_bonus.c bonus/get_next_line_utils_bonus.c bonus/get_next_line_bonus.c bonus/so_long_bonus.c bonus/utils_bonus.c bonus/utils1_bonus.c
OBJ_M = $(SRC_M:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address -g
MLX_LINUX = -Imlx -Lmlx -lmlx -Imlx -lXext -lX11 -lm -lz 
MLX_MAC =  -Imlx -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
INCLUDE_M = so_long.h
INCLUDE_B = so_long_bonus.h

all: $(NAME_M) stock

stock : $(OBJ_M)
	mkdir objects
	mv mandatory/*.o objects

$(NAME_M): $(OBJ_M)
	$(CC) $(CFLAGS) $(OBJ_M) $(MLX_MAC) -o $(NAME_M)

%.o: %.c $(INCLUDE_M)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_B) stock_b

stock_b : $(OBJ_B)
	mkdir objects_b
	mv bonus/*.o objects_b

$(NAME_B): $(OBJ_B)
	$(CC) $(CFLAGS) $(OBJ_B) $(MLX_MAC) -o $(NAME_B)

%_bonus.o: %_bonus.c $(INCLUDE_B)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_M) $(OBJ_B)

fclean: clean
	$(RM) $(NAME_M) $(NAME_B) objects objects_b

re: fclean all

.PHONY: all clean fclean re bonus