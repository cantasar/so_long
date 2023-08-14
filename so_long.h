#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "stdio.h"
# include "stdlib.h"
# include <unistd.h>
# include <fcntl.h>


typedef	struct	s_data
{
	void *mlx;
	void *mlx_win;

	int map_fd;
	int count_player;

}	t_data;

void read_map(t_data *game, char *map);
void ber_control(char *dest);

#endif