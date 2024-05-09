/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:53:18 by rkutun            #+#    #+#             */
/*   Updated: 2024/01/29 12:53:19 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_container	*get_next_min(t_stack *stack_a)
{
	t_container	*tmp;
	t_container	*min;
	int			flag;	

	flag = 0;
	tmp = stack_a->container;
	min = 0;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if ((flag == 0 || tmp->value > min->value) && tmp->index == -1)
		{
			min = tmp;
			flag = 1;
		}
		tmp = tmp->next;
	}
	return (min);
}

void	container_index(t_stack **stack_a)
{
	long int	index;
	t_container	*min;

	index = ft_list_size((*stack_a)->container);
	min = get_next_min(*stack_a);
	while (min)
	{
		min->index = index;
		min = get_next_min(*stack_a);
		index--;
	}
}
