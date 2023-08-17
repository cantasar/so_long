#include "../so_long.h"

int read_map(t_data *game, char *map)
{
	char *line;
	char *all;

	all = NULL;
	game->map_fd = open(map, O_RDONLY);
	printf("%d\n", game->map_fd);
	game->height_map = 0;

	while (1)
	{
		game->height_map++;
		line = get_next_line(game->map_fd);
		if (!line)
			break;
		if (line[0] == '\n')
		{
			write(1, "Empty line in map!\n", 19);
			exit(1);
		}
		printf("%d\n", game->height_map);
		all = gnl_strjoin(all, line);
	}
	if (!all)
	{
		write(1, "Map is empty!  \n", 14);
		exit(1);
	}
	
	if (game->map)
		free(game->map);
	game->map = ft_split(all, '\n');
	close(game->map_fd);
	return (1);
}
