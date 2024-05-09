/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:14:22 by rkutun            #+#    #+#             */
/*   Updated: 2024/02/01 11:58:24 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>

void	*ft_free_stash(char **stash, int create_line,
						t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	if (!*stash)
		return (NULL);
	if (create_line == 0)
	{
		if (*stash)
		{
			free(*stash);
			*stash = NULL;
		}
		return (NULL);
	}
	else if (create_line == 1)
	{
		line = ft_strdup(*stash);
		if (!line)
			return (free_stack(stack_a, stack_b), exit(1), NULL);
		free(*stash);
		*stash = NULL;
		return (line);
	}
	return (NULL);
}

char	*ft_copy_to_stash(char *stash, char *buf, t_stack **stack_a,
							t_stack **stack_b)
{
	char	*res;

	res = 0;
	if (!stash && buf)
	{
		res = ft_strdup(buf);
		if (!res)
			return (free_stack(stack_a, stack_b), exit(1), NULL);
		return (res);
	}
	res = ft_strjoin(stash, buf);
	if (!res)
		return (free_stack(stack_a, stack_b), exit(1), NULL);
	ft_free_stash(&stash, 0, stack_a, stack_b);
	return (res);
}

int	ft_have_nl(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i] != '\0')
		if (s[i] == '\n')
			return (1);
	return (0);
}

char	*ft_extract_line(char *stash)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	j = 0;
	while (j < i + 1)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_recreate_stash(char *stash, t_stack **stack_a, t_stack **stack_b)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n')
		i++;
	if (stash[i + 1] == '\0')
		return (ft_free_stash(&stash, 0, stack_a, stack_b));
	res = ft_substr(stash, i + 1, ft_strlen(stash));
	if (!res)
	{
		ft_free_stash(&stash, 0, stack_a, stack_b);
		free_stack(stack_a, stack_b);
		return (NULL);
	}
	ft_free_stash(&stash, 0, stack_a, stack_b);
	return (res);
}
