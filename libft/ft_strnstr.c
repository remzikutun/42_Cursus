/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:39:43 by rkutun            #+#    #+#             */
/*   Updated: 2023/10/13 17:05:38 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	index;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		index = 0;
		while (haystack[i + index] == needle[index] && (i + index) < len)
		{
			if ((haystack[i + index] == '\0') || (needle[index] == '\0'))
				return ((char *)&haystack[i]);
			index++;
		}
		if (needle[index] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
