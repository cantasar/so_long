//width control
//wall cont
//

#include "../so_long.h"

void empty_line(char *line)
{
	if (line[0] == '\n')
	{
		write(1, "Empty line in map!\n", 19);
		exit(1);
	}
}

void empty_map(char *all)
{
	if (!all)
	{
		write(1, "Map is empty!  \n", 14);
		exit(1);
	}
}

void count_items(t_data *game, char *all)
{
	int i;

	i = 0;
	undefined_char(game);
	while (all[i])
	{
		if (all[i] == 'P')
			game->count_player++;
		if (all[i] == 'C')
			game->count_col++;
		if (all[i] == 'E')
			game->count_exit++;
		if (all[i] == 'J')
			game->count_enemy++;
		i++;
	}
	check_counts(game);
}

void check_counts(t_data *game)
{
	if (game->count_player != 1 || game->count_exit != 1 || game->count_col <= 0)
	{
		if (game->count_player != 1)
			write(1, "Number of player must be 1\n", 27);
		if (game->count_exit != 1)
			write(1, "Number of exit must be 1\n", 25);
		if (game->count_col <= 0)
			write(1, "Must contain at least one collectible\n", 38);
		exit(1);
	}
}

void undefined_char(t_data *game)
{
	int i;

	i = 0;
	while (game->map_all[i])
	{
		if (game->map_all[i] == '0' || game->map_all[i] == '1' || game->map_all[i] == 'P' || game->map_all[i] == 'C' || game->map_all[i] == 'J' || game->map_all[i] == 'E')
		{
			i++;
		}else
		{
			write(1, "undefined char in map\n", 23);
			printf("%c", game->map_all[i]);
			exit(1);
		}
	}
}
