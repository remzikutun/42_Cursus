/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:44:56 by rkutun            #+#    #+#             */
/*   Updated: 2024/02/19 14:05:45 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdbool.h>

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_chr
{
	size_t	px;
	size_t	py;
}		t_chr;

typedef struct s_map
{
	char	**map;
	size_t	width;
	size_t	height;
	size_t	ex;
	size_t	ey;
	size_t	pc;
	size_t	cc;
	size_t	ec;
	size_t	sc;
}		t_map;

typedef struct s_game
{
	struct s_map	t_map;
	struct s_map	c_map;
	struct s_chr	t_chr;
	char			*map_name;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*c_image;
	void			*ex_image;
	void			*p_image;
	void			*f_image;
	void			*w_image;
}		t_game;

bool	ft_extension_check(char *ext);
bool	ft_map_control(t_game *game, size_t y, size_t x);
bool	ft_file_saving(char *map_name, t_game *game);
void	ft_start_game(t_game *game);
int		ft_motion_control(int key, t_game *game);
int		ft_free2(t_game *game);
void	ft_draw_win(t_game *game);
void	ft_pathfinding(t_map *map, int y, int x);

#endif