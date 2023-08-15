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
	void *mlx;
	void *mlx_win;

	int map_fd;
	char **map;

	int count_player;
	int height_map;
	int width_map;

}	t_data;

int read_map(t_data *game, char *map);
void ber_control(char *dest);

char	*get_next_line(int fd);

#endif