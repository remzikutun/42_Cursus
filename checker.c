/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:27:11 by rkutun            #+#    #+#             */
/*   Updated: 2024/02/01 11:58:56 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>

static char	*get_next_line(int fd, t_stack **stack_a,
							t_stack **stack_b, int bytes_read)
{
	char		buf[2];
	static char	*stash = NULL;
	char		*line;

	line = 0;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, 1);
		if (bytes_read == 0 && !stash)
			return (ft_free_stash(&stash, 1, stack_a, stack_b));
		if (bytes_read == -1)
			return (ft_free_stash(&stash, 0, stack_a, stack_b),
				free_stack(stack_a, stack_b), exit(1), NULL);
		buf[bytes_read] = '\0';
		stash = ft_copy_to_stash(stash, buf, stack_a, stack_b);
		if (ft_have_nl(stash))
		{
			line = ft_extract_line(stash);
			if (!line)
				return (ft_free_stash(&stash, 0, stack_a, stack_b),
					free_stack(stack_a, stack_b), exit(1), NULL);
			return (stash = ft_recreate_stash(stash, stack_a, stack_b), line);
		}
	}
	return (ft_free_stash(&stash, 1, stack_a, stack_b));
}

static int	checker(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		s(stack_a, 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		s(stack_b, 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		all_s(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "pa\n") == 0)
		chk_p(stack_a, stack_b, 'a');
	else if (ft_strcmp(line, "pb\n") == 0)
		chk_p(stack_a, stack_b, 'b');
	else if (ft_strcmp(line, "ra\n") == 0)
		r(stack_a, 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		r(stack_b, 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		all_r(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		rr(stack_a, 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rr(stack_b, 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		all_rr(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}

static int	checker_is_sorted(t_container *container)
{
	int	i;

	i = 1;
	if (!container)
		return (0);
	while (container)
	{
		if (container->index != i)
			return (0);
		container = container->next;
		i++;
	}
	return (1);
}

static void	checker_read(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0, stack_a, stack_b, 1);
	while (line)
	{
		if (checker(stack_a, stack_b, line) == 0)
		{
			free(line);
			ft_putendl_fd("Error", 2);
			return ;
		}
		free(line);
		line = get_next_line(0, stack_a, stack_b, 1);
	}
	if (checker_is_sorted((*stack_a)->container) && (*stack_b)->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		res;

	res = is_check(ac, (av + 1), 0);
	if (res == 0)
		return (0);
	else if (res == 2)
		return (1);
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_b || !stack_a)
		return (free_stack(&stack_a, &stack_b), 2);
	stack_b->r_count = 0;
	stack_b->size = 0;
	stack_b->container = NULL;
	if (stack_operations(ac, av, &stack_a) == 0)
		return (free_stack(&stack_a, &stack_b), 2);
	container_index(&stack_a);
	checker_read(&stack_a, &stack_b);
	free_stack(&stack_a, &stack_b);
}
