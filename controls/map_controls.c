/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:12:58 by ctasar            #+#    #+#             */
/*   Updated: 2023/08/22 11:06:53 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	empty_line(char *line)
{
	if (line[0] == '\n')
	{
		ft_printf("Empty line in map!\n");
		exit(1);
	}
}

void	empty_map(char *all)
{
	if (!all)
	{
		ft_printf("Map is empty!\n");
		exit(1);
	}
}

void	count_items(t_data *game, char *all)
{
	int	i;

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

void	check_counts(t_data *game)
{
	if (game->count_player != 1 || \
		game->count_exit != 1 || game->count_col <= 0)
	{
		if (game->count_player != 1)
			ft_printf("Number of player must be 1\n");
		if (game->count_exit != 1)
			ft_printf("Number of exit must be 1\n");
		if (game->count_col <= 0)
			ft_printf("Must contain at least one collectible\n");
		exit(1);
	}
}

void	undefined_char(t_data *game)
{
	int	i;

	i = 0;
	while (game->map_all[i])
	{
		if (game->map_all[i] == '0' || game->map_all[i] == '1' || \
			game->map_all[i] == 'P' || game->map_all[i] == 'C' || \
			game->map_all[i] == 'J' || game->map_all[i] == 'E' || \
			game->map_all[i] == '\n')
		{
			i++;
		}
		else
		{
			ft_printf("undefined char in map <%c>\n", game->map_all[i]);
			exit(1);
		}
	}
}
