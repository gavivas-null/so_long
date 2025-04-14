#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "../Libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

//------------------------------------------------ STRUCTS ------------------------------------------------
typedef struct s_textures
{
	mlx_image_t	*grass;
	mlx_image_t	*wall;
	mlx_image_t	*exit;
	mlx_image_t	*collect;
	mlx_image_t	*player;
}   t_textures;

typedef struct s_game
{
	mlx_t	*mlx;
	void	*win; //con codam ya no se necesita win porque mlx lo tiene todo.
	char	**map;
	t_textures tx;
	int		player_x;
	int		player_y;
	int		width;
	int		height;
	int		moves;
} t_game;

//------------------------------------------------ FUNCIONES ------------------------------------------------

//Validaciones
int			ft_check_valid_chars(t_game *game);
int			ft_check_walls(t_game *game);
int			ft_check_required_elements(t_game *game);
int			ft_check_rectangular(t_game *game);
int			ft_validate_map(t_game *game);
int			ft_validate_path(t_game *game);
int			ft_map_playable(char **copy_map);

//Lectura del mapa
char		**ft_read_map(char *filename);
char		**ft_lst_2_array(t_list *list);
void		ft_get_map_size(t_game *game);
char		**ft_copy_map(t_game *game);

//Flood Fill
void		ft_find_player(char **copy_map, t_game *game);
void		ft_flood_fill(char **copy_map, int x, int y, t_game *game);

//Graficos
void		ft_load_textures(mlx_t *mlx, t_textures *tx);
void		ft_draw_all_textures(t_game *game, t_textures *tx);
mlx_image_t	*ft_load_png(mlx_t *mlx, char *path);
void		ft_draw_floor(t_game *game, t_textures *tx);
void		ft_draw_walls(t_game *game, t_textures *tx);
void		ft_draw_exit(t_game *game, t_textures *tx);
void		ft_draw_collect(t_game *game, t_textures *tx);
void		ft_draw_player(t_game *game, t_textures *tx);

//Controles
void	ft_key_hook(void *param);

//------------------------------------------------ DEFINIR ------------------------------------------------
# define TILE		64

#endif