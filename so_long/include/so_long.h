#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../Libft/libft.h"

char	**ft_lst_2_array(t_list *list);
char	**ft_read_map(char *map);
void	ft_draw_floor(char **map, void *mlx, void *win, void *grass);
void	ft_get_map_size(char **map, int *width, int *height);



# define TILE  256

#endif