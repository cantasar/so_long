/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:13:10 by ctasar            #+#    #+#             */
/*   Updated: 2023/08/18 23:19:20 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_data *game;

	if (argc == 2)
	{
		ber_control(argv[1]);
		//xpm_control();
		game = (t_data *)malloc(sizeof(t_data) * 1);
		game->height_map = 0;
		read_map(game, argv[1]);
		flood_fill(game, 1, 1);
		check_filled_map(game);
		create_win(game);
		
	}
	else
	{
		write(1, "Wrong usage\n./so_long <map path>\n", 33);
	}
	return (0);
}
