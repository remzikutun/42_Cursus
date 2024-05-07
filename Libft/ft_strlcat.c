/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:21:41 by rkutun            #+#    #+#             */
/*   Updated: 2023/10/13 11:22:59 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lenght;

	lenght = ft_strlen(dst);
	i = 0;
	if (lenght >= dstsize)
		return (dstsize + ft_strlen(src));
	i = lenght;
	while (src[lenght - i] != 0 && lenght < (dstsize - 1))
	{
		dst[lenght] = src[lenght - i];
		lenght++;
	}
	dst[lenght] = '\0';
	return (i + ft_strlen(src));
}
