NAME_M = so_long
# NAME_B = checker
SRC_M = mandatory/ft_check_extension.c mandatory/ft_filling.c mandatory/ft_hook.c mandatory/ft_moves.c mandatory/ft_parse_map.c mandatory/ft_setup.c mandatory/ft_valid_chars.c mandatory/ft_valid_map.c mandatory/ft_valid_wall.c mandatory/get_next_line_utils.c mandatory/get_next_line.c mandatory/so_long.c mandatory/utils.c 
OBJ_M = $(SRC_M:.c=.o)
# OBJ_B = $(SRC_B:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address -g
MLX = -Imlx -Lmlx -lmlx -Imlx -lXext -lX11 -lm -lz
RM = rm -rf
INCLUDE_M = so_long.h

all: $(NAME_M) stock

stock : $(OBJ_M)
	mkdir objects
	mv mandatory/*.o objects

$(NAME_M): $(OBJ_M)
	$(CC) $(CFLAGS) $(OBJ_M) $(MLX) -o $(NAME_M)

%.o: %.c $(INCLUDE_M)
	$(CC) $(CFLAGS) -c $< -o $@

# bonus: $(NAME_B)

# $(NAME_B): $(OBJ_B)
# 	$(CC) $(CFLAGS) $^ -o $@

# %_bonus.o: %_bonus.c $(INCLUDE_B)
# 	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_M)

fclean: clean
	$(RM) $(NAME_M) objects

re: fclean all

.PHONY: all clean fclean re bonus