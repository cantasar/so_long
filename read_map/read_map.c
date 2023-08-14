#include "../so_long.h"

void read_map(t_data *game, char *map)
{

	game->map_fd = open(map, O_RDONLY);
	printf("%d", game->map_fd);
	close(game->map_fd);
}
