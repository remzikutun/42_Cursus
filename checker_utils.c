/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:52:48 by rkutun            #+#    #+#             */
/*   Updated: 2024/01/29 12:52:49 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	a;
	size_t	lenght_s2;
	size_t	lenght_s1;

	lenght_s1 = ft_strlen(s1);
	lenght_s2 = ft_strlen(s2);
	a = 0;
	while (a < lenght_s2 && a < lenght_s1)
	{
		if ((unsigned char)s1[a] != (unsigned char)s2[a])
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
		a++;
	}
	return (0);
}

void	chk_p(t_stack **stack_a, t_stack **stack_b, char flag)
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
	}
	else if ((*stack_a)->size && flag == 'b')
	{
		(*stack_a)->size--;
		(*stack_b)->size++;
		tmp = (*stack_a)->container;
		(*stack_a)->container = (*stack_a)->container->next;
		tmp->next = (*stack_b)->container;
		(*stack_b)->container = tmp;
	}
}
