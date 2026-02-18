NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = src/main.c src/parsing.c src/graphic.c src/utils.c src/line.c src/draw.c \
	src/hook.c gnl/get_next_line.c gnl/get_next_line_utils.c src/utils_error.c \
	src/render.c src/projection.c src/color.c
SRC_BONUS = src/main.c src/parsing.c src/graphic.c src/utils.c src/line.c src/draw.c \
	src/hook_bonus.c gnl/get_next_line.c gnl/get_next_line_utils.c src/utils_error.c \
	src/render.c src/projection.c src/color.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx.a
INCLUDES = -Iheader -Ignl -Ilibft -Iminilibx-linux -I/usr/include
MLX_LNK = -Lminilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz
LIBFT_LNK = -Llibft -lft

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LNK) $(MLX_LNK) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C libft

$(MLX):
	make -C minilibx-linux

bonus: .bonus

.bonus: $(OBJ_BONUS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT_LNK) $(MLX_LNK) -o $(NAME)
	touch .bonus

clean:
	rm -f $(OBJ) $(OBJ_BONUS) .bonus
	make -C libft clean
	make -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus
