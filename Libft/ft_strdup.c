/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:55:13 by rkutun            #+#    #+#             */
/*   Updated: 2023/10/14 12:17:59 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	lenght;
	char	*s2;

	lenght = ft_strlen(s1);
	s2 = (char *)malloc(lenght + 1);
	if (!s2)
		return (0);
	ft_memcpy (s2, s1, lenght + 1);
	return (s2);
}
