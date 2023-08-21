/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:20:24 by ctasar            #+#    #+#             */
/*   Updated: 2023/08/20 22:56:25 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_xpm(t_data *game)
{
	int w = 64;
	game->bg = mlx_xpm_file_to_image(game->mlx, "./textures/bg2.xpm", &w, &w);
	game->chr = mlx_xpm_file_to_image(game->mlx, "./textures/by.xpm", &w, &w);
	game->block = mlx_xpm_file_to_image(game->mlx, "./textures/block1.xpm", &w, &w);
	game->coin = mlx_xpm_file_to_image(game->mlx, "./textures/bb8.xpm", &w, &w);
	game->enemy = mlx_xpm_file_to_image(game->mlx, "./textures/enemy1.xpm", &w, &w);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit2.xpm", &w, &w);
}

void	put_text(t_data *game)
{
	char *str;

	str = ft_itoa(game->score);
	mlx_string_put(game->mlx, game->mlx_win, 10, 10, 0xFFFFFFFF, str);
	free(str);
}

void	put_item(char type,int x, int y, t_data *game)
{
	if (type == '1' || type == '0' || type == 'P' || type == 'C' || type == 'E' || type == 'J')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->bg, x, y);
	if (type == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->block, x, y);
	if (type == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->chr, x, y);
	if (type == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->coin, x, y);
	if (type == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, x, y);	
	if (type == 'J')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->enemy, x, y);
	
}

void	put_textures(t_data *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 0;
	y = 20;
	i = 0;
	j = 0;
	put_text(game);
	while (game->map[i])
	{
		j = 0;
		x = 0;
		while (game->map[i][j])
		{
			put_item(game->map[i][j], x, y, game);
			x = x + 64;
			j++;
		}
		y = y + 64;
		i++;
	}
}
