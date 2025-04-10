NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	src/so_long.c \
		src/ft_draw_textures.c \
		src/ft_map.c \
		src/ft_validate_map.c \
		src/ft_validate_map2.c \
		src/ft_handle_keys.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux
MLX_FLAGS = -L $(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES = -I include -I libft

LIBFT = Libft/libft.a

$(NAME): $(OBJS)
	$(MAKE) -C Libft
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C Libft clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C Libft fclean

re: fclean all

.PHONY: all clean fclean re