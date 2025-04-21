NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	src/so_long.c \
		src/ft_read_map.c \
		src/ft_validate_map1.c \
		src/ft_validate_map2.c \
		src/ft_handle_keys.c \
		src/ft_draw_textures1.c \
		src/ft_draw_textures2.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I include -I Libft -I MLX42/include

LIBFT = Libft/libft.a
MLX_LIB = MLX42/build/libmlx42.a
MLX_FLAGS = -ldl -lglfw -pthread -lm

# --------------------------------------------------------------
# 👇 Regla principal
# --------------------------------------------------------------
all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C Libft > /dev/null
	@$(MAKE) libmlx
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)
	@echo "✅ Proyecto compilado correctamente."

# --------------------------------------------------------------
# 🛠 Compilar cada archivo fuente
# --------------------------------------------------------------
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@  > /dev/null
	@echo "🔧 Compilado: $<"

# --------------------------------------------------------------
# 📦 Compilación de MLX42
# --------------------------------------------------------------
libmlx:
	@cmake -B MLX42/build MLX42 > /dev/null
	@make -C MLX42/build -j4 > /dev/null
	@echo "📦 MLX42 compilada."

# --------------------------------------------------------------
# 🧹 Limpieza
# --------------------------------------------------------------
clean:
	@rm -f $(OBJS)
	@$(MAKE) -C Libft clean > /dev/null
	@$(MAKE) -C MLX42/build clean > /dev/null
	@echo "🧹 Archivos objeto y temporales eliminados."

fclean: clean
	@rm -f $(NAME)
	@rm -f MLX42/build/libmlx42.a
	@rm -rf MLX42/build
	@$(MAKE) -C Libft fclean > /dev/null
	@echo "🧼 Todo limpio: binarios, Libft y MLX42."

re: fclean all

.PHONY: all clean fclean re libmlx
