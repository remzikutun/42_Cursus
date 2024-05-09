/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:13:31 by rkutun            #+#    #+#             */
/*   Updated: 2023/10/14 11:45:28 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ram;

	ram = (void *)malloc(count * size);
	if (!ram)
		return (0);
	ft_bzero(ram, count * size);
	return (ram);
}
