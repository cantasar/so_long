#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "gnl/get_next_line.h"
# include "libft/libft.h"

typedef	struct	s_data
{
	// void *mlx;
	// void *mlx_win;

	int map_fd;
	char *map_all;
	char **map;
	char **control_map;

	int count_player;
	int count_col;
	int count_exit;
	int count_start;
	int count_enemy;

	int height_map;
	// int width_map;

}	t_data;

int read_map(t_data *game, char *map);
void ber_control(char *dest);
void empty_line(char *line);
void empty_map(char *all);
void count_items(t_data *game, char *all);
void check_counts(t_data *game);
void undefined_char(t_data *game);


char	*get_next_line(int fd);

#endif