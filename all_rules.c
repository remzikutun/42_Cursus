/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:52:38 by rkutun            #+#    #+#             */
/*   Updated: 2024/01/29 12:52:39 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	all_r(t_stack **stack_a, t_stack **stack_b, int flag)
{
	if ((*stack_a)->container || (*stack_b)->container)
	{
		r(stack_a, 0);
		r(stack_b, 0);
		if (flag == 1)
			ft_putendl_fd("rr", 1);
	}
}

void	all_s(t_stack **stack_a, t_stack **stack_b, int flag)
{
	if ((*stack_a)->container || (*stack_b)->container)
	{
		s(stack_a, 0);
		s(stack_b, 0);
		if (flag == 1)
			ft_putendl_fd("ss", 1);
	}
}

void	all_rr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	if ((*stack_a)->container || (*stack_b)->container)
	{
		rr(stack_a, 0);
		rr(stack_b, 0);
		if (flag == 1)
			ft_putendl_fd("rrr", 1);
	}
}

void	ss_push(t_stack **first_stack, t_stack **second_stack, char flag)
{
	if ((*second_stack)->size >= 2 && (*second_stack)->container->index
		< (*second_stack)->container->next->index)
		all_s(first_stack, second_stack, 1);
	else
		s(first_stack, flag);
}
