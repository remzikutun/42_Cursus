/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:54:47 by rkutun            #+#    #+#             */
/*   Updated: 2024/02/05 11:30:01 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_container	*tmp;

	while (*stack_a && (*stack_a)->container)
	{
		tmp = (*stack_a)->container;
		(*stack_a)->container = (*stack_a)->container->next;
		free(tmp);
	}
	while (*stack_b && (*stack_b)->container)
	{
		tmp = (*stack_b)->container;
		(*stack_b)->container = (*stack_b)->container->next;
		free(tmp);
	}
	free(*stack_a);
	free(*stack_b);
}

static t_container	*ft_list_last(t_container *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

int	ft_list_container_add_back(t_container **lst, t_container *new)
{
	t_container	*tmp;

	if (!new || !lst)
		return (0);
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_list_last(*lst);
		if (!tmp)
			return (0);
		tmp->next = new;
	}
	return (1);
}

int	ft_list_size(t_container *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}
