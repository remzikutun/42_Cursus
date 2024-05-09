/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:56:57 by rkutun            #+#    #+#             */
/*   Updated: 2024/01/25 14:01:30 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_argumancounter(const char *s, char c)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (s && s[index])
	{
		if (s[index] != c)
		{
			count++;
			while (s[index] != c && s[index])
				index++;
		}
		else
			index++;
	}
	return (count);
}

static int	ft_stringcounter(const	char *s, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s[i] != c && s[i])
	{
		lenght++;
		i++;
	}
	return (lenght);
}

void	ft_free(char **strngs)
{
	int	i;

	i = 0;
	while (strngs[i])
	{
		free(strngs[i]);
		i++;
	}
	free(strngs);
}

char	**ft_split(const char *s, char c)
{
	int		ac;
	int		i;
	char	**strngs;
	int		j;

	if (!s)
		return (NULL);
	ac = ft_argumancounter(s, c);
	strngs = (char **)malloc(sizeof(char *) * (ac + 1));
	if (!strngs)
		return (NULL);
	i = 0;
	j = -1;
	while (++j < ac)
	{
		while (s[i] == c)
			i++;
		strngs[j] = ft_substr(s, i, ft_stringcounter(s, c, i));
		if (!(strngs[j]))
			return (ft_free(strngs), NULL);
		i += ft_stringcounter(s, c, i);
	}
	strngs[j] = NULL;
	return (strngs);
}
