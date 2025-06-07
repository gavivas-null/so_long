/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:52:41 by gavivas-          #+#    #+#             */
/*   Updated: 2025/05/05 17:39:30 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "../Libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# define TILE		64

//------------------------- STRUCTS -------------------------
typedef struct s_textures
{
	mlx_image_t	*grass;
	mlx_image_t	*wall;
	mlx_image_t	*exit;
	mlx_image_t	*collect;
	mlx_image_t	*player;
}	t_textures;

typedef struct s_player
{
	mlx_image_t	*right[3];
	mlx_image_t	*left[3];
	mlx_image_t	*front[3];
	mlx_image_t	*back[3];
	int			anim_frame;
	char		direction;
}	t_player;

typedef struct s_enemy
{
	int			enemy_x;
	int			enemy_y;
	mlx_image_t	*sprites[4];
	char		direction;
	int			anim_frame;
}	t_enemy;

typedef struct s_exit
{
	mlx_image_t	*sprites[2];
	int			exit_x;
	int			exit_y;
	int			anim_frame;
}	t_exit;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*player_img;
	mlx_image_t	*move_txt;
	t_textures	tx;
	t_exit		exit;
	t_player	player;
	t_enemy		enemy;
	t_enemy		enemies[10];
	void		*win;
	char		**map;
	int			player_x;
	int			player_y;
	int			width;
	int			height;
	int			moves;
	int			point;
	int			total_collectibles;
	int			screen_h;
	int			screen_w;
}	t_game;

//------------------------- FUNCIONES -------------------------

//Validaciones
int			ft_check_valid_chars(t_game *game);
int			ft_check_walls(t_game *game);
int			ft_check_elements(t_game *game, int p_count,
				int e_count, int c_count);
int			ft_check_rectangular(t_game *game);
int			ft_validate_map(t_game *game);
int			ft_validate_path(t_game *game);
int			ft_map_playable(char **copy_map);
int			ft_check_ber(char *filename);
int			check_map_size(t_game *game);

//Lectura del mapa
char		**ft_read_map(char *filename);
char		**ft_lst_to_array(t_list *list);
void		ft_get_map_size(t_game *game);
char		**ft_copy_map(t_game *game);

//Flood Fill
void		ft_find_player(char **copy_map, t_game *game);
void		ft_flood_fill(char **copy_map, int x, int y, t_game *game);

//Graficos
void		ft_draw_map(t_game *game, t_textures *tx, int x, int y);
void		ft_draw_all_textures(t_game *game, t_textures *tx);
void		ft_draw_player(t_game *game, t_textures *tx);
mlx_image_t	*ft_load_png(t_game *game, char *path);
void		ft_disable_collect_at(t_game *game, int x, int y);

//Controles
void		ft_key_hook(mlx_key_data_t keydata, void *param);
void		ft_move_player(t_game *game, int new_x, int new_y);
void		ft_close_windows(void *param);
void		clean_exit(t_game *game, int code);

//Bonus
void		draw_moves_bonus(t_game *game);
void		load_player_sprites(t_game *game);
void		update_player_sprites(t_game *game, t_player *player);
void		ft_player_sprites(t_game *game, int x, int y);
void		disable_all_player_sprites(t_game *game);
void		ft_draw_enemy(t_game *game, t_enemy *enemy);
void		update_enemy_sprites(t_game *game, t_enemy *enemy);
void		ft_enemy_sprites(t_game *game, int x, int y);
void		disable_all_enemy_sprites(t_game *game);
void		load_enemy_sprites(t_game *game);
void		end_game(t_game *game, int new_x, int new_y);
void		update_player_sprites2(t_game *game, t_player *player);
void		ft_key_hook2(mlx_key_data_t keydata, t_game *game);
void		load_exit_sprites(t_game *game);
void		disable_all_exit_sprites(t_game *game);
void		ft_exit_sprites(t_game *game, int x, int y);
void		update_exit_sprites(t_game *game, t_exit *exit);
void		ft_draw_exit(t_game *game, t_exit *exit);
void		init_int(t_game *game);

//------------------------- DEFINIR -------------------------

#endif