/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:31:54 by rkutun            #+#    #+#             */
/*   Updated: 2024/02/20 11:44:11 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../mlx/mlx.h"

static void	ft_free3(t_game *game)
{
	size_t	i;

	if (game->t_map.map)
	{
		i = 0;
		while (i < game->t_map.height && game->t_map.map[i])
		{
			free(game->t_map.map[i]);
			i++;
		}
		free(game->t_map.map);
	}
	if (game->c_map.map)
	{
		i = 0;
		while (i < game->t_map.height && game->c_map.map[i])
		{
			free(game->c_map.map[i]);
			i++;
		}
		free(game->c_map.map);
	}
}

int	ft_free2(t_game *game)
{
	if (game->c_image)
		mlx_destroy_image(game->mlx_ptr, game->c_image);
	if (game->f_image)
		mlx_destroy_image(game->mlx_ptr, game->f_image);
	if (game->ex_image)
		mlx_destroy_image(game->mlx_ptr, game->ex_image);
	if (game->w_image)
		mlx_destroy_image(game->mlx_ptr, game->w_image);
	if (game->p_image)
		mlx_destroy_image(game->mlx_ptr, game->p_image);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	ft_free3(game);
	exit(1);
	return (0);
}
