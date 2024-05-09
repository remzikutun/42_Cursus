/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:54:52 by rkutun            #+#    #+#             */
/*   Updated: 2024/02/01 11:36:57 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	get_pivot(t_container *stack)
{
	int	min;
	int	max;

	min = stack->index;
	max = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (((min + max) / 2) + ((min + max) % 2));
}

static void	ft_sort(t_stack **stack_a, t_stack **stack_b,
		int max_index, int min_index)
{
	int	pivot_a;
	int	item;
	int	len;

	pivot_a = ((max_index + min_index) / 2) + (max_index + min_index) % 2;
	len = max_index - min_index + 1;
	item = len;
	while ((len / 2) + (len % 2) != item)
	{
		if ((*stack_a)->container->index < pivot_a && item--)
			p(stack_a, stack_b, 'b');
		else if ((*stack_b)->size > 2
			&& (*stack_b)->container->index <= get_pivot((*stack_b)->container))
		{
			all_r(stack_a, stack_b, 1);
		}
		else
			r(stack_a, 'a');
	}
	sa_push_b_opretion(stack_a, stack_b, max_index, pivot_a);
	sb_push_a_opretion(stack_a, stack_b, pivot_a - 1, min_index);
}

static void	set_stack_value(t_stack **stack_a, t_stack **stack_b)
{
	(*stack_a)->size = 0;
	(*stack_a)->container = NULL;
	(*stack_b)->size = 0;
	(*stack_b)->container = NULL;
}

static int	push_swap(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		res;

	res = is_check(ac, (av + 1), 1);
	if (res == 0)
		return (0);
	else if (res == 2)
		return (1);
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_b || !stack_a)
		return (free_stack(&stack_a, &stack_b), 1);
	set_stack_value(&stack_a, &stack_b);
	if (stack_operations(ac, av, &stack_a) == 0)
		return (free_stack(&stack_a, &stack_b), 1);
	container_index(&stack_a);
	if (stack_a->size == 3)
		sa_sort_three(&stack_a, &stack_b);
	else if (stack_a->size == 2)
		s(&stack_a, 'a');
	else
		ft_sort(&stack_a, &stack_b, stack_a->size, 1);
	return (free_stack(&stack_a, &stack_b), 0);
}

int	main(int ac, char **av)
{
	if (ac >= 2)
		return (push_swap(ac, av));
	else
		return (0);
}
