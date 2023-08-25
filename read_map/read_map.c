/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:41:22 by ctasar            #+#    #+#             */
/*   Updated: 2023/08/25 16:53:35 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	loc_p(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->p_x = j;
				game->p_y = i;
			}
			if (game->map[i][j] == 'E')
			{
				game->e_x = j;
				game->e_y = i;
			}
			j++;
		}
		i++;
	}
}

int	read_map(t_data *game, char *map)
{
	char	*line;

	game->map_all = NULL;
	game->map_fd = open(map, O_RDONLY);
	while (1)
	{
		line = get_next_line(game->map_fd);
		if (!line)
			break ;
		game->height_map++;
		empty_line(line);
		game->map_all = gnl_strjoin(game->map_all, line);
		free(line);
	}
	empty_map(game->map_all);
	count_items(game, game->map_all);
	if (game->map)
		free(game->map);
	game->map = ft_split(game->map_all, '\n');
	is_rectangular(game);
	game->control_map = ft_split(game->map_all, '\n');
	close(game->map_fd);
	free(game->map_all);
	return (1);
}
