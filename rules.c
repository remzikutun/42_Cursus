/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:55:05 by rkutun            #+#    #+#             */
/*   Updated: 2024/01/29 12:55:07 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	r(t_stack **stack, char flag)
{
	t_container	*tmp;

	if ((*stack)->container && (*stack)->container->next)
	{
		tmp = (*stack)->container;
		(*stack)->container = (*stack)->container->next;
		ft_list_container_add_back(&(*stack)->container, tmp);
		tmp->next = NULL;
		if (flag == 'a')
			ft_putendl_fd("ra", 1);
		else if (flag == 'b')
			ft_putendl_fd("rb", 1);
	}
}

void	s(t_stack **stack, char flag)
{
	t_container	*tmp;

	if ((*stack)->container && (*stack)->container->next)
	{
		tmp = (*stack)->container;
		(*stack)->container = (*stack)->container->next;
		tmp->next = (*stack)->container->next;
		(*stack)->container->next = tmp;
		if (flag == 'a')
			ft_putendl_fd("sa", 1);
		else if (flag == 'b')
			ft_putendl_fd("sb", 1);
	}
}

void	p(t_stack **stack_a, t_stack **stack_b, char flag)
{
	t_container	*tmp;

	if ((*stack_b)->size && flag == 'a')
	{
		(*stack_a)->size++;
		(*stack_b)->size--;
		tmp = (*stack_b)->container;
		(*stack_b)->container = (*stack_b)->container->next;
		tmp->next = (*stack_a)->container;
		(*stack_a)->container = tmp;
		ft_putendl_fd("pa", 1);
	}
	else if ((*stack_a)->size && flag == 'b')
	{
		(*stack_a)->size--;
		(*stack_b)->size++;
		tmp = (*stack_a)->container;
		(*stack_a)->container = (*stack_a)->container->next;
		tmp->next = (*stack_b)->container;
		(*stack_b)->container = tmp;
		ft_putendl_fd("pb", 1);
	}
}

void	rr(t_stack **stack, int flag)
{
	t_container	*tmp;
	t_container	*tmp2;

	if ((*stack)->container && (*stack)->container->next)
	{
		tmp = (*stack)->container;
		while (tmp->next)
			tmp = tmp->next;
		tmp2 = tmp;
		tmp = (*stack)->container;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next = NULL;
		tmp2->next = (*stack)->container;
		(*stack)->container = tmp2;
		if (flag == 'a')
			ft_putendl_fd("rra", 1);
		else if (flag == 'b')
			ft_putendl_fd("rrb", 1);
	}
}
