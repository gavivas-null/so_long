#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "../Libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# define TILE		64

//------------------------------------------------ STRUCTS ------------------------------------------------
typedef struct s_textures
{
	mlx_image_t	*grass;
	mlx_image_t	*wall;
	mlx_image_t	*exit;
	mlx_image_t	*collect;
	mlx_image_t	*player;
}   t_textures;

typedef struct s_player
{
	mlx_image_t	*right[3];
	mlx_image_t	*left[3];
	mlx_image_t	*front[3];
	mlx_image_t	*back[3];
	int			anim_frame;
	char		direction;
}t_player;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*player_img;
	mlx_image_t *move_txt;
	t_textures 	tx;
	t_player	player;
	void		*win;
	char		**map;
	int			player_x;
	int			player_y;
	int			width;
	int			height;
	int			moves;
	int			point;
	int			total_collectibles;
} t_game;



//------------------------------------------------ FUNCIONES ------------------------------------------------

//Validaciones
int			ft_check_valid_chars(t_game *game);
int			ft_check_walls(t_game *game);
int			ft_check_elements(t_game *game, int p_count, int e_count, int c_count);
int			ft_check_rectangular(t_game *game);
int			ft_validate_map(t_game *game);
int			ft_validate_path(t_game *game);
int			ft_map_playable(char **copy_map);
int			ft_check_ber(char *filename);


//Lectura del mapa
char		**ft_read_map(char *filename);
char		**ft_lst_2_array(t_list *list);
void		ft_get_map_size(t_game *game);
char		**ft_copy_map(t_game *game);

//Flood Fill
void		ft_find_player(char **copy_map, t_game *game);
void		ft_flood_fill(char **copy_map, int x, int y, t_game *game);

//Graficos
void		ft_draw_map(t_game *game, t_textures *tx, int x, int y);
void		ft_draw_all_textures(mlx_t *mlx, t_game *game, t_textures *tx);
void		ft_draw_player(t_game *game, t_textures *tx);
mlx_image_t	*ft_load_png(mlx_t *mlx, char *path);
void		ft_disable_collect_at(t_game *game, int x, int y);

//Controles
void		ft_key_hook(mlx_key_data_t keydata, void *param);
void		ft_move_player(t_game *game, int new_x, int new_y);
void		ft_close_windows(void *param);


//Bonus
void	draw_moves_bonus(t_game *game);
void	load_player_sprites(t_game *game);
void	update_player_sprites(t_game *game);


//------------------------------------------------ DEFINIR ------------------------------------------------

#endif