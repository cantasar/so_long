/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:06:03 by ctasar            #+#    #+#             */
/*   Updated: 2023/08/20 22:52:54 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_win(t_data *game)
{
	// mlx_destroy_image(game->mlx, game->bg);
	// mlx_destroy_image(game->mlx, game->block);
	// mlx_destroy_image(game->mlx, game->chr);
	// mlx_destroy_image(game->mlx, game->coin);
	// mlx_destroy_image(game->mlx, game->exit);
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(1);
	return (0);
}
