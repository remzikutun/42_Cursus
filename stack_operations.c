/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:55:18 by rkutun            #+#    #+#             */
/*   Updated: 2024/01/29 12:59:36 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static t_container	*value_set(int value)
{
	t_container	*tmp;

	tmp = (t_container *)malloc(sizeof(t_container));
	if (!tmp)
		return (NULL);
	tmp->value = value;
	tmp->index = -1;
	tmp->next = 0;
	return (tmp);
}

static int	two_argumant_fill_container(t_stack **stack_a, char **av)
{
	t_container	*container;
	t_container	*container_tmp;
	char		**tmp;
	int			i;

	tmp = ft_split(av[1], ' ');
	if (tmp[1] == 0)
		return (ft_free(tmp), 0);
	container = value_set(ft_atoi(tmp[0]));
	if (!container)
		return (0);
	(*stack_a)->container = container;
	i = 0;
	while (tmp[++i])
	{
		container_tmp = value_set(ft_atoi(tmp[i]));
		if (!tmp)
			return (0);
		if (ft_list_container_add_back(&container, container_tmp) == 0)
			return (0);
	}
	ft_free(tmp);
	return (1);
}

static int	fill_container(t_stack **stack_a, int ac, char **av)
{
	t_container	*container;
	t_container	*tmp;
	int			i;

	container = value_set(ft_atoi(av[1]));
	if (!container)
		return (0);
	(*stack_a)->container = container;
	i = 2;
	while (i < ac)
	{
		tmp = value_set(ft_atoi(av[i]));
		if (!tmp)
			return (0);
		if ((ft_list_container_add_back(&container, tmp)) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	stack_operations(int ac, char **av, t_stack **stack_a)
{
	if (ac == 2)
	{
		if (!two_argumant_fill_container(stack_a, av))
			return (0);
	}
	else
		if (!fill_container(stack_a, ac, av))
			return (0);
	(*stack_a)->size = ft_list_size((*stack_a)->container);
	return (1);
}
