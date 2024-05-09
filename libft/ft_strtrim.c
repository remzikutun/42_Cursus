/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:59:49 by rkutun            #+#    #+#             */
/*   Updated: 2023/10/15 13:55:11 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned int	lenght;

	lenght = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 != '\0' && ft_strchr(set, *s1))
		s1++;
	lenght = ft_strlen(s1);
	while (lenght > 0 && ft_strchr(set, s1[lenght]))
		lenght--;
	return (ft_substr(s1, 0, lenght + 1));
}
