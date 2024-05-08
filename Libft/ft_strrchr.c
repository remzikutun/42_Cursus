/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:39:37 by rkutun            #+#    #+#             */
/*   Updated: 2023/10/13 11:57:16 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	lenght;

	lenght = ft_strlen(s) + 1;
	while (lenght--)
	{
		if (s[lenght] == (char)c)
			return ((char *)&s[lenght]);
	}
	return (0);
}
