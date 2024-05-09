/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:55:14 by rkutun            #+#    #+#             */
/*   Updated: 2024/01/29 12:55:15 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sb_a_push_sort_three2(t_stack **stack_a, t_stack **stack_b,
				t_three_element b)
{
	if (b.first > b.second && b.second < b.third
		&& b.third > b.first)
	{
		r(stack_b, 'b');
		s(stack_b, 'b');
		p(stack_a, stack_b, 'a');
		rr(stack_b, 'b');
		p(stack_a, stack_b, 'a');
		p(stack_a, stack_b, 'a');
	}
	else if (b.first < b.second && b.second < b.third && b.third > b.first)
	{
		r(stack_b, 'b');
		s(stack_b, 'b');
		p(stack_a, stack_b, 'a');
		p(stack_a, stack_b, 'a');
		rr(stack_b, 'b');
		p(stack_a, stack_b, 'a');
	}
}

void	sb_a_push_sort_three(t_stack **stack_a, t_stack **stack_b,
				t_three_element b)
{
	if (b.first > b.second && b.second < b.third && b.third < b.first)
	{
		p(stack_a, stack_b, 'a');
		s(stack_b, 'b');
		p(stack_a, stack_b, 'a');
		p(stack_a, stack_b, 'a');
	}
	else if (b.first < b.second && b.second > b.third && b.third < b.first)
	{
		s(stack_b, 'b');
		p(stack_a, stack_b, 'a');
		p(stack_a, stack_b, 'a');
		p(stack_a, stack_b, 'a');
	}
	else if (b.first < b.second && b.second > b.third && b.third > b.first)
	{
		s(stack_b, 'b');
		p(stack_a, stack_b, 'a');
		s(stack_b, 'b');
		p(stack_a, stack_b, 'a');
		p(stack_a, stack_b, 'a');
	}
	else
		sb_a_push_sort_three2(stack_a, stack_b, b);
}

static void	sb_reverse_sort_three2(t_stack **stack_a, t_stack **stack_b,
				t_three_element b)
{
	if (b.first < b.second && b.second < b.third && b.third > b.first)
	{
		r(stack_b, 'b');
		s(stack_b, 'b');
		p(stack_a, stack_b, 'a');
		p(stack_a, stack_b, 'a');
		p(stack_a, stack_b, 'a');
	}
	else if (b.first > b.second && b.second < b.third && b.third > b.first)
	{
		rr(stack_b, 'b');
		p(stack_a, stack_b, 'a');
		p(stack_a, stack_b, 'a');
		p(stack_a, stack_b, 'a');
	}
	else if (b.first < b.second && b.second > b.third && b.third > b.first)
	{
		r(stack_b, 'b');
		p(stack_a, stack_b, 'a');
		p(stack_a, stack_b, 'a');
		p(stack_a, stack_b, 'a');
	}
}

void	sb_reverse_sort_three(t_stack **stack_a, t_stack **stack_b,
				t_three_element b)
{
	if (b.first > b.second && b.second < b.third && b.third < b.first)
	{
		p(stack_a, stack_b, 'a');
		s(stack_b, 'b');
		p(stack_a, stack_b, 'a');
		p(stack_a, stack_b, 'a');
	}
	else if (b.first < b.second && b.second > b.third && b.third < b.first)
	{
		s(stack_b, 'b');
		p(stack_a, stack_b, 'a');
		p(stack_a, stack_b, 'a');
		p(stack_a, stack_b, 'a');
	}
	else
		sb_reverse_sort_three2(stack_a, stack_b, b);
}

int	is_container_reverse_sorted(t_stack *stack,
				int max_index, int min_index)
{
	t_container	*tmp;

	tmp = stack->container;
	while (max_index - min_index + 1)
	{
		if (tmp->index != max_index)
			return (0);
		tmp = tmp->next;
		max_index--;
	}
	return (1);
}
