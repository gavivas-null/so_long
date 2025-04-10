#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../Libft/libft.h"

typedef struct s_textures
{
	void	*grass;
	void	*wall;
	void	*exit;
	void	*collect;
	void	*player;
}   t_textures;
char	**ft_lst_2_array(t_list *list);
char	**ft_read_map(char *map);
void	ft_get_map_size(char **map, int *width, int *height);
int		ft_check_valid_chars(char **map);
int		ft_check_walls(char **map) ;
int	    ft_check_required_elements(char **map);
int		ft_check_rectangular(char **map);
char	**ft_copy_map(char **map);
void	ft_find_player(char **map, int *x_player, int *y_player);
void	ft_flood_fill(char **map, int x, int y);
int		ft_map_playable(char **map);
int		ft_validate_path(char **map);
int		ft_validate_map(char **map);
void	ft_load_textures(void *mlx, t_textures *tx);
void	ft_draw_all_textures(char **map, void *mlx, void *win, t_textures *tx);
void	ft_draw_floor(char **map, void *mlx, void *win, void *grass);
void	ft_draw_walls(char **map, void *mlx, void *win, void *wall);
void	ft_draw_exit(char **map, void *mlx, void *win, void *exit);
void	ft_draw_collect(char **map, void *mlx, void *win, void *collect);
void	ft_draw_player(char **map, void *mlx, void *win, void *player);



# define TILE  256

#endif