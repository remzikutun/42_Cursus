/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:17:18 by rkutun            #+#    #+#             */
/*   Updated: 2024/02/19 14:09:01 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"

int	main(int ac, char **av)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (ac == 2)
	{
		if (ft_extension_check(av[1]) == 0)
			return (ft_putendl_fd("Inappropriate use. Usage : (.ber)!", 2), 0);
		if (ft_file_saving(av[1], &game) == 0)
			return (0);
		ft_start_game(&game);
	}
	else
		ft_putendl_fd("Inappropriate use. Usage : ./so_long source_file", 2);
}
