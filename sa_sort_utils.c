/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:55:10 by rkutun            #+#    #+#             */
/*   Updated: 2024/01/29 12:55:11 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sort_three(t_stack **stack_a, t_stack **stack_b)
{
	t_three_element	a;

	a.first = (*stack_a)->container->index;
	a.second = (*stack_a)->container->next->index;
	a.third = (*stack_a)->container->next->next->index;
	if (a.first > a.second && a.second > a.third && a.third < a.first)
	{
		ss_push(stack_a, stack_b, 'a');
		rr(stack_a, 'a');
	}
	else if (a.first > a.second && a.second < a.third && a.third < a.first)
		r(stack_a, 'a');
	else if (a.first < a.second && a.second > a.third && a.third < a.first)
		rr(stack_a, 'a');
	else if (a.first > a.second && a.second < a.third && a.third > a.first)
		ss_push(stack_a, stack_b, 'a');
	else if (a.first < a.second && a.second > a.third && a.third > a.first)
	{
		r(stack_a, 'a');
		ss_push(stack_a, stack_b, 'a');
		rr(stack_a, 'a');
	}
}

static void	sa_more_than_3_three_sort2(t_stack **stack_a, t_stack **stack_b,
			t_three_element a)
{
	if (a.first < a.second && a.second > a.third && a.third < a.first)
	{
		r(stack_a, 'a');
		ss_push(stack_a, stack_b, 'a');
		rr(stack_a, 'a');
		s(stack_a, 'a');
	}
	else if (a.first > a.second && a.second < a.third && a.third > a.first)
		ss_push(stack_a, stack_b, 'a');
	else if (a.first < a.second && a.second > a.third && a.third > a.first)
	{
		r(stack_a, 'a');
		ss_push(stack_a, stack_b, 'a');
		rr(stack_a, 'a');
	}
}

void	sa_more_than_3_three_sort(t_stack **stack_a, t_stack **stack_b,
			t_three_element a)
{
	if (a.first > a.second && a.second > a.third && a.third < a.first)
	{
		ss_push(stack_a, stack_b, 'a');
		r(stack_a, 'a');
		s(stack_a, 'a');
		rr(stack_a, 'a');
		s(stack_a, 'a');
	}
	else if (a.first > a.second && a.second < a.third && a.third < a.first)
	{
		ss_push(stack_a, stack_b, 'a');
		r(stack_a, 'a');
		s(stack_a, 'a');
		rr(stack_a, 'a');
	}
	else
		sa_more_than_3_three_sort2(stack_a, stack_b, a);
}

int	is_container_sorted(t_stack *stack, int max_index, int min_index)
{
	t_container	*tmp;

	tmp = stack->container;
	while (max_index - min_index + 1)
	{
		if (tmp->index != min_index)
			return (0);
		tmp = tmp->next;
		min_index++;
	}
	return (1);
}
