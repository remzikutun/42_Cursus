/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:07:04 by rkutun            #+#    #+#             */
/*   Updated: 2024/02/09 16:58:34 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdbool.h>

bool	ft_extension_check(char *ext)
{
	size_t	i;

	i = ft_strlen(ext) - 1;
	if (ext[i] == 'r' && ext[i - 1] == 'e'
		&& ext[i - 2] == 'b' && ext[i - 3] == '.')
		return (1);
	return (0);
}
