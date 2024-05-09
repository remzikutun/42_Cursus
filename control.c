/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:53:27 by rkutun            #+#    #+#             */
/*   Updated: 2024/02/01 12:05:43 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	is_integer_max_min(char **av)
{
	long int	tmp;
	int			i;

	i = 0;
	while (av[i])
	{
		tmp = ft_atoi(av[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	is_shorting(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i - 1]) > ft_atoi(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_repeat_digit(int ac, char **av)
{
	int	j;
	int	i;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_digit(char **av)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (av[i])
	{
		j = 0;
		count = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		if (av[i][j] == '\0')
			return (1);
		while (av[i][j] == '0' && av[i][j + 1] == '0')
			j++;
		while (av[i][j] && ++count)
			if (av[i][j] < '0' || av[i][j++] > '9')
				return (1);
		if (count > 11)
			return (1);
		i++;
	}
	return (0);
}

int	is_check(int ac, char **av, int flag)
{
	char	**tmp;
	int		count;

	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		tmp = ft_split(av[0], ' ');
		count = ft_argumancounter(av[0], ' ');
		if (is_digit(tmp) || is_repeat_digit(count, tmp)
			|| is_integer_max_min(tmp))
			return (ft_free(tmp), ft_putstr_fd("Error\n", 2), 2);
		else if (count == 1)
			return (ft_free(tmp), 0);
		else if (flag == 1 && is_shorting(tmp))
			return (ft_free(tmp), 0);
		ft_free(tmp);
		return (1);
	}
	if (is_digit(av) || is_repeat_digit(ac - 1, av)
		|| is_integer_max_min(av))
		return (ft_putstr_fd("Error\n", 2), 2);
	else if (flag == 1 && is_shorting(av))
		return (0);
	return (1);
}
