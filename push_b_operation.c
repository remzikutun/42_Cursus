/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:54:42 by rkutun            #+#    #+#             */
/*   Updated: 2024/01/29 12:54:43 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sb_push(t_stack **stack_a, t_stack **stack_b,
				int max_index, int min_index)
{
	int				len;
	t_three_element	b;

	b.first = (*stack_b)->container->index;
	b.second = (*stack_b)->container->next->index;
	if ((*stack_b)->size > 2)
		b.third = (*stack_b)->container->next->next->index;
	len = max_index - min_index + 1;
	if (is_container_reverse_sorted(*stack_b, max_index, min_index) == 1)
		while (len--)
			p(stack_a, stack_b, 'a');
	else if (len == 2)
	{
		s(stack_b, 'b');
		p(stack_a, stack_b, 'a');
		p(stack_a, stack_b, 'a');
	}
	else if (len == 3 && (*stack_b)->size == 3)
		sb_reverse_sort_three(stack_a, stack_b, b);
	else if (len == 3)
		sb_a_push_sort_three(stack_a, stack_b, b);
}

void	sb_push_a_opretion(t_stack **stack_a, t_stack **stack_b,
							int max_index, int min_index)
{
	int	pivot;
	int	item;
	int	len;
	int	r_count;

	r_count = 0;
	len = max_index - min_index + 1;
	pivot = ((max_index + min_index) / 2) + (max_index + min_index) % 2;
	if (len > 3)
	{
		item = len;
		while ((len / 2) < item)
			if ((*stack_b)->container->index >= pivot && item--)
				p(stack_a, stack_b, 'a');
		else if (++r_count)
			r(stack_b, 'b');
		while (r_count--
			&& (len / 2) + (len % 2) != (*stack_b)->size)
			rr(stack_b, 'b');
		sa_push_b_opretion(stack_a, stack_b, max_index, pivot);
		sb_push_a_opretion(stack_a, stack_b, pivot - 1, min_index);
	}
	else
		sb_push(stack_a, stack_b, max_index, min_index);
}

static	void	sa_push(t_stack **stack_a, t_stack **stack_b,
				int max_index, int min_index)
{
	t_three_element	a;
	int				len;

	a.first = (*stack_a)->container->index;
	a.second = (*stack_a)->container->next->index;
	if ((*stack_a)->size > 2)
		a.third = (*stack_a)->container->next->next->index;
	len = max_index - min_index + 1;
	if (is_container_sorted(*stack_a, max_index, min_index) == 1)
		return ;
	else if (len == 2
		&& (*stack_a)->container->index > (*stack_a)->container->next->index)
		ss_push(stack_a, stack_b, 'a');
	else if (len == 3 && (*stack_a)->size == 3)
		sa_sort_three(stack_a, stack_b);
	else if (len == 3)
		sa_more_than_3_three_sort(stack_a, stack_b, a);
}

void	sa_push_b_opretion(t_stack **stack_a, t_stack **stack_b,
							int max_index, int min_index)
{
	int	pivot;
	int	len;
	int	item;
	int	r_count;

	r_count = 0;
	pivot = ((max_index + min_index) / 2) + ((max_index + min_index) % 2);
	len = max_index - min_index + 1;
	if (len > 3)
	{
		item = len;
		while ((len / 2) + (len % 2) != item)
			if ((*stack_a)->container->index < pivot && item--)
				p(stack_a, stack_b, 'b');
		else if (++r_count != -1)
			r(stack_a, 'a');
		while ((len / 2) + (len % 2) != (*stack_a)->size
			&& r_count--)
			rr(stack_a, 'a');
		sa_push_b_opretion(stack_a, stack_b, max_index, pivot);
		sb_push_a_opretion(stack_a, stack_b, pivot - 1, min_index);
	}
	else
		sa_push(stack_a, stack_b, max_index, min_index);
}
