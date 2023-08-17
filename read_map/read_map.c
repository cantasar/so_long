#include "../so_long.h"

int read_map(t_data *game, char *map)
{
	char *line;

	game->map_all = NULL;
	game->map_fd = open(map, O_RDONLY);
	game->height_map = 0;
	while (1)
	{
		game->height_map++;
		line = get_next_line(game->map_fd);
		if (!line)
			break;
		empty_line(line);
		game->map_all = gnl_strjoin(game->map_all, line);
		free(line);
	}
	empty_map(game->map_all);
	count_items(game, game->map_all);
	if (game->map)
		free(game->map);
	game->map = ft_split(game->map_all, '\n');
	game->control_map = ft_split(game->map_all, '\n');
	close(game->map_fd);
	free(game->map_all);
	return (1);
}
