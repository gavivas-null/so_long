NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_MAIN = src/so_long.c

SRCS =	src/read_map.c \
		src/validate_map1.c \
		src/validate_map2.c \
		src/keys.c \
		src/draw_textures1.c \
		src/draw_textures2.c

SRCSBONUS = bonus/draw_moves_bonus.c \
			bonus/bonus_so_long.c

OBJS = $(SRCS:.c=.o)
OBJS_MAIN = $(SRC_MAIN:.c=.o)
OBJSBONUS = $(SRCSBONUS:.c=.o)

INCLUDES = -I include -I Libft -I MLX42/include

LIBFT = Libft/libft.a
MLX_LIB = MLX42/build/libmlx42.a
MLX_FLAGS = -ldl -lglfw -pthread -lm

# --------------------------------------------------------------
# Bonus
# --------------------------------------------------------------
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJSBONUS) $(OBJS)
	@$(MAKE) -C Libft > /dev/null
	@$(MAKE) libmlx
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJSBONUS) $(OBJS) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo "✅ Bonus compilado correctamente."


# --------------------------------------------------------------
# 👇 Regla principal
# --------------------------------------------------------------
all: $(NAME)

$(NAME): $(OBJS_MAIN) $(OBJS)
	@$(MAKE) -C Libft > /dev/null
	@$(MAKE) libmlx
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_MAIN) $(OBJS) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)
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
	@rm -f $(OBJS) $(OBJSBONUS)
	@$(MAKE) -C Libft clean > /dev/null
	@$(MAKE) -C MLX42/build clean > /dev/null
	@echo "🧹 Archivos objeto y temporales eliminados."

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@rm -f MLX42/build/libmlx42.a
	@rm -rf MLX42/build
	@$(MAKE) -C Libft fclean > /dev/null
	@echo "🧼 Todo limpio: binarios, Libft y MLX42."

re: fclean all

.PHONY: all clean fclean re libmlx
