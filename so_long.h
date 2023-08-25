/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:13:18 by ctasar            #+#    #+#             */
/*   Updated: 2023/08/25 11:56:26 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;

	int		map_fd;
	char	*map_all;
	char	**map;
	char	**control_map;

	int		count_player;
	int		count_col;
	int		count_exit;
	int		count_enemy;

	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;

	int		score;

	int		height_map;
	int		width_map;

	void	*bg;
	void	*chr;
	void	*block;
	void	*exit;
	void	*enemy;
	void	*coin_cur;
	void	*coin;
	void	*coin_l;
	void	*coin_r;

	int		animate_count;

}	t_data;

int		read_map(t_data *game, char *map);
void	loc_p(t_data *game);

void	ber_control(char *dest);
void	empty_line(char *line);
void	empty_map(char *all);
void	count_items(t_data *game, char *all);
void	check_counts(t_data *game);
void	undefined_char(t_data *game);
void	is_rectangular(t_data *game);
void	wall_control(t_data *game);

void	flood_fill(t_data *game, int x, int y);
void	check_filled_map(t_data *game);

void	get_xpm(t_data *game);
void	create_win(t_data *game);
int		close_win(t_data *game);
int		hook_keys(int keycode, t_data *game);
void	put_textures(t_data *game);
void	put_text(t_data *game);

void	change_coin(t_data *game);
int		loop(t_data *game);

char	*get_next_line(int fd);
int	ft_printf(const char *str, ...);

#endif