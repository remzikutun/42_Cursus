/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:42:58 by rkutun            #+#    #+#             */
/*   Updated: 2023/10/17 11:36:09 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	lenght;
	unsigned int	index;

	if (!s || start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	lenght = 0;
	while (lenght < len && s[lenght + start] != '\0')
		lenght++;
	dest = (char *)malloc(sizeof(char) * (lenght + 1));
	if (dest == NULL)
		return (NULL);
	index = 0;
	while (lenght--)
		dest[index++] = s[start++];
	dest[index] = '\0';
	return (dest);
}
