/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_saving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:50:46 by rkutun            #+#    #+#             */
/*   Updated: 2024/02/20 11:42:05 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>

static size_t	ft_map_size(int fd, t_game *game)
{
	size_t	i;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (close(fd), ft_putendl_fd("Map line reading error.", 2), 0);
	game->t_map.width = ft_strlen(line) - 1;
	i = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
	}
	close(fd);
	return (i);
}

static bool	ft_read_map2(t_game *game, size_t size, int fd)
{
	char	*line;
	char	*tmp;

	while (game->t_map.height < size)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = ft_strtrim(line, "\n");
		if (!tmp)
			return (ft_free2(game), 0);
		free(line);
		line = tmp;
		if (game->t_map.width != ft_strlen(line))
			return (free(tmp), ft_putendl_fd("Map lines are not equal.", 2), 0);
		game->t_map.map[game->t_map.height] = ft_strdup(line);
		if (!game->t_map.map[game->t_map.height])
			return (ft_free2(game), 0);
		free(tmp);
		game->t_map.height++;
	}
	return (1);
}

static bool	ft_read_map(int fd, t_game *game)
{
	size_t	size;

	size = ft_map_size(fd, game);
	if (!size)
		return (0);
	fd = open(game->map_name, O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("The file could not be opened.", 2), 0);
	game->t_map.map = (char **)malloc(size * sizeof(char *));
	if (!game->t_map.map)
		return (ft_putendl_fd("Could not create space in memory.", 2), 0);
	if (ft_read_map2(game, size, fd) == 0)
		return (ft_free2(game), 0);
	return (1);
}

bool	ft_file_saving(char *map_name, t_game *game)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("File could not be read.", 2), 0);
	game->map_name = map_name;
	if (ft_read_map(fd, game) == 0)
		return (close(fd), 0);
	close(fd);
	if (ft_map_control(game, 0, 0) == 0)
		return (ft_free2(game), 0);
	return (1);
}
